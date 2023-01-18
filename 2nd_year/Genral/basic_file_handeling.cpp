// file is pattern of data which is stored in disk.
#include <iostream>
#include<fstream>
/*
reading and writing files.
we will us some classes from #include<fstream>
useful calsses are: 
1)fstreambase
2)ifstream
3)ofstream----2nd and 3rd are derived from fstreambase.

two ways to open file:
        1)using constructor
        2)using open function.
*/
using namespace std;
int main()
{
 /*   //writing in a file.
    string st="text is written in sample file";
    //opening file using constructor
    ofstream out("sample.txt");//file opened
    out<<st; */

    //reading from an file.
    string st2;
    ifstream in("sample2.txt");
   
    getline(in,st2);//used here to read a whole file. 
    cout<<st2;



    return 0;
}