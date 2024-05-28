#ifndef LEDGER_SECTION_LETTERS_PLACE_VERTEX_PAIRS_H
    #define LEDGER_SECTION_LETTERS_PLACE_VERTEX_PAIRS_H



#define xLEFT  0
#define xMID   bitmap.current.width / 2
#define xRIGHT bitmap.current.width - 1

#define yTOP 0
#define yMID bitmap.current.height / 2
#define yBOT bitmap.current.height - 1

#define LEFT_TOP  {xLEFT,  yTOP}
#define LEFT_MID  {xLEFT,  yMID}
#define LEFT_BOT  {xLEFT,  yBOT}
#define MID_TOP   {xMID,   yTOP}
#define CENTER    {xMID,   yMID}
#define MID_BOT   {xMID,   yBOT}
#define RIGHT_TOP {xRIGHT, yTOP}
#define RIGHT_MID {xRIGHT, yMID}
#define RIGHT_BOT {xRIGHT, yBOT}



// 0
#define PLACE_VERTEX_PAIRS_48()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , RIGHT_TOP}\
       ,{LEFT_TOP , LEFT_BOT }\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{LEFT_BOT , RIGHT_BOT}\
    }\
}

// 1
#define PLACE_VERTEX_PAIRS_49()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {RIGHT_TOP, RIGHT_BOT}\
    }\
}

// 2
#define PLACE_VERTEX_PAIRS_50()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , RIGHT_TOP}\
       ,{RIGHT_TOP, RIGHT_MID}\
       ,{RIGHT_MID, LEFT_MID }\
       ,{LEFT_MID , LEFT_BOT }\
       ,{LEFT_BOT , RIGHT_BOT}\
    }\
}

// 3
#define PLACE_VERTEX_PAIRS_51()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , RIGHT_TOP}\
       ,{LEFT_MID , RIGHT_MID}\
       ,{LEFT_BOT , RIGHT_BOT}\
       ,{RIGHT_TOP, RIGHT_BOT}\
    }\
}

// 4
#define PLACE_VERTEX_PAIRS_52()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , LEFT_MID }\
       ,{LEFT_MID , RIGHT_MID}\
       ,{RIGHT_TOP, RIGHT_BOT}\
    }\
}

// 5
#define PLACE_VERTEX_PAIRS_53()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {RIGHT_TOP, LEFT_TOP }\
       ,{LEFT_TOP , LEFT_MID }\
       ,{LEFT_MID , RIGHT_MID}\
       ,{RIGHT_MID, RIGHT_BOT}\
       ,{RIGHT_BOT, LEFT_BOT }\
    }\
}

// 6
#define PLACE_VERTEX_PAIRS_54()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {RIGHT_TOP, LEFT_TOP }\
       ,{LEFT_TOP , LEFT_BOT }\
       ,{LEFT_BOT , RIGHT_BOT}\
       ,{RIGHT_BOT, RIGHT_MID}\
       ,{RIGHT_MID, LEFT_MID }\
    }\
}

// 7
#define PLACE_VERTEX_PAIRS_55()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , RIGHT_TOP}\
       ,{RIGHT_TOP, RIGHT_BOT}\
    }\
}

// 8
#define PLACE_VERTEX_PAIRS_56()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , RIGHT_TOP}\
       ,{LEFT_TOP , LEFT_BOT }\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{LEFT_BOT , RIGHT_BOT}\
       ,{LEFT_MID , RIGHT_MID}\
    }\
}

// 9
#define PLACE_VERTEX_PAIRS_57()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {RIGHT_TOP, LEFT_TOP }\
       ,{LEFT_TOP , LEFT_MID }\
       ,{LEFT_MID , RIGHT_MID}\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{RIGHT_BOT, LEFT_BOT }\
    }\
}



// A
#define PLACE_VERTEX_PAIRS_65()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , LEFT_BOT }\
       ,{LEFT_TOP , RIGHT_TOP}\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{LEFT_MID , RIGHT_MID}\
    }\
}

