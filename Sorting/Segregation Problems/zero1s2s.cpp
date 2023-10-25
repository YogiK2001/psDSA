#include <iostream>
using namespace std;

/**
 * Segregates an array of integers containing 0s, 1s, and 2s,
 * arranging 0s first, then 1s, and finally 2s in the array.
 *
 * @param arr An array of integers containing 0s, 1s, and 2s.
 * @param N The number of elements in the input array arr.
 */
void segragate012(int arr[], int N)
{
    // Initialize three pointers: low, mid, and high.
    int low = 0, mid = 0, high = N - 1;

    // Continue until the mid pointer is less than or equal to the high pointer.
    while (mid <= high)
    {
        // If the element at mid is 0, swap it with the element at low,
        // increment both low and mid pointers.
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        // If the element at mid is 1, move the mid pointer to the next element.
        else if (arr[mid] == 1)
        {
            mid++;
        }
        // If the element at mid is 2, swap it with the element at high,
        // decrement the high pointer.
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

/*
Method Description:
This function segregates an array of integers containing 0s, 1s, and 2s.
It uses three pointers: low, mid, and high. The function iterates through the array,
and if the element at mid is 0, it swaps it with the element at low and increments
both low and mid pointers. If the element at mid is 1, the mid pointer is moved to the next element.
If the element at mid is 2, it swaps it with the element at high and decrements the high pointer.
This process continues until the mid pointer is less than or equal to the high pointer,
effectively segregating 0s, 1s, and 2s in the array.

Parameters:

arr[]: An array of integers containing 0s, 1s, and 2s.
N: An integer representing the number of elements in the input array arr.
Time Complexity: The time complexity of this function is O(N),
where N is the number of elements in the input array.
The function processes each element of the array once, making it a linear time algorithm.
*/