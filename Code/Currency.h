#ifndef LEDGER_CURRENCY_H
    #define LEDGER_CURRENCY_H



namespace Ledger
{
    class Currency;
}



struct Ledger::Currency
{
    enum class Position{Begin, End};



    std::string
        Transform(largeint_t value) const;



    std::string
        name,
        symbol;

    float
        unitCount;

    bool
        space;

    Ledger::Currency::Position
        position;



private:

    std::string
        &AddPrefix(std::string &result) const,
        &AddSuffix(std::string &result) const;
};



std::string Ledger::Currency::Transform(largeint_t value) const
{
    std::string
        result{TGL::String(float(value) * unitCount)};

    return AddSuffix(AddPrefix(result));
}



std::string &Ledger::Currency::AddPrefix(std::string &result) const
{
    if (Ledger::Currency::Position::Begin == position)
    {
        return result = ((space? symbol + ' ' : symbol) + result);
    }

    return result;
}

std::string &Ledger::Currency::AddSuffix(std::string &result) const
{
    if (Ledger::Currency::Position::End == position)
    {
        return (result += (space? ' ' + symbol : symbol));
    }

    return result;
}



#endif // LEDGER_CURRENCY_H



































