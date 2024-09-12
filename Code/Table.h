#ifndef LEDGER_TABLE_H
    #define LEDGER_TABLE_H



#include <functional>



#define DEFAULT_DATE(offset)        Ledger::SectionAttributes(bkg[line % 2], frg[line % 2], Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(            file->entries[static_cast<largeint_t>(line) + offset].date       ))
#define DEFAULT_DESCRIPTION(offset) Ledger::SectionAttributes(bkg[line % 2], frg[line % 2], Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(            file->entries[static_cast<largeint_t>(line) + offset].description))
#define DEFAULT_VALUE(offset)       Ledger::SectionAttributes(bkg[line % 2], frg[line % 2], Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(TGL::String(file->entries[static_cast<largeint_t>(line) + offset].value)     ))

#define COMPUTE_REMAINING() largeuint_t remaining = file_->entries[1].value; for (size_t index = 2; index < file_->entries.size(); ++index) remaining -= file_->entries[index].value; file_->entries[0].value = (remaining);1



#define DEFAULT_DATE_REMAINING        Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(           "Remaining"))
#define DEFAULT_DESCRIPTION_REMAINING Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(           ""         ))
#define DEFAULT_VALUE_REMAINING       Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(TGL::String(remaining)))

#define DEFAULT_DATE_ENTRY        Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(entry.date))
#define DEFAULT_DESCRIPTION_ENTRY Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(entry.description))
#define DEFAULT_VALUE_ENTRY       Ledger::SectionAttributes(Ledger::background, Ledger::foreground, Ledger::xBorder, Ledger::yBorder, Ledger::Uppercase(TGL::String(entry.value)))

#define ALIGN_HEIGHT(offset) (line + offset) * (singleLineHeight - yBorder_) + (yBorder_ * (line + offset > 1))



#define INITIALIZE_REMAINING_ROW()\
{\
    constexpr largeuint_t\
        line = 0;\
\
    COMPUTE_REMAINING();\
\
    sections_[0].resize(3);\
\
    sections_[0][0] = Ledger::Section(DEFAULT_DATE_REMAINING, 0, ALIGN_HEIGHT(0));\
    sections_[0][1] = Ledger::Section(DEFAULT_DESCRIPTION_REMAINING, dateWidth - xBorder_, ALIGN_HEIGHT(0));\
    sections_[0][2] = Ledger::Section(DEFAULT_VALUE_REMAINING, width_ - valueWidth - xBorder_, ALIGN_HEIGHT(0));\
\
    sections_[0][0].bitmap.planned.width = dateWidth;\
    sections_[0][1].bitmap.planned.width = descriptionWidth;\
    sections_[0][2].bitmap.planned.width = valueWidth;\
\
    for (largeuint_t parse = 0; parse < sections_[line].size(); ++parse)\
    {\
        sections_[0][parse].bitmap.planned.height = singleLineHeight;\
\
        sections_[0][parse].Allocate();\
        sections_[0][parse].GenerateBitmap(typewriter);\
    }\
}1



#include "Scroller.h"



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
        &operator =(const Ledger::File &file),
        &operator =(Ledger::Scroller &scroller);

    std::vector<Ledger::Section>
        &operator [](largeuint_t index);
    
    const std::vector<Ledger::Section>
        &operator [](largeuint_t index) const;

    

    void
        Split(Ledger::Typewriter &typewriter, std::function<void()> callable = NULL);

    largeuint_t
        ComputeWidth(uint8_t lengthAssumed) const,
        ComputeHeight(uint8_t lengthAssumed) const;



    std::vector<std::vector<Ledger::Section>>
        &sections;

    largeuint_t
        &width,
        &height,
        &xBorder,
        &yBorder;

    const Ledger::File
        *&file;

    Ledger::Scroller
        *&scroller;

private:



    std::vector<std::vector<Ledger::Section>>
        sections_;

    largeuint_t
        width_,
        height_,
        xBorder_,
        yBorder_;

    const Ledger::File
        *file_;

    Ledger::Scroller
        *scroller_;
};



