#ifndef TABLE_SCROLLER_SCROLLER_DECL_H
    #define TABLE_SCROLLER_SCROLLER_DECL_H



#include "Information.h"
#include <windows.h>
#include <iostream>



namespace Ledger
{
    struct Scroller;
    class Scrollbar;

    Ledger::Format
        error{"", 0, "Error"};
}



struct Ledger::Scroller
{
    Scroller() : information{NULL}, start{0}, interval{5}, linesPerScroll{3}, scrollBefore{false}, scrollAfter{false} {}



    Ledger::Scroller
        &operator =(const Ledger::Information &information),
        &operator =(const Ledger::Information *information),
        &operator =(Ledger::Scrollbar &scrollbar),
        &operator =(Ledger::Scrollbar *scrollbar);

    const Ledger::Format
        &operator [](uint32_t index) const;



    bool
        UpdateDown(),
        UpdateUp();

    void
        DisplayConsole() const,
        Update(),
        UpdateInternal();



    int32_t
        lowerLimit() const,
        upperLimit() const;



    const Ledger::Information
        *information;

    int32_t
        start,
        interval,
        linesPerScroll;

    bool
        scrollBefore,
        scrollAfter;



private:

    Ledger::Scrollbar
        *scrollbar_;
};



#endif // TABLE_SCROLLER_SCROLLER_DECL_H
