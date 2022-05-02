//
// Created by Максим Уланов on 26.04.2022.
//
#pragma once

#include "letter.h"

class letter;
class fio;
class address;

class letter_box {

public:

    letter* MyARRAY;

    letter_box()
    {
        MyARRAY = new letter[0];
    }

    void AddElement()
    {
        letter* tmp;
        tmp = (letter*)std::realloc(MyARRAY, (letter::count + 1) * sizeof(letter));
        if (tmp != nullptr)
        {
            MyARRAY = tmp;
            Input(MyARRAY,letter::count);
            letter::count++;
        }
        else
        {
            std::cout << "Вопросы/Ответы по желанию"  << std::endl;
        }
    }

    void Output()
    {
        int a = MyARRAY[0].recipient.GetCountry().length()+MyARRAY[0].recipient.GetCity().length()+MyARRAY[0].recipient.GetHouse().length()+28;
        int b = MyARRAY[0].sender.GetCountry().length()+MyARRAY[0].sender.GetCity().length()+MyARRAY[0].sender.GetHouse().length()+28;
        int c = MyARRAY[0].fio_recipient.GetSurname().length()+2;
        int d = MyARRAY[0].fio_recipient.GetName().length()+2;
        int e = MyARRAY[0].fio_recipient.GetPatronymic().length()+2;

        for (int i = 0; i < letter::count - 1; i++) {
            for (int j = i + 1; j < letter::count; j++) {
                if(MyARRAY[j].recipient.GetCountry().length()+MyARRAY[j].recipient.GetCity().length()+MyARRAY[j].recipient.GetHouse().length()
                > MyARRAY[i].recipient.GetCountry().length()+MyARRAY[i].recipient.GetCity().length()+MyARRAY[i].recipient.GetHouse().length()){
                    a=MyARRAY[j].recipient.GetCountry().length()+MyARRAY[j].recipient.GetCity().length()+MyARRAY[j].recipient.GetHouse().length()+28;
                }

                else if(MyARRAY[j].sender.GetCountry().length()+MyARRAY[j].sender.GetCity().length()+MyARRAY[j].sender.GetHouse().length()
                        > MyARRAY[i].sender.GetCountry().length()+MyARRAY[i].sender.GetCity().length()+MyARRAY[i].sender.GetHouse().length()){
                    b=MyARRAY[j].sender.GetCountry().length()+MyARRAY[j].sender.GetCity().length()+MyARRAY[j].sender.GetHouse().length()+28;
                }

                else if(MyARRAY[j].fio_recipient.GetSurname().length() > MyARRAY[i].fio_recipient.GetSurname().length()){
                    c=MyARRAY[j].fio_recipient.GetSurname().length()+2;
                }

                else if(MyARRAY[j].fio_recipient.GetName().length() > MyARRAY[i].fio_recipient.GetName().length()){
                    d=MyARRAY[j].fio_recipient.GetName().length()+2;
                }

                else if(MyARRAY[j].fio_recipient.GetPatronymic().length() > MyARRAY[i].fio_recipient.GetPatronymic().length()){
                    e=MyARRAY[j].fio_recipient.GetPatronymic().length()+2;
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

        st << "Address Recipient" << "Address Sender" << "Surname" << "Name" << "Patronymic" << "Price";
        for (int i = 0; i < letter::count; i++)
        {
            st << full_address(MyARRAY[i].recipient) << full_address(MyARRAY[i].sender)
               << MyARRAY[i].fio_recipient.GetSurname() << MyARRAY[i].fio_recipient.GetName()
               << MyARRAY[i].fio_recipient.GetPatronymic() << MyARRAY[i].GetPrice();
        }
    }
};