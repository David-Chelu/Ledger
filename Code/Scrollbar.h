#ifndef TABLE_SCROLLBAR_H
    #define TABLE_SCROLLBAR_H



Ledger::Scrollbar &Ledger::Scrollbar::operator =(Ledger::Scroller &scroller)
{
    return operator =(&scroller);
}

Ledger::Scrollbar &Ledger::Scrollbar::operator =(Ledger::Scroller *scroller)
{
    if (scroller_ = scroller)
    {
        SetRange();
    }

    return *this;
}



bool Ledger::Scrollbar::Update()
{
    if (scroller_)
    {
        cursor_ = scroller_->start;

        scroller_->Update();

        return true;
    }

    return false;
}

void Ledger::Scrollbar::Place(COLORREF color)
{
    static largeint_t
        barHeight;

    barHeight = m_current.height / (interval() + 1);

    Fill(color,
         0,
         barHeight * cursor,
         -1,
         barHeight * (cursor + 1));
}



const largeint_t Ledger::Scrollbar::interval() const
{
    return end_ - begin_;
}



void Ledger::Scrollbar::SetRange()
{
    if (scroller_)
    {
        begin_ = scroller_->lowerLimit();
        end_   = scroller_->upperLimit();

        cursor_ = scroller_->start;
    }
}



#endif // TABLE_SCROLLBAR_H
