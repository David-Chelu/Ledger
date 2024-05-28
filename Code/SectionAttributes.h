#ifndef LEDGER_SECTION_ATTRIBUTES_H
    #define LEDGER_SECTION_ATTRIBUTES_H



struct Ledger::SectionAttributes
{
    SectionAttributes();
    SectionAttributes(COLORREF background
                     ,COLORREF foreground
                     ,largeuint_t width
                     ,largeuint_t height
                     ,const std::string &text
                     );



    Ledger::SectionAttributes
        &operator =(const Ledger::SectionAttributes &attributes);



    void
        DisplayValues() const;

    std::string
        GetValues() const;

    void
        Initialize();



    COLORREF
        background,
        foreground;

    largeuint_t
        width,
        height;

    std::string
        text;
};



Ledger::SectionAttributes::SectionAttributes()
{
    this->Initialize();
}

Ledger::SectionAttributes::SectionAttributes(COLORREF background
                                            ,COLORREF foreground
                                            ,largeuint_t width
                                            ,largeuint_t height
                                            ,const std::string &text
                                            )
                                            :
                                            background(background)
                                           ,foreground(foreground)
                                           ,width     (width     )
                                           ,height    (height    )
                                           ,text      (text      )
{
}



Ledger::SectionAttributes &Ledger::SectionAttributes::operator =(const Ledger::SectionAttributes &attributes)
{
    this->background = attributes.background;
    this->foreground = attributes.foreground;

    this->width  = attributes.width;
    this->height = attributes.height;

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
         + "\n\tWidth: " + TGL::String(this->width)
         + "\n\tHeight: " + TGL::String(this->height)
         + "\n\tText: " + this->text
         ;

    return text;
}

void Ledger::SectionAttributes::Initialize()
{
    this->background = TGL::Pixel(0, 0, 0);
    this->foreground = TGL::Pixel(0, 192, 0);

    this->width  = TGL::xScreen();
    this->height = TGL::yScreen();

    this->text = "Default SectionAttributes Text";
}



#endif // LEDGER_SECTION_ATTRIBUTES_H
