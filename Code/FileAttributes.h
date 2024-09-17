#ifndef LEDGER_FILE_ATTRIBUTES_H
    #define LEDGER_FILE_ATTRIBUTES_H



struct Ledger::FileAttributes
{
    FileAttributes();
    FileAttributes(const std::string &directory,
                   const std::ios_base::openmode openMode_);



    Ledger::FileAttributes
        &operator =(const Ledger::FileAttributes &attributes);



    void
        DisplayValues() const;

    std::string
        GetOpenModeValues() const,
        GetValues() const;

    void
        Initialize();



    std::string
        directory;

    std::ios_base::openmode
        openMode;
};



#endif // LEDGER_FILE_ATTRIBUTES_H



































