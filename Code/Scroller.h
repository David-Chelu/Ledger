#ifndef TABLE_SCROLLER_SCROLLER_H
    #define TABLE_SCROLLER_SCROLLER_H



struct Ledger::Scroller
{
    Scroller();



    Ledger::Scroller
        &operator =(const Ledger::Information &information),
        &operator =(const Ledger::Information *information),
        &operator =(Ledger::Scrollbar &scrollbar),
        &operator =(Ledger::Scrollbar *scrollbar);

    const Ledger::Format
        &operator [](uint32_t index) const;



    bool
        UpdateDown(),
        UpdateUp();

    void
        DisplayConsole() const,
        Update(),
        UpdateInternal();



    int32_t
        lowerLimit() const,
        upperLimit() const;



    const Ledger::Information
        *information;

    int32_t
        start,
        interval,
        linesPerScroll;

    bool
        scrollBefore,
        scrollAfter;



private:

    Ledger::Scrollbar
        *scrollbar_;
};



#endif // TABLE_SCROLLER_SCROLLER_H
