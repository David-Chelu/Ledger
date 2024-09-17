#include "Ledger.h"



int main()
{
    if (!Ledger::ReadFontSize(Ledger::xFont,
                              Ledger::yFont))
    {
        std::cout << "\nCannot open file \"" + Ledger::attributesDirectory + "\".";
        
        std::cin.get();

        return 0;
    }

    Ledger::xPadding = Ledger::xFont / 4;
    Ledger::yPadding = Ledger::yFont / 8;



    StartTGL();



    const COLORREF
        background{TGL::Pixel(255, 255, 127)};

    bool
        update = true,
        current[256]{0},
        previous[256];

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

    Ledger::Scroller
        scroller;
    
    Ledger::Information
        information{file.entries};
    
    POINT
        mouse;



    window.planned.style = WS_BORDER;
    window.planned.callback = LedgerCallback;
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
    
    table = scroller;
    table = file;
    table = window;
    scroller.start = 0;
    scroller.interval = window.current.height / table.ComputeHeight(1) - 2;
    scroller.linesPerScroll = 1;
    scroller = information;



    video.Lock();

    table.Split(typewriter, std::bind(Ledger::Display,
                                      std::ref(video),
                                      std::ref(table)));

    LoopStart
    {
        CopyMemory(previous, current, 256);
        ReadInput(current);
        GetCursorPos(&mouse);
        ScreenToClient(window.RequestHWND(), &mouse);

        if (update)
        {
            Ledger::Display(video, table);

            update = false;
        }

        if (Ledger::scrollDown)
        {
            update = scroller.UpdateDown();

            Ledger::scrollDown = false;
        }

        if (Ledger::scrollUp)
        {
            update = scroller.UpdateUp();

            Ledger::scrollUp = false;
        }

        if (!previous[VK_LBUTTON] && current[VK_LBUTTON])
        {
            if (!table.scrollbar.Grab(&mouse))
            {
                if (table.scrollbar.Inside(&mouse) && table.scrollbar.ChangedProximity(&mouse))
                {
                    update = table.scrollbar.Update();
                }
            }
        }

        if (previous[VK_LBUTTON] && !current[VK_LBUTTON])
        {
            table.scrollbar.Release();
        }

        if (table.scrollbar.grabbed && Ledger::mouseMoved &&
            previous[VK_LBUTTON] && current[VK_LBUTTON])
        {
            if (table.scrollbar.ChangedProximity(&mouse))
            {
                update = table.scrollbar.Update();
            }
        }

        // TODO: add case where you click in an empty area and snap to it

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
