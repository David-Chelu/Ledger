#ifndef LEDGER_SECTION_H
    #define LEDGER_SECTION_H



namespace Ledger
{
    struct SectionAttributes;
    class Section;
    class Typewriter;
}



#include "SectionAttributes.h"
#include "Letters.h"



class Ledger::Section
{
public:

    Section();



    bool
        Allocate(largeuint_t width, largeuint_t height),
        Allocate();

    void
        Fill(),
        DrawBorder();

    largeuint_t
        GenerateBitmap(Ledger::Typewriter &typewriter);



    const Ledger::SectionAttributes
        &current;

    Ledger::SectionAttributes
        &planned;

    TGL::tglBitmap
        &image;

private:

    Ledger::SectionAttributes
        current_,
        planned_;

    TGL::tglBitmap
        image_;
};



Ledger::Section::Section() : current {current_}
                           , planned {planned_}
                           , image   {image_  }
{
}



bool Ledger::Section::Allocate(largeuint_t width, largeuint_t height)
{
    image_.planned.width  = width;
    image_.planned.height = height;

    return image_.Allocate();
}

bool Ledger::Section::Allocate()
{
    return image_.Allocate();
}

void Ledger::Section::Fill()
{
    image_.Fill(planned_.background);
}

void Ledger::Section::DrawBorder()
{
    const largeuint_t
        left  = 0
       ,right = image_.current.width
       ,top   = 0
       ,bot   = image_.current.height
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
            image_(yPixel);

            for (xPixel = xStart; xPixel < xStop; ++xPixel)
            {
                image_[xPixel] = planned_.foreground;
            }
        }
    }
}

//sections will be black rectangles with text in them. Border is a whole draw on first frame, unicolor



#endif // LEDGER_SECTION_H
