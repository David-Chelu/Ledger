#ifndef LEDGER_SECTION_LETTERS_H
    #define LEDGER_SECTION_LETTERS_H



// #define BIND_SYMBOL(x) {x, InBitmapDraw_##x}
// Definition by Gabe
#define BIND_SYMBOL(x)\
{\
    x,\
    [](TGL::tglBitmap &bitmap, largeuint_t xOff, largeuint_t yOff, largeuint_t xFont, largeuint_t yFont, COLORREF foreground)\
    {\
        ADD_THICKNESS();\
        PLACE_VERTEX_PAIRS_##x();\
        DRAW_LINES();\
    }\
}



namespace Ledger
{
    struct Vertex { largeuint_t x, y; };
    struct Line { Vertex point1, point2; };
}



#include "PlaceVertexPairs.h"
#include "InBitmapDraw.h"



namespace Ledger
{
    std::map<char, void (*)(TGL::tglBitmap&, largeuint_t, largeuint_t, largeuint_t, largeuint_t, COLORREF)>
        GenerateSymbol = 
    {
        BIND_SYMBOL(45)
       ,BIND_SYMBOL(46)

       ,BIND_SYMBOL(48)
       ,BIND_SYMBOL(49)
       ,BIND_SYMBOL(50)
       ,BIND_SYMBOL(50)
       ,BIND_SYMBOL(51)
       ,BIND_SYMBOL(52)
       ,BIND_SYMBOL(53)
       ,BIND_SYMBOL(54)
       ,BIND_SYMBOL(55)
       ,BIND_SYMBOL(56)
       ,BIND_SYMBOL(57)

       ,BIND_SYMBOL(65)
       ,BIND_SYMBOL(66)
       ,BIND_SYMBOL(67)
       ,BIND_SYMBOL(68)
       ,BIND_SYMBOL(69)
       ,BIND_SYMBOL(70)
       ,BIND_SYMBOL(71)
       ,BIND_SYMBOL(72)
       ,BIND_SYMBOL(73)
       ,BIND_SYMBOL(74)
       ,BIND_SYMBOL(75)
       ,BIND_SYMBOL(76)
       ,BIND_SYMBOL(77)
       ,BIND_SYMBOL(78)
       ,BIND_SYMBOL(79)
       ,BIND_SYMBOL(80)
       ,BIND_SYMBOL(81)
       ,BIND_SYMBOL(82)
       ,BIND_SYMBOL(83)
       ,BIND_SYMBOL(84)
       ,BIND_SYMBOL(85)
       ,BIND_SYMBOL(86)
       ,BIND_SYMBOL(87)
       ,BIND_SYMBOL(88)
       ,BIND_SYMBOL(89)
       ,BIND_SYMBOL(90)
    };

    inline bool
        IsMapped(char c);
}



bool Ledger::IsMapped(char c)
{
    return Ledger::GenerateSymbol.find(c) != Ledger::GenerateSymbol.end();
}



#endif // LEDGER_SECTION_LETTERS_H
