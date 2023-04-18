#include<iostream>
using namespace std;

void bubbleSort(int * arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                cout << "前=" <<arr[j] << endl;
                cout << "前=" << arr[j + 1] << endl;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                cout << "后=" << arr[j] << endl;
                cout << "后=" << arr[j + 1] << endl;
            }
        }
    }
}

void printArray(int * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[10] = {4, 3 ,2, 1, 6, 7, 5, 8, 9, 10};

    int len = sizeof(arr) / sizeof(arr[0]); 

    bubbleSort(arr, len);

    printArray(arr, len);

    return 0;
}