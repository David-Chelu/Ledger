#ifndef LEDGER_TABLE_H
    #define LEDGER_TABLE_H



#define DEFAULT_DATE        Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(file->entries[section].date))
#define DEFAULT_DESCRIPTION Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(file->entries[section].description))
#define DEFAULT_VALUE       Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(TGL::String(file->entries[section].value)))

#define DEFAULT_DATE_ENTRY        Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(entry.date))
#define DEFAULT_DESCRIPTION_ENTRY Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(entry.description))
#define DEFAULT_VALUE_ENTRY       Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(TGL::String(entry.value)))

#define ALIGN_HEIGHT section * (singleLineHeight - yBorder_)



namespace Ledger
{
    class Table;

    void
        Display(TGL::tglVideo &video, Ledger::Table &table);
    
    std::string
        Uppercase(std::string s);

    largeuint_t
        xFont,
        yFont,
        xPadding,
        yPadding,
        xBorder = 8,
        yBorder = 8;

    COLORREF
        foreground = TGL::Pixel(0, 192, 0),
        background = TGL::Pixel(0, 0, 0);
}



std::string Ledger::Uppercase(std::string s)
{
    for (char &c : s)
    {
        if ('a' <= c && c <= 'z')
        {
            c -= 32;
        }
    }

    return s;
}



class Ledger::Table
{
public:

    Table();



    Ledger::Table
        &operator =(const TGL::tglWindow &window),
        &operator =(const Ledger::File &file);

    std::vector<Ledger::Section>
        &operator [](largeuint_t index);
    
    const std::vector<Ledger::Section>
        &operator [](largeuint_t index) const;

    

    void
        Split(Ledger::Typewriter &typewriter);



    std::vector<std::vector<Ledger::Section>>
        &sections;

    largeuint_t
        &width,
        &height,
        &xBorder,
        &yBorder;

    const Ledger::File
        *&file;

private:

    largeuint_t
        ComputeWidth(uint8_t lengthAssumed) const,
        ComputeHeight(uint8_t lengthAssumed) const;



    std::vector<std::vector<Ledger::Section>>
        sections_;

    largeuint_t
        width_,
        height_,
        xBorder_,
        yBorder_;

    const Ledger::File
        *file_;
};



Ledger::Table::Table()
            :
            sections{sections_},
            width   {width_   },
            height  {height_  },
            xBorder {xBorder_ },
            yBorder {yBorder_ },
            file    {file_    }
{
    width_  =
    height_ = 0;

    xBorder_ =
    yBorder_ = 8;
}



Ledger::Table &Ledger::Table::operator =(const TGL::tglWindow &window)
{
    width_  = window.current.width;
    height_ = window.current.height;

    return *this;
}

Ledger::Table &Ledger::Table::operator =(const Ledger::File &file)
{
    file_ = &file;

    return *this;
}

std::vector<Ledger::Section> &Ledger::Table::operator [](largeuint_t index)
{
    return sections_[index];
}

const std::vector<Ledger::Section> &Ledger::Table::operator [](largeuint_t index) const
{
    return sections_[index];
}



void Ledger::Table::Split(Ledger::Typewriter &typewriter)
{
    largeuint_t
        dateWidth = ComputeWidth(std::string("2024.06.02").length()),
        descriptionWidth,
        valueWidth = ComputeWidth(std::string("$1000000").length()),
        singleLineHeight = ComputeHeight(1);

    descriptionWidth = width_ - dateWidth - valueWidth + xBorder_;

    sections_.resize(file->entries.size());

    for (largeuint_t section = 0; section < sections_.size(); ++section)
    {
        sections_[section].resize(3);

        sections_[section][0] = Ledger::Section(DEFAULT_DATE, 0, ALIGN_HEIGHT);
        sections_[section][1] = Ledger::Section(DEFAULT_DESCRIPTION, dateWidth - xBorder_, ALIGN_HEIGHT);
        sections_[section][2] = Ledger::Section(DEFAULT_VALUE, width_ - valueWidth - xBorder_, ALIGN_HEIGHT);
    }

    for (largeuint_t section = 0; section < sections_.size(); ++section)
    {
        sections_[section][0].bitmap.planned.width = dateWidth;
        sections_[section][1].bitmap.planned.width = descriptionWidth;
        sections_[section][2].bitmap.planned.width = valueWidth;

        for (largeuint_t parse = 0; parse < sections_[section].size(); ++parse)
        {
            sections_[section][parse].bitmap.planned.height = singleLineHeight;

            sections_[section][parse].Allocate();
            sections_[section][parse].GenerateBitmap(typewriter);
        }
    }
}



largeuint_t Ledger::Table::ComputeWidth(uint8_t lengthAssumed) const
{
    largeuint_t
        length = lengthAssumed + 2;

    return length * Ledger::xFont + (length + 1) * Ledger::xPadding + (xBorder_ << 1);
}

largeuint_t Ledger::Table::ComputeHeight(uint8_t lengthAssumed) const
{
    largeuint_t
        length = lengthAssumed + 1;

    return length * Ledger::yFont + (length + 1) * Ledger::yPadding + 2 * yBorder_;
}



void Ledger::Display(TGL::tglVideo &video, Ledger::Table &table)
{
    video.SetMode(TGL::VideoMode::Bitmap);
    
    // for (auto &line : table.sections)
    // {
    //     for (auto &section : line)
    //     {
    //         video = section.bitmap;
    
    //         video.Display();
    //     }
    // }
    video = table.sections[0][0].bitmap;

    video.Display();
}



#endif // LEDGER_TABLE_H