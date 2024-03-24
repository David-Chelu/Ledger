#include "Code/TGL/TGL.h"
#include "Code/File.h"
#include "Code/Currency.h"



int main()
{
    TGL::Message("Dollar", Ledger::Currency{"dollar", "$", 0.2, false, Ledger::Currency::Position::Begin}.Transform(100));
    TGL::Message("Dollar", Ledger::Currency{"dollar", "$", 0.2, true , Ledger::Currency::Position::Begin}.Transform(100));
    TGL::Message("Dollar", Ledger::Currency{"dollar", "$", 0.2, false, Ledger::Currency::Position::End  }.Transform(100));
    TGL::Message("Dollar", Ledger::Currency{"dollar", "$", 0.2, true , Ledger::Currency::Position::End  }.Transform(100));

return 0;

    Ledger::File
        file;



//    Ledger::File{{{"Total", 500, "Car"},
//                  {"2024.01.10", -200, "Tires"},
//                  {"2024.02.10", 100, "Monthly Installment"}}}.WriteEntriesDirectly();

//    file.WriteEntriesDirectly({{"A", 1, "a"},
//                              {"B", 2, "b"},
//                              {"C", 3, "c"}});
    file.ReadEntriesDirectly();

    file.DisplayEntries();



    TGL::Message("", file.current.GetValues());

    return 0;



    StartTGL();



    LOGBRUSH
        logBrush{BS_SOLID
                ,RGB(0, 255, 0)
                ,{}};

    bool
        update = true;

    HBRUSH
        brush = (HBRUSH)GetStockObject(BLACK_BRUSH);

    HGDIOBJ
        pen = ExtCreatePen(PS_GEOMETRIC
                         | PS_INSIDEFRAME
                         | PS_ENDCAP_ROUND
                         | PS_JOIN_MITER
                          ,5
                          ,&logBrush
                          ,0
                          ,NULL);

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

    table = window;



    table.Lock();

    LoopStart
    {
        if (update)
        {
            BeginPaint(window.RequestHWND(), &paint);

            SelectObject(table.RequestHDC(), brush);
            SelectObject(table.RequestHDC(), pen);

            Rectangle(table.RequestHDC(),
                      0,
                      0,
                      window.xClient(),
                      window.yClient());

            EndPaint(window.RequestHWND(), &paint);

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
