#ifndef LEDGER_FILE_H
    #define LEDGER_FILE_H



#include "FileAttributes.h"



class Ledger::File
{
public:

    File();
    File(const std::vector<Ledger::Format> &entries);
    ~File();



    void
        Initialize()
       ,Clear()
       ,Close()
       ,Couple(const std::vector<uint8_t> &text) // Pair, Connect, Couple, or Clip
       ,DisplayEntries() const
       ;

    bool
        Open()
       ,Open(const std::string &directory)
       ,Open(const std::ios_base::openmode openMode)
       ,Open(const std::string &directory, const std::ios_base::openmode openMode)
       ;

    largeuint_t
        ReadEntries()
       ,ReadEntriesDirectly()
       ,WriteEntry(const Ledger::Format &entry)
       ,WriteEntries(const std::vector<Ledger::Format> &entries)
       ,WriteEntries()
       ,WriteEntriesDirectly(const std::vector<Ledger::Format> &entries)
       ,WriteEntriesDirectly()
       ,LongestLine()
       ,LongestDate()
       ,LongestDescription()
       ;

    static largeuint_t
        LongestLine(const std::vector<Ledger::Format> &entries)
       ,LongestDate(const std::vector<Ledger::Format> &entries)
       ,LongestDescription(const std::vector<Ledger::Format> &entries)
       ,LineSize(const Ledger::Format &entry)
       ;



    bool operator !() const;
    operator bool() const;



    const Ledger::FileAttributes
        &current;

    Ledger::FileAttributes
        &planned;
    
    std::vector<Ledger::Format>
        &entries;

private:

    std::fstream
        handle_;

    Ledger::FileAttributes
        current_,
        planned_;

    std::vector<Ledger::Format>
        entries_;

};



#endif // LEDGER_FILE_H



































