#include <iostream>
using namespace std;
template <class t>
void selection_sort(t a[], int n)
{
    t temp;
    int i = 0, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    cout << "your array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "<<endl;
    }
}
int main()
{
    int ch,size;
    int a[20];
    float b[20];
    do
    {
        cout << "*******welcome sir*******" << endl;
        cout << "\n1.integer sorting\n2.float sorting\n3.exit" << endl;
        cout << "enter your choice : ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                    cout<<"you choose integer sorting!!\nhow much numbers do you want to enter ?"<<endl;
                    cin>>size;
                    for(int i=0;i<size;i++){
                        cout<<"enter element : "<<endl;
                        cin>>a[i];
                    }
                    selection_sort<int>(a,size);
                    break;

            case 2:
                    cout<<"you choose float sorting!!\nhow much numbers do you want to enter ?"<<endl;
                    cin>>size;
                    for(int i=0;i<size;i++){
                        cout<<"enter element : "<<endl;
                        cin>>b[i];
                    }
                    selection_sort<float>(b,size);
                    break;

            case 3:
                    break;
        }
    } while (ch != 3);

    return 0;
}
