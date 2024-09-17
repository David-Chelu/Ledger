#ifndef TABLE_SCROLLBAR_H
    #define TABLE_SCROLLBAR_H



class Ledger::Scrollbar : public TGL::tglBitmap
{
public:

    Scrollbar();



    Ledger::Scrollbar
        &operator =(Ledger::Scroller &scroller),
        &operator =(Ledger::Scroller *scroller);



    bool
        Update(),
        UpdateInternal(),
        Grab(LPPOINT mouse),
        Release(),
        ChangedProximity(LPPOINT mouse),
        Inside(LPPOINT mouse) const;

    void    
        Place(COLORREF color);

    

    const largeint_t
        &begin,
        &end,
        &cursor,
        &barHeight,
        &barRegion,
        interval() const,
        position() const;

    largeuint_t
        &yBorder;

    const bool
        &grabbed;
    


private:

    void
        SetRange();



    largeint_t
        begin_,
        end_,
        cursor_,
        barHeight_,
        barRegion_;

    largeuint_t
        yBorder_;

    bool
        grabbed_;
    
    Ledger::Scroller
        *scroller_;
};



#endif // TABLE_SCROLLBAR_H
