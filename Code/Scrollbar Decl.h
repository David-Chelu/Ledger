#ifndef TABLE_SCROLLBAR_DECL_H
    #define TABLE_SCROLLBAR_DECL_H



namespace Ledger
{
    class Scrollbar;
}



class Ledger::Scrollbar : public TGL::tglBitmap
{
public:

    Scrollbar() : begin    {begin_    },
                  end      {end_      },
                  cursor   {cursor_   },
                  yBorder  {yBorder_  },
                  barHeight{barHeight_},
                  barRegion{barRegion_},
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
        &barHeight,
        &barRegion,
        interval() const;

    largeuint_t
        &yBorder;
    


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
    
    Ledger::Scroller
        *scroller_;
};



#endif // TABLE_SCROLLBAR_DECL_H
