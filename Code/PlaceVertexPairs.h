#ifndef LEDGER_SECTION_LETTERS_PLACE_VERTEX_PAIRS_H
    #define LEDGER_SECTION_LETTERS_PLACE_VERTEX_PAIRS_H



#define THICK (thickness - 1)

#define xLEFT  xOff
#define xMID   xOff + xFont / 2
#define xRIGHT xOff + xFont - 1

#define yTOP yOff
#define yMID yOff + yFont / 2
#define yBOT yOff + yFont - 1

// T stands for THICK
// B stands for Begin (offset of half THICK for mid sections)
// E stands for End (offset of half THICK for mid sections)
#define xLEFT_T  xLEFT  + THICK
#define xMID_TB  xMID   - THICK / 2
#define xMID_TE  xMID   + THICK / 2
#define xRIGHT_T xRIGHT - THICK

#define yTOP_T  yTOP + THICK
#define yMID_TB yMID - THICK / 2
#define yMID_TE yMID + THICK / 2
#define yBOT_T  yBOT - THICK



#define LEFT_TOP  {xLEFT,  yTOP}
#define LEFT_MID  {xLEFT,  yMID}
#define LEFT_BOT  {xLEFT,  yBOT}
#define MID_TOP   {xMID,   yTOP}
#define CENTER    {xMID,   yMID}
#define MID_BOT   {xMID,   yBOT}
#define RIGHT_TOP {xRIGHT, yTOP}
#define RIGHT_MID {xRIGHT, yMID}
#define RIGHT_BOT {xRIGHT, yBOT}



#define LINE_TOP                {LEFT_TOP,  {xRIGHT  , yTOP_T}}
#define LINE_BOT                {LEFT_BOT,  {xRIGHT  , yBOT_T}}
#define LINE_LEFT               {LEFT_TOP,  {xLEFT_T , yBOT  }}
#define LINE_RIGHT              {RIGHT_TOP, {xRIGHT_T, yBOT  }}
#define LINE_VERTICAL           {{xMID_TB, yTOP }, {xMID_TE + !(thickness % 2), yBOT  }}
#define LINE_HORIZONTAL         {{xLEFT, yMID_TB}, {xRIGHT, yMID_TE + !(thickness % 2)}}
#define LINE_DIAGONAL_PRIMARY   {LEFT_TOP , RIGHT_BOT}
#define LINE_DIAGONAL_SECONDARY {RIGHT_TOP, LEFT_BOT }

#define LINE_TOP_LEFT               {LEFT_TOP , {xMID_TE , yTOP_T }}
#define LINE_TOP_RIGHT              {RIGHT_TOP, {xMID_TB , yTOP_T }}
#define LINE_BOT_LEFT               {LEFT_BOT , {xMID_TE , yBOT_T }}
#define LINE_BOT_RIGHT              {RIGHT_BOT, {xMID_TB , yBOT_T }}
#define LINE_LEFT_TOP               {LEFT_TOP , {xLEFT_T , yMID_TE}}
#define LINE_LEFT_BOT               {LEFT_BOT , {xLEFT_T , yMID_TB}}
#define LINE_RIGHT_TOP              {RIGHT_TOP, {xRIGHT_T, yMID_TE}}
#define LINE_RIGHT_BOT              {RIGHT_BOT, {xRIGHT_T, yMID_TB}}
#define LINE_VERTICAL_TOP           {{xMID_TB, yTOP   }, {xMID_TE + !(thickness % 2), yMID_TE}}
#define LINE_VERTICAL_BOT           {{xMID_TB, yMID_TB}, {xMID_TE + !(thickness % 2), yBOT   }}
#define LINE_HORIZONTAL_LEFT        {{xLEFT  , yMID_TB}, {xMID_TE, yMID_TE + !(thickness % 2)}}
#define LINE_HORIZONTAL_RIGHT       {{xMID_TB, yMID_TB}, {xRIGHT , yMID_TE + !(thickness % 2)}}
#define LINE_DIAGONAL_PRIMARY_TOP   {LEFT_TOP , {xMID_TE, yMID_TE}}
#define LINE_DIAGONAL_PRIMARY_BOT   {RIGHT_BOT, {xMID_TB, yMID_TB}}
#define LINE_DIAGONAL_SECONDARY_TOP {RIGHT_TOP, {xMID_TB, yMID_TE}}
#define LINE_DIAGONAL_SECONDARY_BOT {LEFT_BOT , {xMID_TE, yMID_TB}}



