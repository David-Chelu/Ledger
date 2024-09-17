#ifndef TABLE_SCROLLER_INFORMATION_H
    #define TABLE_SCROLLER_INFORMATION_H



struct Ledger::Information
{
    Information();
    Information(std::vector<Ledger::Format> &other);



    std::vector<Ledger::Format>
        &data;
    
private:

    std::vector<Ledger::Format>
        data_;
};



#endif // TABLE_SCROLLER_INFORMATION_H