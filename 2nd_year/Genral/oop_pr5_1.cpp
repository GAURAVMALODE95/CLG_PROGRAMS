#include <iostream>
using namespace std;
template <class t>
void selection(t arr[], int size)
{
    int i, j, min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    cout<<"sorted array : ";
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    float arr[6];
    for (int i = 0; i < 6; i++)
    {
        cout << "element : ";
        cin >> arr[i];
    }
    selection<float>(arr,6);

    return 0;
}