// -
#define PLACE_VERTEX_PAIRS_45()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_HORIZONTAL\
    }\
}

// .
#define PLACE_VERTEX_PAIRS_46()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {{xMID_TB - 1, yBOT_T - 2}, {xMID_TE + 1 + THICK % 2, yBOT}}\
    }\
}



// 0
#define PLACE_VERTEX_PAIRS_48()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_BOT\
       ,LINE_LEFT\
       ,LINE_RIGHT\
    }\
}

// 1
#define PLACE_VERTEX_PAIRS_49()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_RIGHT\
    }\
}

// 2
#define PLACE_VERTEX_PAIRS_50()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_BOT\
       ,LINE_RIGHT_TOP\
       ,LINE_LEFT_BOT\
    }\
}

// 3
#define PLACE_VERTEX_PAIRS_51()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_BOT\
       ,LINE_RIGHT\
    }\
}

// 4
#define PLACE_VERTEX_PAIRS_52()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_RIGHT\
    }\
}

// 5
#define PLACE_VERTEX_PAIRS_53()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_BOT\
       ,LINE_LEFT_TOP\
       ,LINE_RIGHT_BOT\
    }\
}

// 6
#define PLACE_VERTEX_PAIRS_54()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_BOT\
       ,LINE_LEFT\
       ,LINE_RIGHT_BOT\
    }\
}

// 7
#define PLACE_VERTEX_PAIRS_55()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_RIGHT\
    }\
}

// 8
#define PLACE_VERTEX_PAIRS_56()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_LEFT\
       ,LINE_RIGHT\
       ,LINE_BOT\
       ,LINE_HORIZONTAL\
    }\
}

// 9
#define PLACE_VERTEX_PAIRS_57()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_LEFT_TOP\
       ,LINE_RIGHT\
       ,LINE_BOT\
       ,LINE_HORIZONTAL\
    }\
}



// A
#define PLACE_VERTEX_PAIRS_65()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_LEFT\
       ,LINE_RIGHT\
       ,LINE_HORIZONTAL\
    }\
}

// B
#define PLACE_VERTEX_PAIRS_66()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,{LEFT_TOP, {xRIGHT_T - 1, yTOP_T}}\
       ,{LEFT_BOT, {xRIGHT_T - 1, yBOT_T}}\
       ,{{xLEFT , yMID_TB}, {xRIGHT_T - 1, yMID_TE}}\
       ,{{xRIGHT, yTOP_T + 1 }, {xRIGHT_T, yMID_TB - 1}}\
       ,{{xRIGHT, yMID_TE + 1}, {xRIGHT_T, yBOT_T - 1 }}\
    }\
}

// C
#define PLACE_VERTEX_PAIRS_67()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_LEFT\
       ,LINE_BOT\
    }\
}

// D
#define PLACE_VERTEX_PAIRS_68()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,{LEFT_TOP, {xRIGHT_T - 1, yTOP_T}}\
       ,{LEFT_BOT, {xRIGHT_T - 1, yBOT_T}}\
       ,{{xRIGHT, yTOP_T + 1}, {xRIGHT_T, yBOT_T - 1}}\
    }\
}

// E
#define PLACE_VERTEX_PAIRS_69()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_BOT\
       ,LINE_LEFT\
    }\
}

// F
#define PLACE_VERTEX_PAIRS_70()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_LEFT\
    }\
}

// G
#define PLACE_VERTEX_PAIRS_71()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_LEFT\
       ,LINE_BOT\
       ,LINE_RIGHT_BOT\
       ,LINE_HORIZONTAL_RIGHT\
    }\
}

// H
#define PLACE_VERTEX_PAIRS_72()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_RIGHT\
       ,LINE_HORIZONTAL\
    }\
}

// I
#define PLACE_VERTEX_PAIRS_73()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_VERTICAL\
       ,{{xMID_TB, yTOP}, {xMID_TE, yTOP_T}}\
       ,{{xMID_TB, yBOT}, {xMID_TE, yBOT_T}}\
    }\
}

// J
#define PLACE_VERTEX_PAIRS_74()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_RIGHT\
       ,LINE_BOT\
       ,LINE_LEFT_BOT\
    }\
}

// K
#define PLACE_VERTEX_PAIRS_75()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_HORIZONTAL_LEFT\
       ,LINE_VERTICAL\
       ,LINE_TOP_RIGHT\
       ,LINE_BOT_RIGHT\
    }\
}

// L
#define PLACE_VERTEX_PAIRS_76()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_BOT\
    }\
}

