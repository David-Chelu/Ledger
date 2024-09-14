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
        position;

    position = barHeight_ / 2 + cursor * barRegion_ / interval();

    Fill(0);

    Fill(color,
         0,
         position - barHeight_ / 2,
         -1,
         position + barHeight_ / 2);
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

        barHeight_ = m_current.width * 3 / 2;
        barRegion_ = m_current.height - barHeight;
    }
}



#endif // TABLE_SCROLLBAR_H
