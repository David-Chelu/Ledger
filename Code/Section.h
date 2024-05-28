#ifndef LEDGER_SECTION_H
    #define LEDGER_SECTION_H



namespace Ledger
{
    struct SectionAttributes;
    class Section;
}



#include "SectionAttributes.h"
#include "Letters.h"



class Ledger::Section
{
public:

    Section();



    void GenerateBitmap();



    Ledger::SectionAttributes
        &current;

    const Ledger::SectionAttributes
        &previous;

    const TGL::tglBitmap
        &image;

private:

    Ledger::SectionAttributes
        current_,
        previous_;

    TGL::tglBitmap
        image_;
};



Ledger::Section::Section() : current {current_ }
                           , previous{previous_}
                           , image   {image_   }
{
}



void Ledger::Section::GenerateBitmap()
{
}

//sections will be black rectangles with text in them. Border is a whole draw on first frame, unicolor



#endif // LEDGER_SECTION_H
