#ifndef LEDGER_TYPEWRITER_H
    #define LEDGER_TYPEWRITER_H



#include <ctype.h>



namespace Ledger
{
    class Section;
    class Typewriter;
}



class Ledger::Typewriter
{
public:

    Typewriter();



    largeuint_t
        Print(Ledger::Section &section) const;



    largeuint_t
        &xFont,
        &yFont,
        &xPadding,
        &yPadding;

private:

    largeuint_t
        xFont_,
        yFont_,
        xPadding_,
        yPadding_;
};



Ledger::Typewriter::Typewriter() : xFont   (xFont_   )
                                   , yFont   (yFont_   )
                                   , xPadding(xPadding_)
                                   , yPadding(yPadding_)
{
    xFont_ = 16;
    yFont_ = 32;

    xPadding_ = xFont_ / 8;
    yPadding_ = yFont_ / 8;
}



largeuint_t Ledger::Typewriter::Print(Ledger::Section &section) const
{
    // TODO: improve this function's code

    const largeuint_t
        drawHeight{yFont_ + (yPadding_ << 1)};

    if (drawHeight > section.bitmap.current.height - (section.planned.yBorder << 1))
    {
        return -1; // TODO: drawHeight initialization will be changed to adapt directly (check if border's too big even for 0 characters, and then uses min between the height and remainder space (after section height - 2 * yBorder))
    }

    largeuint_t
        printed = 0,
        length;
    
    const std::string
        &text{section.planned.text};

    for (length = 0; length < text.length(); ++length)
    {
        if ('\n' == text[length])
        {
            break;
        }
    }

    if (section.planned.xBorder << 1 > section.bitmap.current.width)
    {
        return -1;
    }

    const largeuint_t
        xFreeSpace = section.bitmap.current.width - (section.planned.xBorder << 1);

    if (xFreeSpace >= xPadding_)
    {
        length = TGL::Min(length, (xFreeSpace - xPadding_) / (xFont_ + xPadding_));
    }

    largeuint_t
        xStartCell = 0,
        xCell,
        xStartDraw,
        yStartDraw;

    // TODO: use xStartCell to remove leading spaces (index starts at the first non whitespace)
    // TODO: use length to remove trailing spaces (decrement until non whitespace)

    // wipe with background color
    section.Fill();

    // add border with foreground color
    section.DrawBorder();

    xStartDraw = (section.bitmap.current.width - length * xFont_ - (length + 1) * xPadding_) / 2;
    yStartDraw = (section.bitmap.current.height - drawHeight) / 2;

    // draw with foreground color
    for (xCell = 0; xCell < length; ++xCell)
    {
        if (Ledger::IsMapped(text[xStartCell + xCell]))
        {
            Ledger::GenerateSymbol[text[xStartCell + xCell]](section.bitmap/*, 2 coordinates for start, 2 sizes for font*/
                                                            ,xStartDraw + xPadding_ + xCell * (xPadding_ + xFont_)
                                                            ,yStartDraw
                                                            ,xFont_
                                                            ,yFont_
                                                            ,section.planned.foreground);
        }
    }
    
    return printed;
}



largeuint_t Ledger::Section::GenerateBitmap(Ledger::Typewriter &typewriter)
{
    static largeuint_t
        typed;

    typed = typewriter.Print(*this);

    if (typed && -1 != typed)
    {
        current_.background = planned.background;
        current_.foreground = planned.foreground;

        current_.xBorder = planned.xBorder;
        current_.yBorder = planned.yBorder;

        current_.text = planned.text;
    }

    return typed;
}



#endif // LEDGER_TYPEWRITER_H
