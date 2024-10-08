#ifndef LEDGER_FILE_ATTRIBUTES_CPP
    #define LEDGER_FILE_ATTRIBUTES_CPP



Ledger::FileAttributes::FileAttributes()
{
    Initialize();
}

Ledger::FileAttributes::FileAttributes(const std::string &directory
                                      ,const std::ios_base::openmode openMode)
                                      :
                                       directory{directory}
                                      ,openMode {openMode }
{
}



Ledger::FileAttributes &Ledger::FileAttributes::operator =(const Ledger::FileAttributes &attributes)
{
    directory = attributes.directory;
    openMode  = attributes.openMode;



    return *this;
}



void Ledger::FileAttributes::DisplayValues() const
{
    std::cout << GetValues() + "\n\n\n\n";
}

std::string Ledger::FileAttributes::GetOpenModeValues() const
{
    std::string
        text;

    std::vector<std::pair<std::ios_base::openmode, const std::string>>
        openMode_
        {
            {std::ios::in    , "in"    },
            {std::ios::out   , "out"   },
            {std::ios::binary, "binary"},
            {std::ios::ate   , "ate"   },
            {std::ios::app   , "app"   },
            {std::ios::trunc , "trunc" }
        };



    for (auto mode : openMode_)
    {
        if (mode.first & openMode)
        {
            (text += mode.second) += "; ";
        }
    }



    return text;
}

std::string Ledger::FileAttributes::GetValues() const
{
    std::string
        text;

    text = std::string("FileAttributes:")
         + "\n\tDirectory: " + directory
         + "\n\tOpen Mode: " + GetOpenModeValues()
         ;

    return text;
}

void Ledger::FileAttributes::Initialize()
{
    openMode = std::ios::in | std::ios::out;
}



#endif // LEDGER_FILE_ATTRIBUTES_CPP



































