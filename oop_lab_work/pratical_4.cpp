#include <iostream>
#include <fstream>

using namespace std;
int main()
{

    ofstream outfile;
    outfile.open("sample00.txt", ios::app);
    string s;

    while (1)
    {
        cout << "\n1.ENTER A LINE. \n0.EXIT" << endl;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            cin.get();
            getline(cin, s);
            outfile << s;
        }
        else if (ch == 0)
        {
            cout << "YOU ARE EXITED !!!" << endl;
            break;
        }
    }
    outfile.close();

    string g;
    ifstream infile;
    infile.open("sample00.txt", ios::in);
    while (!infile.eof())
    {
        getline(infile, g);
        cout << "FOLLOWING ARE CONTENTS OF YOUR FILE :" << endl;
        cout << s << endl;
    }

    return 0;
}
