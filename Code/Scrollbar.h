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
        scroller_->UpdateInternal();

        return true;
    }

    return false;
}

bool Ledger::Scrollbar::UpdateInternal()
{
    if (scroller_)
    {
        cursor_ = scroller_->start;

        return true;
    }

    return false;
}

bool Ledger::Scrollbar::Grab(LPPOINT mouse)
{
    if (mouse)
    {
        static largeint_t
            x1, x2,
            y1, y2,
            pivot;

        pivot = position();

        x1 = xPosition;
        y1 = yPosition + pivot - barHeight_ / 2;

        x2 = x1 + current.width;
        y2 = y1 + barHeight_;

        if (y1 <= mouse->y && mouse->y < y2 &&
            x1 <= mouse->x && mouse->x < x2)
        {
            grabbed_ = true;
        }
        else
        {
            grabbed_ = false;
        }
    }

    return grabbed_;
}

bool Ledger::Scrollbar::Release()
{
    return (grabbed_ = false);
}

bool Ledger::Scrollbar::ChangedProximity(LPPOINT mouse)
{
    if (mouse)
    {
        static largeint_t
            above,
            below,
            pivot;
        
        --cursor_;
        above = position();
        
        cursor_ += 2;
        below = position();

        --cursor_;
        pivot = position();



        if (begin_ <= cursor_ - 1 && cursor_ - 1 <= end_ &&
            TGL::Abs(mouse->y - above) < TGL::Abs(pivot - mouse->y))
        {
            --cursor_;

            return true;
        }

        if (begin_ <= cursor_ + 1 && cursor_ + 1 <= end_ &&
            TGL::Abs(mouse->y - below) < TGL::Abs(pivot - mouse->y))
        {
            ++cursor_;

            return true;
        }
    }

    return false;
}

bool Ledger::Scrollbar::Inside(LPPOINT mouse) const
{
    if (mouse)
    {
        if (yPosition <= mouse->y && mouse->y < yPosition + current.height &&
            xPosition <= mouse->x && mouse->x < xPosition + current.width)
        {
            return true;
        }
    }

    return false;
}

void Ledger::Scrollbar::Place(COLORREF color)
{
    static largeint_t
        pivot;

    pivot = position();

    Fill(0);

    Fill(color,
         0,
         pivot - barHeight_ / 2,
         -1,
         pivot + barHeight_ / 2);
}



const largeint_t Ledger::Scrollbar::interval() const
{
    return end_ - begin_;
}

const largeint_t Ledger::Scrollbar::position() const
{
    return barHeight_ / 2 + cursor_ * barRegion_ / interval();
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
