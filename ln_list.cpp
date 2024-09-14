#include <iostream>
using namespace std;


int main()
{
    //sorting algorithm
    int arr[] = {1, 7, 10, 4, 5, 6, 2, 8, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}