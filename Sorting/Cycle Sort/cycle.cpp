/*
Cycle Sort With Duplicates:

Cycle Sort is an in-place, non-comparison-based sorting algorithm. It works by selecting an element
from the array and placing it in its correct position, then repeating the process for the next element
until the entire array is sorted. This implementation of Cycle Sort handles duplicate elements as well,
ensuring both uniqueness and in-place ordering.

Description of Implementation:
1. The function cycleSortWithDups takes an array of integers and its size as input.
2. It iterates through the array from the first element to the second last element.
3. For each element, it finds the correct position for it by counting the number of elements smaller than it.
4. If the element is already in the correct position, it moves to the next element.
5. If the element has duplicates, it ensures the in-place property by finding the correct position for each duplicate.
6. It swaps the current element with the element at its correct position.
7. It then rotates the rest of the cycle until the current element is back at its initial position.
8. The sorted array is printed to the console.

Note: Cycle Sort is not the most efficient sorting algorithm for general use cases,
but it has advantages in specific situations, especially when minimizing writes to memory is a concern.

Author: ChatGPT
*/

#include <iostream>
#include <algorithm>

// Function to perform Cycle Sort with handling duplicates
int cycleSortWithDups(int arr[], int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }

        // Skip if the element is already in the correct position
        if (pos == cs)
        {
            continue;
        }

        // Handle duplicates by finding the correct position for each duplicate element
        while (item == arr[pos])
        {
            pos++;
        }

        // Swap the current element with the element at its correct position
        std::swap(item, arr[pos]);

        // Rotate the rest of the cycle until the current element is back at its initial position
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }

            while (item == arr[pos])
            {
                pos++;
            }

            std::swap(item, arr[pos]);
        }
    }
    return 0;
}

int main()
{
    int arr[] = {20, 10, 20, 40, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform Cycle Sort on the array with handling duplicates
    cycleSortWithDups(arr, n);

    // Print the sorted array
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
