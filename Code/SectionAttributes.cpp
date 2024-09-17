#ifndef LEDGER_SECTION_ATTRIBUTES_CPP
    #define LEDGER_SECTION_ATTRIBUTES_CPP



Ledger::SectionAttributes::SectionAttributes()
{
    this->Initialize();
}

Ledger::SectionAttributes::SectionAttributes(COLORREF background
                                            ,COLORREF foreground
                                            ,largeuint_t xBorder
                                            ,largeuint_t yBorder
                                            ,const std::string &text
                                            )
                                            :
                                            background(background)
                                           ,foreground(foreground)
                                           ,xBorder   (xBorder   )
                                           ,yBorder   (yBorder   )
                                           ,text      (text      )
{
}

Ledger::SectionAttributes::SectionAttributes(const std::string &text)
                                            :
                                            text{text}
{
}



Ledger::SectionAttributes &Ledger::SectionAttributes::operator =(const Ledger::SectionAttributes &attributes)
{
    this->background = attributes.background;
    this->foreground = attributes.foreground;

    this->xBorder = attributes.xBorder;
    this->yBorder = attributes.yBorder;

    this->text = attributes.text;



    return *this;
}



void Ledger::SectionAttributes::DisplayValues() const
{
    std::cout << this->GetValues() + "\n\n\n\n";
}

std::string Ledger::SectionAttributes::GetValues() const
{
    std::string
        text;

    text = std::string("SectionAttributes:")
         + "\n\tBackground: " + TGL::Colors(this->background)
         + "\n\tForeground: " + TGL::Colors(this->foreground)
         + "\n\txBorder: " + TGL::String(this->xBorder)
         + "\n\tyBorder: " + TGL::String(this->yBorder)
         + "\n\tText: " + this->text
         ;

    return text;
}

void Ledger::SectionAttributes::Initialize()
{
    this->background = TGL::Pixel(0, 0, 0);
    this->foreground = TGL::Pixel(192, 192, 192);

    this->xBorder = 0;
    this->yBorder = 0;

    this->text = "Sample Text";
}



#endif // LEDGER_SECTION_ATTRIBUTES_CPP
