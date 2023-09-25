// package Sorting.Quick Sort.Partitions.Dutch National Flag;

/*
You can solve this problem by using a modified version of the Dutch National Flag algorithm, 
which is used to partition an array into three parts based on a given range [a, b]. 
Here's one way to perform this partition:

Initialize three pointers: low, mid, and high.

low points to the current position where elements less than a should be placed.
mid points to the current position where elements within the range [a, b] should be placed.
high points to the current position where elements greater than b should be placed.
Traverse the array from left to right using a loop until mid crosses high. You can use a for loop or a while loop.

For each element arr[i]:

If arr[i] is less than a, swap it with the element at the low pointer, and increment both low and mid pointers.
If arr[i] is between a and b, increment only the mid pointer to keep it in the correct range.
If arr[i] is greater than b, swap it with the element at the high pointer and decrement the high pointer.
Continue this process until mid crosses high.

At the end of the process, you'll have partitioned the array into three parts as required. 
*/

public class dutch {
    class Solution {
        // Function to swap two elements in the array.
        private void swap(int[] array, int i, int j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        // Function to partition the array around the range such
        // that the array is divided into three parts.
        public void threeWayPartition(int array[], int a, int b) {
            int low = 0, mid = 0, high = array.length - 1;

            while (mid <= high) {
                if (array[mid] < a) {
                    swap(array, low, mid);
                    low++;
                    mid++;
                } else if (array[mid] >= a && array[mid] <= b) {
                    mid++;
                } else if (array[mid] > b) {
                    swap(array, mid, high);
                    high--;
                }
            }
        }
    }

}