// M
#define PLACE_VERTEX_PAIRS_77()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_RIGHT\
       ,LINE_TOP\
       ,LINE_VERTICAL_TOP\
    }\
}

// N
#define PLACE_VERTEX_PAIRS_78()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_VERTICAL\
       ,LINE_RIGHT\
       ,LINE_TOP_LEFT\
       ,LINE_BOT_RIGHT\
    }\
}

// O
#define PLACE_VERTEX_PAIRS_79()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {{xLEFT_T + 1, yTOP  }, {xRIGHT_T - 1, yTOP_T}}\
       ,{{xLEFT_T + 1, yBOT  }, {xRIGHT_T - 1, yBOT_T}}\
       ,{{xLEFT  , yTOP_T + 1}, {xLEFT_T , yBOT_T - 1}}\
       ,{{xRIGHT , yTOP_T + 1}, {xRIGHT_T, yBOT_T - 1}}\
    }\
}

// P
#define PLACE_VERTEX_PAIRS_80()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_TOP\
       ,LINE_RIGHT_TOP\
       ,LINE_HORIZONTAL\
    }\
}

// Q
#define PLACE_VERTEX_PAIRS_81()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {{xLEFT_T + 1, yTOP  }, {xRIGHT_T - 1, yTOP_T}}\
       ,{{xLEFT_T + 1, yBOT  }, {xRIGHT_T - 1, yBOT_T}}\
       ,{{xLEFT  , yTOP_T + 1}, {xLEFT_T , yBOT_T - 1}}\
       ,{{xRIGHT , yTOP_T + 1}, {xRIGHT_T, yBOT_T - 1}}\
       ,LINE_HORIZONTAL_RIGHT\
       ,LINE_VERTICAL_BOT\
    }\
}

// R
#define PLACE_VERTEX_PAIRS_82()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_TOP\
       ,LINE_RIGHT_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_VERTICAL_BOT\
       ,LINE_BOT_RIGHT\
    }\
}

// S
#define PLACE_VERTEX_PAIRS_83()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {{xRIGHT_T - 1, yTOP}, {xLEFT_T + 1, yTOP_T}}\
       ,{{xLEFT, yTOP_T + 1}, {xLEFT_T, yMID_TB - 1}}\
       ,{{xLEFT_T + 1, yMID_TB}, {xRIGHT_T - 1, yMID_TE}}\
       ,{{xRIGHT_T, yMID_TE + 1}, {xRIGHT, yBOT_T - 1}}\
       ,{{xRIGHT_T - 1, yBOT_T}, {xLEFT_T + 1, yBOT}}\
       ,{{xRIGHT, yTOP_T + 1}, {xRIGHT_T, yTOP + 2 * THICK + 1}}\
       ,{{xLEFT, yBOT_T - 1}, {xLEFT_T, yBOT - 2 * THICK - 1}}\
    }\
}

// T
#define PLACE_VERTEX_PAIRS_84()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_VERTICAL\
    }\
}

// U
#define PLACE_VERTEX_PAIRS_85()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, {xLEFT_T, yBOT_T - 1}}\
       ,{RIGHT_TOP, {xRIGHT_T, yBOT_T - 1}}\
       ,{{xLEFT_T + 1, yBOT}, {xRIGHT_T - 1, yBOT_T}}\
    }\
}

// V
#define PLACE_VERTEX_PAIRS_86()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP_LEFT\
       ,LINE_VERTICAL\
       ,LINE_BOT_RIGHT\
       ,LINE_RIGHT\
    }\
}

// W
#define PLACE_VERTEX_PAIRS_87()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT\
       ,LINE_RIGHT\
       ,LINE_BOT\
       ,LINE_VERTICAL_BOT\
    }\
}

// X
#define PLACE_VERTEX_PAIRS_88()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_BOT\
       ,LINE_VERTICAL\
       ,LINE_HORIZONTAL\
    }\
}

// Y
#define PLACE_VERTEX_PAIRS_89()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_LEFT_TOP\
       ,LINE_RIGHT_TOP\
       ,LINE_HORIZONTAL\
       ,LINE_VERTICAL_BOT\
    }\
}

// Z
#define PLACE_VERTEX_PAIRS_90()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        LINE_TOP\
       ,LINE_VERTICAL_TOP\
       ,LINE_HORIZONTAL_LEFT\
       ,LINE_LEFT_BOT\
       ,LINE_BOT\
    }\
}



#endif // LEDGER_SECTION_LETTERS_PLACE_VERTEX_PAIRS_H
