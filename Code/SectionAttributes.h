#ifndef LEDGER_SECTION_ATTRIBUTES_H
    #define LEDGER_SECTION_ATTRIBUTES_H



struct Ledger::SectionAttributes
{
    SectionAttributes();
    SectionAttributes(COLORREF background
                     ,COLORREF foreground
                     ,largeuint_t xBorder
                     ,largeuint_t yBorder
                     ,const std::string &text
                     );
    SectionAttributes(const std::string &text);



    Ledger::SectionAttributes
        &operator =(const Ledger::SectionAttributes &attributes);



    void
        DisplayValues() const;

    std::string
        GetValues() const;

    void
        Initialize();



    COLORREF
        background,
        foreground;

    largeuint_t
        xBorder,
        yBorder;

    std::string
        text;
};



#endif // LEDGER_SECTION_ATTRIBUTES_H
