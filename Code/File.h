#ifndef LEDGER_FILE_H
    #define LEDGER_FILE_H



#include "FileAttributes.h"
#include "Format.h"

#include <fstream>
#include <string>



namespace Ledger
{
    class File;
}



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

private:

    std::fstream
        handle_;

    Ledger::FileAttributes
        current_,
        planned_;

    std::vector<Ledger::Format>
        entries_;

};



Ledger::File::File() : planned{planned_}, current{current_}
{
    Initialize();
}

Ledger::File::File(const std::vector<Ledger::Format> &entries) : File()
{
    entries_ = entries;
}

Ledger::File::~File()
{
    Clear();
}



void Ledger::File::Initialize()
{
}

void Ledger::File::Clear()
{
    Close();
}

void Ledger::File::Close()
{
    if (handle_.is_open())
    {
        handle_.close();
    }
}

void Ledger::File::Couple(const std::vector<uint8_t> &text)
{
    std::vector<uint8_t>::const_iterator
        begin = text.begin(),
        end   = text.end(),
        pivot;

    size_t
        offset = Ledger::newline.size();

    if (end - offset == std::search(end - offset,
                                    end,
                                    Ledger::newline.begin(),
                                    Ledger::newline.end()))
    {
        end -= offset;
    }

    pivot = begin;

    do
    {
        entries_.push_back({pivot, end});
    }
    while ((pivot = entries_.back().LastNewline() + Ledger::newline.size()) != end &&
           entries_.back().LastNewline() != end);
}

void Ledger::File::DisplayEntries() const
{
    for (const Ledger::Format &entry : entries_)
    {
        entry.DisplayValues();
    }
}

bool Ledger::File::Open()
{
    return Open(planned.directory, planned.openMode);
}

bool Ledger::File::Open(const std::string &directory)
{
    return Open(directory, planned.openMode);
}

bool Ledger::File::Open(const std::ios_base::openmode openMode)
{
    return Open(planned.directory, openMode);
}

bool Ledger::File::Open(const std::string &directory, const std::ios_base::openmode openMode)
{
    handle_.open(directory, openMode);

    if (handle_.is_open())
    {
        current_.openMode  = openMode;
        current_.directory = directory;

        return true;
    }

    return false;
}

largeuint_t Ledger::File::ReadEntries()
{
    if (!handle_.is_open())
    {
        return -1;
    }

    char
        *contents;

    std::streampos
        start,
        stop,
        size;

    largeuint_t
        result;

    result = 0;



    handle_.seekg(0, handle_.end);
    stop = handle_.tellg();

    handle_.seekg(0, handle_.beg);
    start = handle_.tellg();

    contents = new char[size = stop - start];

    handle_.read(contents, size);

    Couple({contents, contents + size});




    delete []contents;

    return result;
}

largeuint_t Ledger::File::ReadEntriesDirectly()
{
    largeuint_t
        result;

    planned.openMode = std::ios::in | std::ios::binary;
    planned.directory = "ledger.ldg";

    Open();
    result = ReadEntries();
    Close();

    return result;
}

largeuint_t Ledger::File::WriteEntry(const Ledger::Format &entry)
{
    return WriteEntries({entry});
}

largeuint_t Ledger::File::WriteEntries(const std::vector<Ledger::Format> &entries)
{
    if (!handle_.is_open())
    {
        return -1;
    }

    char
        *line;

    largeuint_t
        result,
        size,
        s1,
        s2,
        s3,
        s4,
        s5,
        s6;

    line = new char[LongestLine(entries)];

    result = 0;



    for (const auto &entry : entries)
    {
        size = LineSize(entry);

        s1 = entry.date.length();
        s2 = Ledger::linePadding.size();
        s3 = sizeof(Ledger::Format::value);
        s4 = s2;
        s5 = entry.description.length();
        s6 = Ledger::newline.length();

        CopyMemory(line,
                   entry.date.data(),
                   s1);

        CopyMemory(line + s1,
                   Ledger::linePadding.data(),
                   s2);

        CopyMemory(line + s1 + s2,
                   &entry.value,
                   s3);

        CopyMemory(line + s1 + s2 + s3,
                   Ledger::linePadding.data(),
                   s4);

        CopyMemory(line + s1 + s2 + s3 + s4,
                   entry.description.data(),
                   s5);

        CopyMemory(line + s1 + s2 + s3 + s4 + s5,
                   Ledger::newline.data(),
                   s6);

        handle_.write(line, size);

        std::vector<uint8_t>
            text{line, line + size};

        ++result;
    }



    delete []line;

    return result;
}

largeuint_t Ledger::File::WriteEntries()
{
    return WriteEntries(entries_);
}

largeuint_t Ledger::File::WriteEntriesDirectly(const std::vector<Ledger::Format> &entries)
{
    largeuint_t
        result;

    planned.openMode = std::ios::out | std::ios::binary;
    planned.directory = "ledger.ldg";

    Open();
    result = WriteEntries(entries);
    Close();

    return result;
}

largeuint_t Ledger::File::WriteEntriesDirectly()
{
    return WriteEntriesDirectly(entries_);
}

largeuint_t Ledger::File::LongestLine(const std::vector<Ledger::Format> &entries)
{
    return LongestDate(entries)
         + 2 * Ledger::linePadding.size()
         + sizeof(Ledger::Format::value)
         + LongestDescription(entries)
         + Ledger::newline.size()
         ;
}

largeuint_t Ledger::File::LongestLine()
{
    return LongestLine(entries_);
}

largeuint_t Ledger::File::LongestDate(const std::vector<Ledger::Format> &entries)
{
    return std::max_element(entries.begin(),
                            entries.end(),
                            [](const Ledger::Format &lhs, const Ledger::Format &rhs)
                            {
                                return lhs.date.length() < rhs.date.length();
                            }
                            )->date.length();
}

largeuint_t Ledger::File::LongestDate()
{
    return LongestDate(entries_);
}

largeuint_t Ledger::File::LongestDescription(const std::vector<Ledger::Format> &entries)
{
    return std::max_element(entries.begin(),
                            entries.end(),
                            [](const Ledger::Format &lhs, const Ledger::Format &rhs)
                            {
                                return lhs.description.length() < rhs.description.length();
                            }
                            )->description.length();
}

largeuint_t Ledger::File::LongestDescription()
{
    return LongestDescription(entries_);
}

largeuint_t Ledger::File::LineSize(const Ledger::Format &entry)
{
    return entry.date.length()
         + 2 * Ledger::linePadding.size()
         + sizeof(Ledger::Format::value)
         + entry.description.length()
         + Ledger::newline.size()
         ;
}

bool Ledger::File::operator !() const
{
    return !handle_.is_open();
}

Ledger::File::operator bool() const
{
    return handle_.is_open();
}



#endif // LEDGER_FILE_H



































