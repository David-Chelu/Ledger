#ifndef TABLE_SCROLLBAR_DECL_H
    #define TABLE_SCROLLBAR_DECL_H



namespace Ledger
{
    class Scrollbar;
}



class Ledger::Scrollbar : public TGL::tglBitmap
{
public:

    Scrollbar() : begin {begin_},
                  end   {end_},
                  cursor{cursor_},
                  tglBitmap()
                  {}



    Ledger::Scrollbar
        &operator =(Ledger::Scroller &scroller),
        &operator =(Ledger::Scroller *scroller);



    bool
        Update();

    void    
        Place(COLORREF color);

    

    const largeint_t
        &begin,
        &end,
        &cursor,
        interval() const;
    


private:

    void
        SetRange();



    largeint_t
        begin_,
        end_,
        cursor_;
    
    Ledger::Scroller
        *scroller_;
};



#endif // TABLE_SCROLLBAR_DECL_H
