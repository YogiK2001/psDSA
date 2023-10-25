#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Segregates positive and negative integers in an input array.
 * It places all negative integers before positive integers in the array.
 *
 * @param arr An array of integers containing positive and negative values.
 * @param n The number of elements in the input array arr.
 */
void segregation(int arr[], int n)
{
    // Initialize two pointers, i and j.
    int i = 0, j = n - 1;

    // Continue until the two pointers meet or cross each other.
    while (i < j)
    {
        // Move the pointer i to the right until a positive integer is found.
        while (arr[i] < 0)
            i++;

        // Move the pointer j to the left until a negative integer is found.
        while (arr[j] >= 0)
            j--;

        // If i is less than j, swap the elements at positions i and j.
        if (i < j)
            swap(arr[i], arr[j]);
    }
}

/*
Method Description:
This function segregates positive and negative integers in an input array arr
by placing all negative integers before positive integers. It uses two pointers,
i and j, initialized to the start and end of the array, respectively. The function
continues until the i pointer is less than the j pointer. While traversing the
array, it finds a positive integer from the left side and a negative integer
from the right side. If i is less than j, it swaps the elements at positions i and j,
effectively placing negative integers before positive integers in the array.

Parameters:

arr[]: An array of integers containing both positive and negative values.
n: An integer representing the number of elements in the input array arr.
Time Complexity: The time complexity of this function is O(n),
where n is the number of elements in the input array.
The function processes each element of the array once, making it a linear time algorithm.
*/

int main()
{
}
