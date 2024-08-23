#include <iostream>
using namespace std;

// returns the index of second largest
// if second largest (s) didn't exist return -1
int secLarge(int arr[], int n)
{
    int f = 0, s = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[f])
        {
            s = f;
            f = i;
        }
        else if (arr[i] < arr[f])
        {
            if (s == -1 || arr[s] < arr[i])
                s = i;
        }
    }
    return s;
}

int main()
{
    int arr[] = {10, 12, 20, 4};
    int index = secLarge(arr, sizeof(arr) / sizeof(arr[0]));
    if (index == -1)
        cout << "Second Largest didn't exist";
    else
        cout << "Second largest : " << arr[index];
}