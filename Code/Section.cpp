#ifndef LEDGER_SECTION_CPP
    #define LEDGER_SECTION_CPP



#include "SectionAttributes.cpp"



Ledger::Section::Section() : current  {current_  }
                           , planned  {planned_  }
                           , bitmap   {bitmap_   }
{
}

Ledger::Section::Section(const Ledger::SectionAttributes &attributes,
                         largeuint_t newXPosition,
                         largeuint_t newYPosition)
                         :
                         Section()
{
    planned_ = attributes;

    bitmap.xPosition = newXPosition;
    bitmap.yPosition = newYPosition;
}



Ledger::Section &Ledger::Section::operator =(const Ledger::Section &section)
{
    planned_ = section.planned_;

    bitmap.xPosition = section.bitmap.xPosition;
    bitmap.yPosition = section.bitmap.yPosition;

    return *this;
}



bool Ledger::Section::Allocate(largeuint_t width, largeuint_t height)
{
    bitmap_.planned.width  = width;
    bitmap_.planned.height = height;
    
    if (bitmap_.Allocate())
    {
        current_ = planned_;

        return true;
    }
    
    return false;
}

bool Ledger::Section::Allocate()
{
    if (bitmap_.Allocate())
    {
        current_ = planned_;

        return true;
    }

    return false;
}

void Ledger::Section::Fill()
{
    bitmap_.Fill(planned_.background);
}

void Ledger::Section::DrawBorder()
{
    const largeuint_t
        left  = 0
       ,right = bitmap_.current.width
       ,top   = 0
       ,bot   = bitmap_.current.height
       ,&xBorder = planned_.xBorder
       ,&yBorder = planned_.yBorder
       ;

    std::vector<Ledger::Line>
        interval
        {
            {{left, top}, {right, top + yBorder}}
           ,{{left, bot - yBorder}, {right, bot}}
           ,{{left, top + yBorder}, {left + xBorder, bot - yBorder}}
           ,{{right - xBorder, top + yBorder}, {right, bot - yBorder}}
        };

    largeuint_t
        xPixel, xStart, xStop,
        yPixel, yStart, yStop;



    for (auto &diagonal : interval)
    {
        xStart = TGL::Min(diagonal.point1.x, diagonal.point2.x);
        xStop  = TGL::Max(diagonal.point1.x, diagonal.point2.x);
        yStart = TGL::Min(diagonal.point1.y, diagonal.point2.y);
        yStop  = TGL::Max(diagonal.point1.y, diagonal.point2.y);

        for (yPixel = yStart; yPixel < yStop; ++yPixel)
        {
            bitmap_(yPixel);

            for (xPixel = xStart; xPixel < xStop; ++xPixel)
            {
                bitmap_[xPixel] = planned_.foreground;
            }
        }
    }
}

void Ledger::Section::DisplayValues() const
{
    std::cout << GetValues() + "\n\n\n\n";
}

std::string Ledger::Section::GetValues() const
{
    std::string
        text;

    text = std::string("Section:")
         + "\nCurrent "   + current_.GetValues()
         + "\n\nPlanned " + planned_.GetValues()
         + "\nImage: " + (bitmap_.image? "Yes; " + TGL::StringHex(largeuint_t(bitmap_.image)) : "No")
         ;

    return text;
}



#endif // LEDGER_SECTION_CPP