Ledger::Table::Table()
            :
            sections {sections_},
            width    {width_   },
            height   {height_  },
            xBorder  {xBorder_ },
            yBorder  {yBorder_ },
            file     {file_    },
            scroller {scroller_},
            file_    {NULL     }
{
    width_  =
    height_ = 0;

    xBorder_ =
    yBorder_ = 8;

    scroller_ = NULL;
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

Ledger::Table &Ledger::Table::operator =(Ledger::Scroller &scroller)
{
    scroller_ = &scroller;

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



void Ledger::Table::Split(Ledger::Typewriter &typewriter, std::function<void()> callable)
{
    largeuint_t
        dateWidth = ComputeWidth(std::string("2024.06.02").length()),
        valueWidth = ComputeWidth(std::string("$1000000").length()),
        descriptionWidth = width_ - dateWidth - valueWidth + xBorder_,
        singleLineHeight = ComputeHeight(1),
        lineCount;
    


    sections_.resize(file->entries.size());
    lineCount = sections_.size();

    COMPUTE_REMAINING();

    // INITIALIZE_REMAINING_ROW();

    for (largeuint_t line = 0; line < lineCount; ++line)
    {
        sections_[line].resize(3);

        static COLORREF
            bkg[2],
            frg[2];

        if (line >= 2)
        {
            bkg[0] = TGL::Pixel(96, 96, 96);
            bkg[1] = Ledger::background;
            
            frg[0] = TGL::Pixel(0, 224, 0);
            frg[1] = Ledger::foreground;
        }
        else
        {
            bkg[0] = TGL::Pixel(32, 32, 32);
            bkg[1] = TGL::Pixel( 0,  0,  0);
            
            frg[0] = TGL::Pixel(160, 0, 224);
            frg[1] = TGL::Pixel(128, 0, 192);
        }

        sections_[line][0] = Ledger::Section(DEFAULT_DATE       (0),                              0, ALIGN_HEIGHT(0));
        sections_[line][1] = Ledger::Section(DEFAULT_DESCRIPTION(0),           dateWidth - xBorder_, ALIGN_HEIGHT(0));
        sections_[line][2] = Ledger::Section(DEFAULT_VALUE      (0), width_ - valueWidth - xBorder_, ALIGN_HEIGHT(0));
    }

    for (largeuint_t line = 0; line < lineCount; ++line)
    {
        sections_[line][0].bitmap.planned.width = dateWidth;
        sections_[line][1].bitmap.planned.width = descriptionWidth;
        sections_[line][2].bitmap.planned.width = valueWidth;

        for (largeuint_t parse = 0; parse < sections_[line].size(); ++parse)
        {
            sections_[line][parse].bitmap.planned.height = singleLineHeight;

            sections_[line][parse].Allocate();
            sections_[line][parse].GenerateBitmap(typewriter);
        }
    }

    const auto
        backup = scroller_->interval;

    scroller_->interval = 0;
    callable();
    scroller_->interval = backup;

    scroller_->information->data.erase(scroller_->information->data.begin(),
                                       scroller_->information->data.begin() + 2);
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
    largeuint_t
        start,
        stop,
        parse,
        singleLineHeight = table.ComputeHeight(1),
        line = 0,
        offset;
    
    const auto
        yBorder_{table.yBorder};

    video.SetMode(TGL::VideoMode::Bitmap);

    if (table.scroller && table.scroller->interval > 0)
    {
        offset = 2;

        start = offset + table.scroller->start;
        stop = start + table.scroller->interval;
    }
    else
    {
        offset = 0;

        start = offset;
        stop = (table.scroller? 2 : 0);
    }

    for (parse = start; parse < stop; ++parse)
    {
        for (auto &section : table.sections[parse])
        {
            section.bitmap.yPosition = ALIGN_HEIGHT(offset + parse - start);

            video = section.bitmap;

            video.Display();
        }
    }

    // video = table.sections[0][0].bitmap;
    // video.Display();
}



#endif // LEDGER_TABLE_H