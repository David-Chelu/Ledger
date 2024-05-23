#include "Code/TGL/TGL.h"
#include "Code/File.h"
#include "Code/Currency.h"
#include "Code/Section.h"



int main()
{
    Ledger::SectionAttributes().DisplayValues();

    MessageBox(NULL, "Diflüber", "Ich", 0);

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
    table = blankCanvas;



    table.Lock();

    table.Display();

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
