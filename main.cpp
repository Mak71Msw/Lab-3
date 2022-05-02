#include "letter.h"
#include "letter_box.h"
#include "check.cpp"

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