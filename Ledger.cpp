#include "Code/TGL/TGL.h"
#include "Code/File.h"
#include "Code/Currency.h"
#include "Code/Section.h"
#include "Code/Typewriter.h"

#include <algorithm>



namespace Ledger
{
    const COLORREF
        foreground = TGL::Pixel(0, 192, 0),
        background = TGL::Pixel(0, 0, 0);
}



void ToUppercase(std::string &s)
{
    for (char &c : s)
    {
        if ('a' <= c && c <= 'z')
        {
            c -= 32;
        }
    }
}



int main()
{
    // MessageBox(NULL, "Diflüber", "Ich", 0);

    StartTGL();



    const COLORREF
        background{TGL::Pixel(255, 255, 127)};

    bool
        update = true;

    PAINTSTRUCT
        paint;

    TGL::tglWindow
        window("Ledger");

    TGL::tglVideo
        table;



    window.planned.style = WS_BORDER;
    window.SetToWorkRect();

    window.Create();
    window.Show();



    const ColorWithSize_t
        canvasData{background, window.current.width, window.current.height};

    TGL::tglBitmap
        blankCanvas{canvasData};



    table.SetMode(TGL::VideoMode::Bitmap);
    table = window;
    // table = blankCanvas;



    table.Lock();

    Ledger::Section
        section;

    Ledger::Typewriter
        typewriter;

    if (!Ledger::ReadFontSize(typewriter.xFont,
                              typewriter.yFont))
    {
        std::cout << "\nCannot open file \"" + Ledger::fontSizeDirectory + "\".";
    }
    else
    {
        typewriter.xPadding = typewriter.xFont / 8;
        typewriter.yPadding = typewriter.yFont / 8;
    
        section.planned.xBorder =
        section.planned.yBorder = 8;

        section.planned.foreground = Ledger::foreground;
        section.planned.background = Ledger::background;

        section.image.planned.width  = 320;
        section.image.planned.height = 160;

        ToUppercase(section.planned.text);

        section.Allocate();
        section.GenerateBitmap(typewriter);

        table = section.image;

        table.Display();
    }

    LoopStart
    {
        if (update)
        {
            update = false;
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }

        Sleep(1);
    }
    LoopEnd

    table.Unlock();



    EndTGL();



    return 0;
}
