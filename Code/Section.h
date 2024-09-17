#ifndef LEDGER_SECTION_H
    #define LEDGER_SECTION_H



#include "SectionAttributes.h"



class Ledger::Section
{
public:

    Section();
    Section(const Ledger::SectionAttributes &attributes,
            largeuint_t newXPosition = 0,
            largeuint_t newYPosition = 0);



    Ledger::Section
        &operator =(const Ledger::Section &section);



    bool
        Allocate(largeuint_t width, largeuint_t height),
        Allocate();

    void
        Fill(),
        DrawBorder(),
        DisplayValues() const;

    std::string
        GetValues() const;

    largeuint_t
        GenerateBitmap(Ledger::Typewriter &typewriter);



    const Ledger::SectionAttributes
        &current;

    Ledger::SectionAttributes
        &planned;

    TGL::tglBitmap
        &bitmap;

private:

    Ledger::SectionAttributes
        current_,
        planned_;

    TGL::tglBitmap
        bitmap_;
};



#endif // LEDGER_SECTION_H
