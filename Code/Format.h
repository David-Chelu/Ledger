#ifndef LEDGER_FORMAT_H
    #define LEDGER_FORMAT_H



#include <fstream>
#include <string>



namespace Ledger
{
    struct Format;



    const std::vector<uint8_t>
        linePadding{0, 255, 0, 255};

    const std::string
        newline{13, 10};
}



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



Ledger::Format::Format()
{
}

Ledger::Format::Format(const std::string &date
                      ,largeint_t value
                      ,const std::string &description)
                      :
                       date{date}
                      ,value{value}
                      ,description{description}
{
}

Ledger::Format::Format(const std::vector<uint8_t>::const_iterator begin,
                       const std::vector<uint8_t>::const_iterator end)
{
    auto
        dateStart        = begin, dateStop        = begin
       ,valueStart       = begin, valueStop       = begin
       ,descriptionStart = begin, descriptionStop = begin
       ;



    dateStart = begin;
    dateStop  = std::search(begin
                           ,end
                           ,Ledger::linePadding.begin()
                           ,Ledger::linePadding.end()
                           );

    if (end != dateStop)
    {
        valueStart = dateStop + Ledger::linePadding.size();
        valueStop  = valueStart + sizeof(value);

        if (end != std::search(valueStop,
                                      valueStop + Ledger::linePadding.size(),
                                      Ledger::linePadding.begin(),
                                      Ledger::linePadding.end()))
        {
            descriptionStart = valueStop + Ledger::linePadding.size();
            descriptionStop  = end;

            date.assign(dateStart, dateStop);
            std::copy(valueStart, valueStop, (uint8_t*)&value);
            description.assign(descriptionStart, descriptionStop);

            lastNewline_ = std::search(descriptionStart, end,
                                       Ledger::newline.begin(), Ledger::newline.end());
        }
    }
}

Ledger::Format::Format(const std::vector<uint8_t> &text) : Format(text.begin(), text.end())
{
}



void Ledger::Format::DisplayValues() const
{
    std::cout << GetValues() + "\n\n\n\n";
}

std::string Ledger::Format::GetValues() const
{
    std::string
        text;

    text = std::string("Format:")
         + "\n\tDate: " + date
         + "\n\tValue: " + TGL::String(value)
         + "\n\tDescription: " + description
         ;

    return text;
}

const std::vector<uint8_t>::const_iterator Ledger::Format::LastNewline() const
{
    return lastNewline_;
}



#endif // LEDGER_FORMAT_H



