// B
#define PLACE_VERTEX_PAIRS_66()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, {xRIGHT - 1, yTOP}}\
       ,{LEFT_MID, {xRIGHT - 1, yMID}}\
       ,{LEFT_BOT, {xRIGHT - 1, yBOT}}\
       ,{LEFT_TOP, LEFT_BOT}\
       ,{{xRIGHT, yTOP + 1}, {xRIGHT, yMID - 1}}\
       ,{{xRIGHT, yMID + 1}, {xRIGHT, yBOT - 1}}\
    }\
}

// C
#define PLACE_VERTEX_PAIRS_67()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, RIGHT_TOP}\
       ,{LEFT_TOP, LEFT_BOT}\
       ,{LEFT_BOT, RIGHT_BOT}\
    }\
}

// D
#define PLACE_VERTEX_PAIRS_68()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, {xRIGHT - 1, yTOP}}\
       ,{LEFT_TOP, LEFT_BOT}\
       ,{LEFT_BOT, {xRIGHT - 1, yBOT}}\
       ,{{xRIGHT, yTOP + 1}, {xRIGHT, yBOT - 1}}\
    }\
}

// E
#define PLACE_VERTEX_PAIRS_69()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, RIGHT_TOP}\
       ,{LEFT_MID, RIGHT_MID}\
       ,{LEFT_BOT, RIGHT_BOT}\
       ,{LEFT_TOP, LEFT_BOT}\
    }\
}

// F
#define PLACE_VERTEX_PAIRS_70()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, RIGHT_TOP}\
       ,{LEFT_MID, RIGHT_MID}\
       ,{LEFT_TOP, LEFT_BOT}\
    }\
}

// G
#define PLACE_VERTEX_PAIRS_71()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP,  RIGHT_TOP}\
       ,{LEFT_TOP,  LEFT_BOT}\
       ,{LEFT_BOT,  RIGHT_BOT}\
       ,{RIGHT_BOT, RIGHT_MID}\
       ,{RIGHT_MID, CENTER}\
    }\
}

// H
#define PLACE_VERTEX_PAIRS_72()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , LEFT_BOT}\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{LEFT_MID , RIGHT_MID}\
    }\
}

// I
#define PLACE_VERTEX_PAIRS_73()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {MID_TOP, MID_BOT}\
       ,{{xMID - 1, yTOP}, {xMID + 1, yTOP}}\
       ,{{xMID - 1, yBOT}, {xMID + 1, yBOT}}\
    }\
}

// J
#define PLACE_VERTEX_PAIRS_74()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {RIGHT_TOP, RIGHT_BOT}\
       ,{RIGHT_BOT, LEFT_BOT }\
       ,{LEFT_BOT , LEFT_MID }\
    }\
}

// K
#define PLACE_VERTEX_PAIRS_75()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, LEFT_BOT }\
       ,{LEFT_MID, CENTER   }\
       ,{MID_TOP , MID_BOT  }\
       ,{MID_TOP , RIGHT_TOP}\
       ,{MID_BOT , RIGHT_BOT}\
    }\
}

// L
#define PLACE_VERTEX_PAIRS_76()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, LEFT_BOT }\
       ,{LEFT_BOT, RIGHT_BOT}\
    }\
}

// M
#define PLACE_VERTEX_PAIRS_77()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , LEFT_BOT }\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{LEFT_TOP , RIGHT_TOP}\
       ,{MID_TOP  , CENTER   }\
    }\
}

// N
#define PLACE_VERTEX_PAIRS_78()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_BOT , LEFT_TOP }\
       ,{LEFT_TOP , MID_TOP  }\
       ,{MID_TOP  , MID_BOT  }\
       ,{MID_BOT  , RIGHT_BOT}\
       ,{RIGHT_BOT, RIGHT_TOP}\
    }\
}

// O
#define PLACE_VERTEX_PAIRS_79()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {{xLEFT + 1, yTOP    }, {xRIGHT - 1, yTOP    }}\
       ,{{xLEFT    , yTOP + 1}, {xLEFT     , yBOT - 1}}\
       ,{{xLEFT + 1, yBOT    }, {xRIGHT - 1, yBOT    }}\
       ,{{xRIGHT   , yTOP + 1}, {xRIGHT    , yBOT - 1}}\
    }\
}

