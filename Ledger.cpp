#include "Code/TGL/TGL.h"



int main()
{
    StartTGL();



    TGL::tglWindow
        window("Ledger");



    window.planned.style = WS_BORDER;
    window.SetToWorkRect();

    window.Create();
    window.Show();



    TGL::Message("End of Program", "Close dialog box to end the program.");



    EndTGL();



    return 0;
}
