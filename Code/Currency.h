#ifndef LEDGER_CURRENCY_H
    #define LEDGER_CURRENCY_H



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



#endif // LEDGER_CURRENCY_H



































