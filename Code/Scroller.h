#ifndef TABLE_SCROLLER_SCROLLER_H
    #define TABLE_SCROLLER_SCROLLER_H



Ledger::Scroller &Ledger::Scroller::operator =(const Ledger::Information &information)
{
    this->information = &information;

    return *this;
}

Ledger::Scroller &Ledger::Scroller::operator =(const Ledger::Information *information)
{
    this->information = information;

    return *this;
}

Ledger::Scroller &Ledger::Scroller::operator =(Ledger::Scrollbar &scrollbar)
{
    scrollbar_ = &scrollbar;

    return *this;
}

Ledger::Scroller &Ledger::Scroller::operator =(Ledger::Scrollbar *scrollbar)
{
    scrollbar_ = scrollbar;

    return *this;
}

const Ledger::Format &Ledger::Scroller::operator [](uint32_t index) const
{
    return (information? information->data[index] : Ledger::error);
}



bool Ledger::Scroller::UpdateDown()
{
    static int32_t
        upperLimit;

    upperLimit = (information? information->data.size() - (scrollAfter? 1 : interval) : 0);

    if (information && start < upperLimit)
    {
        start = std::min(start + linesPerScroll, upperLimit);

        if (scrollbar_)
        {
            scrollbar_->Update();
        }

        return true;
    }

    return false;
}

bool Ledger::Scroller::UpdateUp()
{
    static int32_t
        lowerLimit;

    lowerLimit = (scrollBefore? -interval + 1 : 0);

    if (information && start > lowerLimit)
    {
        start = std::max(start - linesPerScroll, lowerLimit);

        if (scrollbar_)
        {
            scrollbar_->Update();
        }

        return true;
    }

    return false;
}

void Ledger::Scroller::DisplayConsole() const
{
    static const std::string
        border(3, 219),
        empty{"   \n"};

    static HANDLE
        console = GetStdHandle(STD_OUTPUT_HANDLE);

    std::string
        compound;

    int
        cursor;



    compound = (border + '\n');

    for (int index = 0; index < interval; ++index)
    {
        cursor = index + start;

        if (cursor < lowerLimit() || cursor >= information->data.size())
        {
            compound += empty;
        }
        else
        {
            compound += (operator[](cursor).description + '\n');
        }
    }

    compound += border;



    SetConsoleCursorPosition(console, {0, 3});

    std::cout << compound;
}

void Ledger::Scroller::Update()
{
    if (scrollbar_)
    {
        start = scrollbar_->cursor;
    }
}



int32_t Ledger::Scroller::lowerLimit() const
{
    return (scrollBefore? -interval + 1 : 0);
}

int32_t Ledger::Scroller::upperLimit() const
{
    return information->data.size() - (scrollAfter? 1 : interval);
}



#endif // TABLE_SCROLLER_SCROLLER_H
