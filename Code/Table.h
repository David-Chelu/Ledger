#ifndef LEDGER_TABLE_H
    #define LEDGER_TABLE_H



class Ledger::Table
{
public:

    Table();



    Ledger::Table
        &operator =(const TGL::tglWindow &window),
        &operator =(const Ledger::File &file),
        &operator =(Ledger::Scroller &scroller);

    std::vector<Ledger::Section>
        &operator [](largeuint_t index);
    
    const std::vector<Ledger::Section>
        &operator [](largeuint_t index) const;

    

    void
        Split(Ledger::Typewriter &typewriter, std::function<void()> callable = NULL);

    largeuint_t
        ComputeWidth(uint8_t lengthAssumed) const,
        ComputeHeight(uint8_t lengthAssumed) const;



    std::vector<std::vector<Ledger::Section>>
        &sections;

    largeuint_t
        &width,
        &height,
        &xBorder,
        &yBorder;

    const Ledger::File
        *&file;

    Ledger::Scroller
        *&scroller;

    Ledger::Scrollbar
        &scrollbar;

private:



    std::vector<std::vector<Ledger::Section>>
        sections_;

    largeuint_t
        width_,
        height_,
        xBorder_,
        yBorder_;

    const Ledger::File
        *file_;

    Ledger::Scroller
        *scroller_;

    Ledger::Scrollbar
        scrollbar_;
};



#endif // LEDGER_TABLE_H