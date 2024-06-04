#include "Code/TGL/TGL.h"
#include "Code/File.h"
#include "Code/Currency.h"
#include "Code/Section.h"
#include "Code/Typewriter.h"
#include "Code/Table.h"

#include <algorithm>



int main()
{
    if (!Ledger::ReadFontSize(Ledger::xFont,
                              Ledger::yFont))
    {
        std::cout << "\nCannot open file \"" + Ledger::attributesDirectory + "\".";
        
        std::cin.get();

        return 0;
    }

    Ledger::xPadding = Ledger::xFont / 8;
    Ledger::yPadding = Ledger::yFont / 8;



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
        video;

    Ledger::File
        file;

    Ledger::Table
        table;

    Ledger::Typewriter
        typewriter;



    window.planned.style = WS_BORDER;
    window.SetToWorkRect();

    window.Create();
    window.Show();



    video.SetMode(TGL::VideoMode::Bitmap);
    video = window;



    typewriter.xFont = Ledger::xFont;
    typewriter.yFont = Ledger::yFont;

    typewriter.xPadding = Ledger::xPadding;
    typewriter.yPadding = Ledger::yPadding;



    file.ReadEntriesDirectly();
    
    table = file;
    table = window;

    table.Split(typewriter);



    video.Lock();

    Display(video, table);

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

    video.Unlock();



    EndTGL();



    return 0;
}
