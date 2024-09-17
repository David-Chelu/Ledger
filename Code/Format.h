#ifndef LEDGER_FORMAT_H
    #define LEDGER_FORMAT_H



struct Ledger::Format
{
    Format();
    Format(const std::string &date,
           largeint_t value,
           const std::string &description);
    Format(const std::vector<uint8_t>::const_iterator begin,
           const std::vector<uint8_t>::const_iterator end);
    Format(const std::vector<uint8_t> &text);



    void
        DisplayValues() const;

    std::string
        GetValues() const;

    const std::vector<uint8_t>::const_iterator
        LastNewline() const;



    std::string
        date;

    largeint_t
        value;

    std::string
        description;

private:

    std::vector<uint8_t>::const_iterator
        lastNewline_;

};



#endif // LEDGER_FORMAT_H



































