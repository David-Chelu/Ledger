#ifndef LEDGER_TYPEWRITER_H
    #define LEDGER_TYPEWRITER_H



class Ledger::Typewriter
{
public:

    Typewriter();



    largeuint_t
        Print(Ledger::Section &section) const;



    largeuint_t
        &xFont,
        &yFont,
        &xPadding,
        &yPadding;

private:

    largeuint_t
        xFont_,
        yFont_,
        xPadding_,
        yPadding_;
};



#endif // LEDGER_TYPEWRITER_H
