#ifndef LEDGER_SECTION_LETTERS_IN_BITMAP_DRAW_H
    #define LEDGER_SECTION_LETTERS_IN_BITMAP_DRAW_H



#define ADD_THICKNESS()\
largeuint_t\
    thickness = TGL::Min(bitmap.current.width, bitmap.current.height) / 8

#define DRAW_LINES()\
for (std::vector<Ledger::Line>::iterator diagonal = diagonals.begin(); diagonal != diagonals.end(); ++diagonal)\
{\
    static largeuint_t\
        xStart, xStop,\
        yStart, yStop,\
        x, y;\
    \
    xStart = TGL::Min(diagonal->point1.x, diagonal->point2.x);\
    xStop  = TGL::Max(diagonal->point1.x, diagonal->point2.x);\
    yStart = TGL::Min(diagonal->point1.y, diagonal->point2.y);\
    yStop  = TGL::Max(diagonal->point1.y, diagonal->point2.y);\
    \
    {\
        for (y = yStart; y <= yStop; ++y)\
        {\
            bitmap(y);\
        \
            for (x = xStart; x <= xStop; ++x)\
            {\
                bitmap[x] = Ledger::foreground;\
            }\
        }\
    }\
}\
1



void InBitmapDraw_48(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_48();
    DRAW_LINES();
}

void InBitmapDraw_49(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_49();
    DRAW_LINES();
}

void InBitmapDraw_50(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_50();
    DRAW_LINES();
}

void InBitmapDraw_51(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_51();
    DRAW_LINES();
}

void InBitmapDraw_52(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_52();
    DRAW_LINES();
}

void InBitmapDraw_53(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_53();
    DRAW_LINES();
}

void InBitmapDraw_54(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_54();
    DRAW_LINES();
}

void InBitmapDraw_55(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_55();
    DRAW_LINES();
}

void InBitmapDraw_56(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_56();
    DRAW_LINES();
}

void InBitmapDraw_57(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_57();
    DRAW_LINES();
}



void InBitmapDraw_65(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_65();
    DRAW_LINES();
}

void InBitmapDraw_66(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_66();
    DRAW_LINES();
}

void InBitmapDraw_67(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_67();
    DRAW_LINES();
}

void InBitmapDraw_68(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_68();
    DRAW_LINES();
}

void InBitmapDraw_69(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_69();
    DRAW_LINES();
}

void InBitmapDraw_70(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_70();
    DRAW_LINES();
}

void InBitmapDraw_71(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_71();
    DRAW_LINES();
}

void InBitmapDraw_72(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_72();
    DRAW_LINES();
}

void InBitmapDraw_73(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_73();
    DRAW_LINES();
}

void InBitmapDraw_74(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_74();
    DRAW_LINES();
}

void InBitmapDraw_75(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_75();
    DRAW_LINES();
}

void InBitmapDraw_76(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_76();
    DRAW_LINES();
}

void InBitmapDraw_77(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_77();
    DRAW_LINES();
}

void InBitmapDraw_78(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_78();
    DRAW_LINES();
}

void InBitmapDraw_79(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_79();
    DRAW_LINES();
}

void InBitmapDraw_80(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_80();
    DRAW_LINES();
}

void InBitmapDraw_81(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_81();
    DRAW_LINES();
}

void InBitmapDraw_82(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_82();
    DRAW_LINES();
}

void InBitmapDraw_83(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_83();
    DRAW_LINES();
}

void InBitmapDraw_84(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_84();
    DRAW_LINES();
}

void InBitmapDraw_85(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_85();
    DRAW_LINES();
}

void InBitmapDraw_86(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_86();
    DRAW_LINES();
}

void InBitmapDraw_87(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_87();
    DRAW_LINES();
}

void InBitmapDraw_88(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_88();
    DRAW_LINES();
}

void InBitmapDraw_89(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_89();
    DRAW_LINES();
}

void InBitmapDraw_90(TGL::tglBitmap &bitmap)
{
    ADD_THICKNESS();
    PLACE_VERTEX_PAIRS_90();
    DRAW_LINES();
}



#endif // LEDGER_SECTION_LETTERS_IN_BITMAP_DRAW_H
