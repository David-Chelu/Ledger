#ifndef LEDGER_SECTION_LETTERS_H
    #define LEDGER_SECTION_LETTERS_H



#define BIND_LETTER(x) {x, InBitmapDraw_##x}



namespace Ledger
{
    struct Vertex { largeuint_t x, y; };
    struct Line { Vertex point1, point2; };

    COLORREF
        foreground = TGL::Pixel(0, 255, 0);
}



#include "PlaceVertexPairs.h"
#include "InBitmapDraw.h"



namespace Ledger
{
    std::map<char, void (*)(TGL::tglBitmap&)>
        GenerateLetter = 
    {
        BIND_LETTER(48)
       ,BIND_LETTER(49)
       ,BIND_LETTER(50)
       ,BIND_LETTER(50)
       ,BIND_LETTER(51)
       ,BIND_LETTER(52)
       ,BIND_LETTER(53)
       ,BIND_LETTER(54)
       ,BIND_LETTER(55)
       ,BIND_LETTER(56)
       ,BIND_LETTER(57)

       ,BIND_LETTER(65)
       ,BIND_LETTER(66)
       ,BIND_LETTER(67)
       ,BIND_LETTER(68)
       ,BIND_LETTER(69)
       ,BIND_LETTER(70)
       ,BIND_LETTER(71)
       ,BIND_LETTER(72)
       ,BIND_LETTER(73)
       ,BIND_LETTER(74)
       ,BIND_LETTER(75)
       ,BIND_LETTER(76)
       ,BIND_LETTER(77)
       ,BIND_LETTER(78)
       ,BIND_LETTER(79)
       ,BIND_LETTER(80)
       ,BIND_LETTER(81)
       ,BIND_LETTER(82)
       ,BIND_LETTER(83)
       ,BIND_LETTER(84)
       ,BIND_LETTER(85)
       ,BIND_LETTER(86)
       ,BIND_LETTER(87)
       ,BIND_LETTER(88)
       ,BIND_LETTER(89)
       ,BIND_LETTER(90)
    };
}



#endif // LEDGER_SECTION_LETTERS_H
