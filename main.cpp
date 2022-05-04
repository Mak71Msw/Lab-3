#include "letter_box.h"

int CheckMenu()
{
    while (true)
    {
        std::cout << "Диалоговое окно:" << std::endl;
        std::cout << "1)Показать таблицу с данными" << std::endl;
        std::cout << "2)Добавить новое письмо" << std::endl;
        std::cout << "3)Поиск письма по отправителю" << std::endl;
        std::cout << "4)Поиск письма по получателю " << std::endl;
        std::cout << "5)Сортировать по увелечению стоимости" << std::endl;
        std::cout << "6)Сортировать по алфавиту(адрес отправителя) " << std::endl;
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

int letter::count = 0;
int main()
{
    letter_box element ;
    Read(element.MyARRAY,letter::count,"OOP3.txt");
    int c;
    do {
        c=CheckMenu();
        switch (c)
        {
            case 1:
                element.Output();
                break;

            case 2:
                element.AddElement();
                break;

            case 3:
                SearchSender(element.MyARRAY,letter::count);
                break;

            case 4:
                SearchRecipient(element.MyARRAY,letter::count);
                break;

            case 5:
                SortedPrice(element.MyARRAY,letter::count);
                break;

            case 6:
                SortedSender(element.MyARRAY,letter::count);
                break;

            case 7:
                Save(element.MyARRAY,letter::count,"OOP3.txt");
                break;
        }
    } while (c != 7);
    return 0;
}