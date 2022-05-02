//
// Created by Максим Уланов on 26.04.2022.
//

#include "letter.h"

double CheckPrice()
{
    while (true)
    {
        std::cout << "Стоимость письма: ";
        double a;
        std::cin >> a;

        if (std::cin.fail() or (a < 0))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
        }
        else
            return a;
    }
}

std::string CheckCountry()
{
    int i;
    std::string str;
    do{
        std::cout<<"Страна: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!')
               or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[')
               or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if(str[i]) {
            std::cout << "Нужно вводить буквы!" << std::endl << "Повторите ввод!!!" << std::endl;
        }

    }while(str[i]);

    return str;
}

std::string CheckCity()
{
    int i;
    std::string str;
    do{
        std::cout<<"Город: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!')
               or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[')
               or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if(str[i]) {
            std::cout << "Нужно вводить буквы!" << std::endl << "Повторите ввод!!!" << std::endl;
        }

    }while(str[i]);

    return str;
}

std::string CheckHouse()
{
    int i;
    std::string str;
    do{
        std::cout<<"Дом/Корпус: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':')
            or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if(str[i]) {
            std::cout << "Вот пример ввода:" << std::endl << "1111d" << std::endl << "Повторите ввод!!!" << std::endl;
        }

    }while(str[i]);

    return str;
}

std::string CheckSurname()
{
    int i;
    std::string str;
    do{
        std::cout<<"Фамилия: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!')
               or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[')
               or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if(str[i]) {
            std::cout << "Нужно вводить буквы!" << std::endl << "Повторите ввод!!!" << std::endl;
        }

    }while(str[i]);

    return str;
}

std::string CheckName()
{
    int i;
    std::string str;
    do{
        std::cout<<"Имя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!')
               or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[')
               or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if(str[i]) {
            std::cout << "Нужно вводить буквы!" << std::endl << "Повторите ввод!!!" << std::endl;
        }

    }while(str[i]);

    return str;
}

std::string CheckPatronymic()
{
    int i;
    std::string str;
    do{
        std::cout<<"Отчество: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!')
            or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[')
            or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if(str[i]) {
            std::cout << "Нужно вводить буквы!" << std::endl << "Повторите ввод!!!" << std::endl;
        }
    }while(str[i]);

    return str;
}

int CheckMenu()
{
    while (true)
    {
        std::cout << "Диалоговое окно:" << std::endl;
        std::cout << "1)Показать таблицу с данными" << std::endl;
        std::cout << "2)Добавить новое письмо" << std::endl;
        std::cout << "3)Поиск письма по отправителю" << std::endl;
        std::cout << "4)Поиск письма по получателю через перегрузку ==" << std::endl;
        std::cout << "5)Сортировать по увелечению стоимости" << std::endl;
        std::cout << "6)Сортировать по алфавиту(адрес отправителя) через перегрузку!" << std::endl;
        std::cout << "7)Сохранить и выйти" << std::endl;
        std::cout << "Введите число от 1 до 7" << std::endl;
        int c;
        std::cin >> c;

        if (std::cin.fail() or (c < 1) or (c > 7))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
        }
        else
            return c;
    }
}