// P
#define PLACE_VERTEX_PAIRS_80()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , RIGHT_TOP}\
       ,{LEFT_MID , RIGHT_MID}\
       ,{LEFT_TOP , LEFT_BOT }\
       ,{RIGHT_TOP, RIGHT_MID}\
    }\
}

// Q
#define PLACE_VERTEX_PAIRS_81()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {{xLEFT  + 1, yTOP    }, {xRIGHT - 1, yTOP    }}\
       ,{{xLEFT     , yTOP + 1}, {xLEFT     , yBOT - 1}}\
       ,{{xLEFT  + 1, yBOT    }, {xRIGHT - 1, yBOT    }}\
       ,{{xRIGHT    , yTOP + 1}, {xRIGHT    , yBOT - 1}}\
       ,{{xRIGHT - 3, yBOT - 2}, {xRIGHT    , yBOT - 2}}\
    }\
}

// R
#define PLACE_VERTEX_PAIRS_82()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , RIGHT_TOP}\
       ,{LEFT_MID , RIGHT_MID}\
       ,{LEFT_TOP , LEFT_BOT }\
       ,{RIGHT_TOP, RIGHT_MID}\
       ,{CENTER   , MID_BOT  }\
       ,{MID_BOT  , RIGHT_BOT}\
    }\
}

// S
#define PLACE_VERTEX_PAIRS_83()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {{xLEFT + 1, yTOP    }, {xRIGHT - 1, yTOP    }}\
       ,{{xLEFT    , yTOP + 1}, {xLEFT     , yMID - 1}}\
       ,{{xLEFT + 1, yMID    }, {xRIGHT - 1, yMID    }}\
       ,{{xRIGHT   , yMID + 1}, {xRIGHT    , yBOT - 1}}\
       ,{{xLEFT + 1, yBOT    }, {xRIGHT - 1, yBOT    }}\
       ,{{xLEFT    , yBOT - 1}, {xLEFT     , yBOT - 2}}\
       ,{{xRIGHT   , yTOP + 1}, {xRIGHT    , yTOP + 2}}\
    }\
}

// T
#define PLACE_VERTEX_PAIRS_84()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, RIGHT_TOP}\
       ,{MID_TOP , MID_BOT  }\
    }\
}

// U
#define PLACE_VERTEX_PAIRS_85()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , LEFT_BOT }\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{LEFT_BOT , RIGHT_BOT}\
    }\
}

// V
#define PLACE_VERTEX_PAIRS_86()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , MID_TOP  }\
       ,{MID_TOP  , CENTER   }\
       ,{CENTER   , MID_BOT  }\
       ,{MID_BOT  , RIGHT_BOT}\
       ,{RIGHT_BOT, RIGHT_TOP}\
    }\
}

// W
#define PLACE_VERTEX_PAIRS_87()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , LEFT_BOT }\
       ,{RIGHT_TOP, RIGHT_BOT}\
       ,{LEFT_BOT , RIGHT_BOT}\
       ,{CENTER   , MID_BOT  }\
    }\
}

// X
#define PLACE_VERTEX_PAIRS_88()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, RIGHT_TOP}\
       ,{LEFT_BOT, RIGHT_BOT}\
       ,{MID_TOP , MID_BOT  }\
       ,{LEFT_MID, RIGHT_MID}\
    }\
}

// Y
#define PLACE_VERTEX_PAIRS_89()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP , LEFT_MID }\
       ,{LEFT_MID , RIGHT_MID}\
       ,{RIGHT_MID, RIGHT_TOP}\
       ,{CENTER   , MID_BOT  }\
    }\
}

// Z
#define PLACE_VERTEX_PAIRS_90()\
std::vector<Ledger::Line> diagonals\
{\
    {\
        {LEFT_TOP, RIGHT_TOP}\
       ,{MID_TOP , CENTER   }\
       ,{CENTER  , LEFT_MID }\
       ,{LEFT_MID, LEFT_BOT }\
       ,{LEFT_BOT, RIGHT_BOT}\
    }\
}



#endif // LEDGER_SECTION_LETTERS_PLACE_VERTEX_PAIRS_H
