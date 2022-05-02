//
// Created by Максим Уланов on 26.04.2022.
//

#include "letter.h"
#include "check.cpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Input(letter* Obj,int amount)
{
    Obj[amount].recipient.SetCountry(CheckCountry());
    Obj[amount].recipient.SetCity(CheckCity());
    Obj[amount].recipient.SetHouse(CheckHouse());

    Obj[amount].sender.SetCountry(CheckCountry());
    Obj[amount].sender.SetCity(CheckCity());
    Obj[amount].sender.SetHouse(CheckHouse());

    Obj[amount].fio_recipient.SetSurname((CheckSurname()));
    Obj[amount].fio_recipient.SetName((CheckName()));
    Obj[amount].fio_recipient.SetPatronymic((CheckPatronymic()));

    Obj[amount].SetPrice(CheckPrice()) ;
    std::cin.get();

    std::cout << std::endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void SearchSender(letter* Obj, int amount)
{
    std::string s;
    std::string n;
    std::string m;

    s=CheckCountry();
    n=CheckCity();
    m=CheckHouse();

    int a = Obj[0].recipient.GetCountry().length()+Obj[0].recipient.GetCity().length()+Obj[0].recipient.GetHouse().length()+28;
    int b = Obj[0].sender.GetCountry().length()+Obj[0].sender.GetCity().length()+Obj[0].sender.GetHouse().length()+28;
    int c = Obj[0].fio_recipient.GetSurname().length()+2;
    int d = Obj[0].fio_recipient.GetName().length()+2;
    int e = Obj[0].fio_recipient.GetPatronymic().length()+2;

    for (int i = 0; i < letter::count - 1; i++) {
        for (int j = i + 1; j < letter::count; j++) {
            if(Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()
               > Obj[i].recipient.GetCountry().length()+Obj[i].recipient.GetCity().length()+Obj[i].recipient.GetHouse().length()){
                a=Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()+28;
            }

            else if(Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()
                    > Obj[i].sender.GetCountry().length()+Obj[i].sender.GetCity().length()+Obj[i].sender.GetHouse().length()){
                b=Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()+28;
            }

            else if(Obj[j].fio_recipient.GetSurname().length() > Obj[i].fio_recipient.GetSurname().length()){
                c=Obj[j].fio_recipient.GetSurname().length()+2;
            }

            else if(Obj[j].fio_recipient.GetName().length() > Obj[i].fio_recipient.GetName().length()){
                d=Obj[j].fio_recipient.GetName().length()+2;
            }

            else if(Obj[j].fio_recipient.GetPatronymic().length() > Obj[i].fio_recipient.GetPatronymic().length()){
                e=Obj[j].fio_recipient.GetPatronymic().length()+2;
            }
        }
    }
    StreamTable st(std::cout);
    st.AddCol(a);
    st.AddCol(b);
    st.AddCol(c);
    st.AddCol(d);
    st.AddCol(e);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    bool no_any = true;

    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].sender.GetCountry() == s and Obj[i].sender.GetCity() == n and Obj[i].sender.GetHouse() == m)
        {
            st << full_address(Obj[i].recipient) << full_address(Obj[i].sender)
               << Obj[i].fio_recipient.GetSurname() << Obj[i].fio_recipient.GetName()
               << Obj[i].fio_recipient.GetPatronymic() << Obj[i].GetPrice();
            no_any= false;
        }
    }
    if (no_any)
    {
        st << "country_recipient" << "city_recipient" << "house_recipient" << "country_sender"
        << "city_sender" << "house_sender" << "surname"  << "name" << "patronymic" << "0.0";
        std::cout<<"Таких кентов тут нет"<<std::endl<<std::endl;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void SearchRecipient(letter* Obj, int amount)
{
    std::string k;

    k=CheckSurname();

    int a = Obj[0].recipient.GetCountry().length()+Obj[0].recipient.GetCity().length()+Obj[0].recipient.GetHouse().length()+28;
    int b = Obj[0].sender.GetCountry().length()+Obj[0].sender.GetCity().length()+Obj[0].sender.GetHouse().length()+28;
    int c = Obj[0].fio_recipient.GetSurname().length()+2;
    int d = Obj[0].fio_recipient.GetName().length()+2;
    int e = Obj[0].fio_recipient.GetPatronymic().length()+2;

    for (int i = 0; i < letter::count - 1; i++) {
        for (int j = i + 1; j < letter::count; j++) {
            if(Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()
               > Obj[i].recipient.GetCountry().length()+Obj[i].recipient.GetCity().length()+Obj[i].recipient.GetHouse().length()){
                a=Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()+28;
            }

            else if(Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()
                    > Obj[i].sender.GetCountry().length()+Obj[i].sender.GetCity().length()+Obj[i].sender.GetHouse().length()){
                b=Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()+28;
            }

            else if(Obj[j].fio_recipient.GetSurname().length() > Obj[i].fio_recipient.GetSurname().length()){
                c=Obj[j].fio_recipient.GetSurname().length()+2;
            }

            else if(Obj[j].fio_recipient.GetName().length() > Obj[i].fio_recipient.GetName().length()){
                d=Obj[j].fio_recipient.GetName().length()+2;
            }

            else if(Obj[j].fio_recipient.GetPatronymic().length() > Obj[i].fio_recipient.GetPatronymic().length()){
                e=Obj[j].fio_recipient.GetPatronymic().length()+2;
            }
        }
    }
    StreamTable st(std::cout);
    st.AddCol(a);
    st.AddCol(b);
    st.AddCol(c);
    st.AddCol(d);
    st.AddCol(e);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    bool no_any = true;

    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].fio_recipient.GetSurname() == k)
        {
            st << full_address(Obj[i].recipient) << full_address(Obj[i].sender)
               << Obj[i].fio_recipient.GetSurname() << Obj[i].fio_recipient.GetName()
               << Obj[i].fio_recipient.GetPatronymic() << Obj[i].GetPrice();
            no_any= false;
        }
    }
    if (no_any)
    {
        st << "country_recipient" << "city_recipient" << "house_recipient" << "country_sender"
           << "city_sender" << "house_sender" << "surname"  << "name" << "patronymic" << "0.0";
        std::cout<<"Таких кентов тут нет"<<std::endl<<std::endl;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void SortedPrice(letter* &Obj, int amount)
{
    letter tmp;

    for (int i = 0; i < amount - 1; i++)
    {
        for (int j = 0; j < amount - i - 1; j++)
        {
            if (Obj[j].GetPrice() > Obj[j + 1].GetPrice())
            {
                tmp = Obj[j];
                Obj[j] = Obj[j + 1];
                Obj[j + 1] = tmp;
            }
        }
    }

    int a = Obj[0].recipient.GetCountry().length()+Obj[0].recipient.GetCity().length()+Obj[0].recipient.GetHouse().length()+28;
    int b = Obj[0].sender.GetCountry().length()+Obj[0].sender.GetCity().length()+Obj[0].sender.GetHouse().length()+28;
    int c = Obj[0].fio_recipient.GetSurname().length()+2;
    int d = Obj[0].fio_recipient.GetName().length()+2;
    int e = Obj[0].fio_recipient.GetPatronymic().length()+2;

    for (int i = 0; i < letter::count - 1; i++) {
        for (int j = i + 1; j < letter::count; j++) {
            if(Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()
               > Obj[i].recipient.GetCountry().length()+Obj[i].recipient.GetCity().length()+Obj[i].recipient.GetHouse().length()){
                a=Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()+28;
            }

            else if(Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()
                    > Obj[i].sender.GetCountry().length()+Obj[i].sender.GetCity().length()+Obj[i].sender.GetHouse().length()){
                b=Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()+28;
            }

            else if(Obj[j].fio_recipient.GetSurname().length() > Obj[i].fio_recipient.GetSurname().length()){
                c=Obj[j].fio_recipient.GetSurname().length()+2;
            }

            else if(Obj[j].fio_recipient.GetName().length() > Obj[i].fio_recipient.GetName().length()){
                d=Obj[j].fio_recipient.GetName().length()+2;
            }

            else if(Obj[j].fio_recipient.GetPatronymic().length() > Obj[i].fio_recipient.GetPatronymic().length()){
                e=Obj[j].fio_recipient.GetPatronymic().length()+2;
            }
        }
    }
    StreamTable st(std::cout);
    st.AddCol(a);
    st.AddCol(b);
    st.AddCol(c);
    st.AddCol(d);
    st.AddCol(e);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    for (int i = 0; i < amount; i++)
        {
            st << full_address(Obj[i].recipient) << full_address(Obj[i].sender)
               << Obj[i].fio_recipient.GetSurname() << Obj[i].fio_recipient.GetName()
               << Obj[i].fio_recipient.GetPatronymic() << Obj[i].GetPrice();
        }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void SortedSender(letter* &Obj, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        for (int j = amount - 1; j > i; j--)
        {
            if (!(Obj[j].sender.GetCountry() >= Obj[j-1].sender.GetCountry()))
            {
                std::swap(Obj[j], Obj[j-1]);
            }
        }
    }

    int a = Obj[0].recipient.GetCountry().length()+Obj[0].recipient.GetCity().length()+Obj[0].recipient.GetHouse().length()+28;
    int b = Obj[0].sender.GetCountry().length()+Obj[0].sender.GetCity().length()+Obj[0].sender.GetHouse().length()+28;
    int c = Obj[0].fio_recipient.GetSurname().length()+2;
    int d = Obj[0].fio_recipient.GetName().length()+2;
    int e = Obj[0].fio_recipient.GetPatronymic().length()+2;

    for (int i = 0; i < letter::count - 1; i++) {
        for (int j = i + 1; j < letter::count; j++) {
            if(Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()
               > Obj[i].recipient.GetCountry().length()+Obj[i].recipient.GetCity().length()+Obj[i].recipient.GetHouse().length()){
                a=Obj[j].recipient.GetCountry().length()+Obj[j].recipient.GetCity().length()+Obj[j].recipient.GetHouse().length()+28;
            }

            else if(Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()
                    > Obj[i].sender.GetCountry().length()+Obj[i].sender.GetCity().length()+Obj[i].sender.GetHouse().length()){
                b=Obj[j].sender.GetCountry().length()+Obj[j].sender.GetCity().length()+Obj[j].sender.GetHouse().length()+28;
            }

            else if(Obj[j].fio_recipient.GetSurname().length() > Obj[i].fio_recipient.GetSurname().length()){
                c=Obj[j].fio_recipient.GetSurname().length()+2;
            }

            else if(Obj[j].fio_recipient.GetName().length() > Obj[i].fio_recipient.GetName().length()){
                d=Obj[j].fio_recipient.GetName().length()+2;
            }

            else if(Obj[j].fio_recipient.GetPatronymic().length() > Obj[i].fio_recipient.GetPatronymic().length()){
                e=Obj[j].fio_recipient.GetPatronymic().length()+2;
            }
        }
    }
    StreamTable st(std::cout);
    st.AddCol(a);
    st.AddCol(b);
    st.AddCol(c);
    st.AddCol(d);
    st.AddCol(e);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    for (int i = 0; i < amount; i++)
    {
        st << full_address(Obj[i].recipient) << full_address(Obj[i].sender)
           << Obj[i].fio_recipient.GetSurname() << Obj[i].fio_recipient.GetName()
           << Obj[i].fio_recipient.GetPatronymic() << Obj[i].GetPrice();
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save(letter* Obj, int amount, std::string filename)
{
    std::ofstream record(filename, std::ios::out);

    if (record)
    {
        for (int i=0; i<amount; i++)
        {
            record << Obj[i].recipient.GetCountry()<<" "<< Obj[i].recipient.GetCity()<<" "<< Obj[i].recipient.GetHouse() <<" "
            <<Obj[i].sender.GetCountry()<<" "<< Obj[i].sender.GetCity()<<" "<< Obj[i].sender.GetHouse() <<" "
            <<Obj[i].fio_recipient.GetSurname()<<" "<<Obj[i].fio_recipient.GetName()<<" "
            <<Obj[i].fio_recipient.GetPatronymic()<<" "<<Obj[i].GetPrice()<<std::endl;
        }
    }

    else
    {
        std::cout<<"Че-то не записывается(("<<std::endl;
    }
    record.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Read(letter* &Obj, int amount, std::string filename)
{
    std::ifstream myfile(filename);
    int count=0;
    char *str = new char [1024];
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile.getline(str, 1024, '\n');
            count++;
        }
        delete[] str;
    }

    amount=count-1;
    myfile.close();


    std::ifstream reading(filename);
    if (reading)
    {

        Obj = new letter[amount];

        for (int i = 0; i<amount; i++)
        {
            std::string country_recipient;
            std::string city_recipient;
            std::string house_recipient;
            std::string country_sender;
            std::string city_sender;
            std::string house_sender;
            std::string surname;
            std::string name;
            std::string patronymic;
            double price;

            reading >> country_recipient >> city_recipient >> house_recipient
            >> country_sender >> city_sender >> house_sender
            >> surname >> name >> patronymic >> price;

            Obj[i].recipient.SetCountry(country_recipient);
            Obj[i].recipient.SetCity(city_recipient);
            Obj[i].recipient.SetHouse(house_recipient);
            Obj[i].sender.SetCountry(country_sender);
            Obj[i].sender.SetCity(city_sender);
            Obj[i].sender.SetHouse(house_sender);
            Obj[i].fio_recipient.SetSurname(surname);
            Obj[i].fio_recipient.SetName(name);
            Obj[i].fio_recipient.SetPatronymic(patronymic);
            Obj[i].SetPrice(price);
        }
    }
    myfile.close();
    letter::count=amount;
    std::cout<<"Количество писем: "<<letter::count<<"\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~