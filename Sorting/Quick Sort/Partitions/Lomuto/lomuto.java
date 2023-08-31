/**
 * Lomuto Partition Algorithm
 *
 * This algorithm is used to partition an array around a chosen pivot element,
 * such that all elements less than or equal to the pivot are on its left side,
 * and all elements greater than the pivot are on its right side.
 *
 * @param arr The array to be partitioned.
 * @param l   The index of the left boundary of the partition.
 * @param h   The index of the right boundary of the partition.
 * @return The index of the pivot element after partitioning.
 */

public class lomuto {
    public static void main(String[] args) {
        int[] arr = { 8, 4, 7, 9, 3, 10, 5 };
        int n = arr.length;
        int p = 0;
        int r = n - 1;
        int q = lomutoPartition(arr, p, r);
        System.out.println(q);
    }

    public static int lomutoPartition(int[] arr, int l, int h) {
        // Select the pivot element from the rightmost position
        int pivot = arr[h];

        // Initialize the index of the smaller element
        int i = l - 1;

        // Iterate through the array to partition it
        for (int j = l; j < h; j++) {
            if (arr[j] <= pivot) {
                // If the current element is smaller than or equal to the pivot,
                // increment the index of the smaller element and swap arr[i] and arr[j]
                i++;
                swap(arr, i, j);
            }
        }

        // Swap the pivot element to its correct position
        swap(arr, i + 1, h);

        // Return the index of the pivot element after partitioning
        return i + 1;
    }

    public static void swap(int[] arr, int i, int j) {
        if (i == j)
            return;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)

/*
 * Practical Use Cases:
 * 
 * The Lomuto partition algorithm is an essential component of quicksort, one of
 * the most efficient sorting algorithms. By using Lomuto partition, quicksort
 * divides an array into smaller subarrays and sorts them recursively, resulting
 * in a well-ordered array. It's widely used in various applications where
 * sorting is needed, such as:
 * 
 * Sorting Algorithms: As mentioned, the Lomuto partition is a core part of the
 * quicksort algorithm, which is frequently used for sorting large datasets
 * efficiently.
 * 
 * Order Statistics: The partitioning can be utilized to find the k-th smallest
 * or largest element in an array.
 * 
 * Data Analysis: In various statistical analyses, you might need to sort data
 * to find medians or quartiles.
 * 
 * Duplicate Detection: It can be used to detect duplicate elements in an array.
 * 
 * Binary Search: Some binary search algorithms utilize a sorted array, and
 * quicksort aids in achieving that sorted order.
 * 
 * Load Balancing: In load balancing algorithms, partitioning data efficiently
 * is crucial, and quicksort can help.
 * 
 */