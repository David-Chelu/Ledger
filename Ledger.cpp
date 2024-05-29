#include "Code/TGL/TGL.h"
#include "Code/File.h"
#include "Code/Currency.h"
#include "Code/Section.h"



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

    // table.Display();

    TGL::tglBitmap
        testLetterBitmap;

    if (!Ledger::ReadFontSize(testLetterBitmap.planned.width,
                              testLetterBitmap.planned.height))
    {
        std::cout << "\nCannot open file \"" + Ledger::fontSizeDirectory + "\".";
    }
    
    testLetterBitmap.Allocate();
    testLetterBitmap.Fill(0);

    table = testLetterBitmap;

    testLetterBitmap.xPosition = testLetterBitmap.planned.width;
    testLetterBitmap.yPosition = testLetterBitmap.planned.width;

    for (char character = '0'; character <= '9'; ++character)
    {
        testLetterBitmap.Fill(0);
        Ledger::GenerateLetter[character](testLetterBitmap);
        testLetterBitmap.xPosition += (testLetterBitmap.current.width * 2);
        
        table.Display();
    }

    testLetterBitmap.xPosition  = testLetterBitmap.planned.width;
    testLetterBitmap.yPosition += (3 * testLetterBitmap.current.height / 2);

    for (char character = 'A'; character <= 'Z'; ++character)
    {
        testLetterBitmap.Fill(0);
        Ledger::GenerateLetter[character](testLetterBitmap);
        testLetterBitmap.xPosition += (testLetterBitmap.current.width * 2);
        
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
