#include "Code/TGL/TGL.h"



namespace Ledger
{
    struct Currency;
    class File;
    struct FileAttributes;
    struct Format;
    struct Information;
    class Scrollbar;
    struct Scroller;
    class Section;
    struct SectionAttributes;
    class Table;
    class Typewriter;

    struct Vertex { largeuint_t x, y; };
    struct Line { Vertex point1, point2; };



    inline bool
        ReadFontSize(largeuint_t &width, largeuint_t &height);

    std::string
        Padded(const std::string &text, uint32_t plannedWidth, char padding),
        PrePadded(const std::string &text, uint32_t plannedWidth, char padding),
        Uppercase(std::string s);
    
    void
        Display(TGL::tglVideo &video, Ledger::Table &table);




    const std::string
        ledgerEntriesDirectory = "ledger.ldg",
        attributesDirectory = "attributes.lga",
        newline{13, 10};

    const std::vector<uint8_t>
        linePadding{0, 255, 0, 255};

    extern Ledger::Format
        error;

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

    bool
        scrollDown = false,
        scrollUp   = false,
        mouseMoved = false;
}



#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <ctype.h>



#include "Code/Currency.h"
#include "Code/File.h"
#include "Code/Format.h"
#include "Code/Information.h"
#include "Code/Scrollbar.h"
#include "Code/Scroller.h"
#include "Code/Section.h"
#include "Code/Table.h"
#include "Code/Typewriter.h"

#include "Code/PlaceVertexPairs.h"
#include "Code/InBitmapDraw.cpp"
#include "Code/Letters.cpp"

#include "Code/Currency.cpp"
#include "Code/File.cpp"
#include "Code/Format.cpp"
#include "Code/Information.cpp"
#include "Code/Scrollbar.cpp"
#include "Code/Scroller.cpp"
#include "Code/Section.cpp"
#include "Code/Table.cpp"
#include "Code/Typewriter.cpp"



#define CHECK_INPUT(variable, expression)\
if (expression)\
{\
    variable = true;\
}1



namespace Ledger
{
    Ledger::Format
        error{"", 0, "Error"};
}



LRESULT CALLBACK LedgerCallback(HWND handle
                               ,UINT message
                               ,WPARAM wParam
                               ,LPARAM lParam)
{
    short
        wheelInput = GET_WHEEL_DELTA_WPARAM(wParam);
    
    if (0 == wheelInput % 120)
    {
        CHECK_INPUT(Ledger::scrollDown, wheelInput < 0);
        CHECK_INPUT(Ledger::scrollUp,   wheelInput > 0);
    }

    Ledger::mouseMoved = false;

    switch (message)
    {
        case WM_PAINT:
        {
            TGL::callbackDC =
            BeginPaint(handle, &TGL::callbackPS);
            EndPaint(handle, &TGL::callbackPS);

            return 0;
        }
        case WM_MOUSEMOVE:
        {
            Ledger::mouseMoved = true;

            return 0;
        }
        case WM_CREATE:
        {
            return 0;
        }
        case WM_DESTROY:
        {
            return 0;
        }
    }
    return DefWindowProc(handle, message, wParam, lParam);
}



void ReadInput(bool *current)
{
    for (uint16_t index = 0; index < 256; ++index)
    {
        current[index] = !!GetAsyncKeyState(index);
    }
}



bool Ledger::ReadFontSize(largeuint_t &width, largeuint_t &height)
{
    // TODO: add reading border size, and optional padding
    // TODO: reformat in the style of json

    std::fstream
        handle;

    handle.open(Ledger::attributesDirectory.c_str(), std::ios::in);

    if (!handle.is_open())
    {
        return false;
    }
    else
    {
        handle >> width >> height;

        handle.close();
    }

    return true;
}

std::string Ledger::Padded(const std::string &text, uint32_t plannedWidth, char padding)
{
    return text + std::string(plannedWidth <= text.length()? 0 : plannedWidth - text.length(), padding);
}

std::string Ledger::PrePadded(const std::string &text, uint32_t plannedWidth, char padding)
{
    return std::string(plannedWidth <= text.length()? 0 : plannedWidth - text.length(), padding) + text;
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

        TGL::tglBitmap
            limits(ColorWithSize_t{TGL::Pixel(160, 160, 160),
                                   table.scrollbar.current.width, 
                                   table.scrollbar.current.width});

        video = limits;

        limits.xPosition = table.width - table.xBorder - limits.current.width;
        video.Display();

        limits.yPosition = table.scrollbar.yPosition + table.yBorder + table.scrollbar.current.height;
        video.Display();
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

    // add a Render function, combine all sections instead of displaying them 1 by 1
    // resize section to include the 2 rightmost empty pixels. Rather, rewrite the formula for distribution between the 3 horizontal sections

    table.scrollbar.Fill(0);
    table.scrollbar.Place(TGL::Pixel(208, 208, 160));

    video = table.scrollbar;
    video.Display();

    // video = table.sections[0][0].bitmap;
    // video.Display();
}
