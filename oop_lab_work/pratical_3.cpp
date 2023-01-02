#include <iostream>
using namespace std;
class publication
{

private:
    string title;
    float price;

public:
    void set_data()
    {
        cout << "\n ENTER THE PUBLICATION DETAILS :" << endl;
        cout << "\n ENTER THE TITLE OF PUBLICATION :" << endl;
        cin.ignore();
        getline(cin, title);
        cout << "ENTER THE PRICE OF PUBLICATION" << endl;
        cin >> price;
    }

    void get_data()
    {
        cout << "\n THE TITLE OF PUBLICATION IS :" << title;
        cout << "\n PRICE OF PUBLICATION IS : " << price;
    }
};

class book : public publication
{
private:
    int page_count;

public:
    void add_book()
    {
        try
        {
            set_data();
            cout << "ENTER PAGE COUNT OF BOOK : " << endl;
            cin >> page_count;
            if (page_count <= 0)
            {
                throw page_count;
            }
        }
        catch (...)
        {
            cout << "/n INVALID PAGE!" << endl;
            page_count = 0;
        }
    }
    void display_book()
    {
        get_data();
        cout << page_count;
    }
};

class tape : public publication
{
private:
    float min;

public:
    void add_min()
    {
        try
        {
            set_data();
            cout << "ENTER TIME IN MINUTES : " << endl;
            cin >> min;
            if (min <= 0)
            {
                throw min;
            }
        }
        catch (...)
        {
            cout << "\n invalid play time ! " << endl;
            min = 0;
        }
    }
    void display_tape()
    {
        get_data();
        cout << "PLAY TIME IS : " << min << endl;
    }
};
int main()
{
    book b1[5];
    tape t1[5];
    int decision, tape_count = 0, book_count = 0;

    do
    {

        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Add Information to Books";
        cout << "\n2. Add Information to Tapes";
        cout << "\n3. Display Books Information";
        cout << "\n4. Display Tapes Information";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> decision;

        switch (decision)
        {
        case 1:
            b1[book_count].add_book();
            book_count++;
            break;

        case 2:
            t1[tape_count].add_min();
            tape_count++;
            break;

        case 3:
            cout << "\n BOOK PUBLICATION DATABASE SYSTEM";
            for (int j = 0; j < book_count; j++)
            {
                b1[j].display_book();
            }
            break;

        case 4:
            cout << "\n TAPE PUBLICATION DATABASE SYSTEM";
            for (int j = 0; j < tape_count; j++)
            {
                t1[j].display_tape();
            }
            break;
        case 5:
            exit(0);
        }
    } while (decision != 3);
    return 0;
}
