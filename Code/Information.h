#ifndef TABLE_SCROLLER_INFORMATION_H
    #define TABLE_SCROLLER_INFORMATION_H



#include "Format.h"
#include <vector>
#include <string>
#include <stdint.h>



namespace Ledger
{
    struct Information;
}



std::string Padded(const std::string &text, uint32_t plannedWidth, char padding)
{
    return text + std::string(plannedWidth <= text.length()? 0 : plannedWidth - text.length(), padding);
}

std::string PrePadded(const std::string &text, uint32_t plannedWidth, char padding)
{
    return std::string(plannedWidth <= text.length()? 0 : plannedWidth - text.length(), padding) + text;
}



struct Ledger::Information
{
    Information() : data{data_} {}
    Information(std::vector<Ledger::Format> &other) : data{other} {}



    std::vector<Ledger::Format>
        &data;
    
private:

    std::vector<Ledger::Format>
        data_;
};



#endif // TABLE_SCROLLER_INFORMATION_H