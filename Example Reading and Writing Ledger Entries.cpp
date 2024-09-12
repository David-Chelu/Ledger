#include "Code/TGL/TGL.h"
#include "Code/File.h"



int main()
{
    Ledger::File
        file; // in namespace Ledger, variable ledgerEntriesDirectory holds the default "ledger.ldg" file name



    // Ledger::File::ReadEntriesDirectly uses default file name
    file.ReadEntriesDirectly();



    // Ledger::File::entries is a std::vector<Ledger::Format>

    /* Ledger::Format is
        std::string date
        largeint_t value // largeint_t = int64_t in the current version of TGL
        std::string description
    */
    file.entries.push_back({"2024.09.12", static_cast<largeint_t>(1) << 51, "Sample"});

    // Perfect for debugging before calling WriteEntriesDirectly
    file.DisplayEntries();



    // Ledger::File::WriteEntriesDirectly uses default file name, overwrites file contents
    // file.WriteEntriesDirectly();



    TGL::Message("End of Program", "Click OK to exit program.");



    return 0;
}
