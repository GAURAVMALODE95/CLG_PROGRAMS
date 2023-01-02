#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    typedef map<string, int> maptype;
    maptype populationmap;
    populationmap.insert(pair<string, int>("maharastra", 12312412));
    populationmap.insert(pair<string, int>("goa", 5432524));
    populationmap.insert(pair<string, int>("kerla", 6523326));
    populationmap.insert(pair<string, int>("delhi", 63326));
    populationmap.insert(pair<string, int>("punjab", 23434));

    maptype::iterator it;
    string ch;
    char ch1;

    do
    {
        cout << "enter the state name : " << endl;
        cin >> ch;
        it = populationmap.find(ch);
        if (it != populationmap.end())
        {
            cout << ch << "s population is  : " << it->second << endl;
        }
        else
        {
            cout << "state not present in map " << endl;
        }

        cout << "\nwant to continew?(y/n)" << endl;
        cin >> ch1;
    } while (ch1 != 'n');

    return 0;
}
