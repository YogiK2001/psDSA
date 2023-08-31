/**
 * Hoare's Partition Algorithm
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

public class hoores {

    public static void main(String[] args) {
        int[] arr = { 8, 4, 7, 9, 3, 10, 5 };
        int n = arr.length;
        int p = 0;
        int r = n - 1;
        int q = partition(arr, p, r);
        System.out.println(q);
    }

    public static int partition(int arr[], int l, int h) {
        int pivot = arr[l]; // Select the pivot element from the leftmost position

        int i = l - 1;
        int j = h + 1;

        while (true) {
            // Increment i until arr[i] is not less than pivot
            do {
                i++;
            } while (arr[i] < pivot);

            // Decrement j until arr[j] is not greater than pivot
            do {
                j--;
            } while (arr[j] > pivot);

            // If i and j cross each other, the partitioning is complete
            if (i >= j)
                return j;

            // Swap arr[i] and arr[j] to maintain the partition
            swap(arr, i, j);
        }
    }

    public static void swap(int[] arr, int i, int j) {
        if (i == j)
            return;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*
 * Practical Use Cases:
 * 
 * Hoare's partition algorithm is commonly used in various scenarios similar to
 * Lomuto's partition. Here are some of its practical use cases:
 * 
 * Quicksort: Hoare's partition algorithm is used as a key component of the
 * quicksort algorithm, one of the fastest sorting algorithms.
 * 
 * Order Statistics: Just like Lomuto's partition, it can be used to find the
 * k-th smallest or largest element in an array.
 * 
 * Data Analysis: In statistical analyses and data processing, sorting is often
 * required to identify medians and quartiles.
 * 
 * Binary Search: Some binary search algorithms work with sorted arrays, and
 * quicksort, using Hoare's partition, can help achieve this sorted order.
 * 
 * Load Balancing: In load balancing algorithms, efficient data partitioning is
 * crucial, and quicksort's partitioning strategy can be employed.
 * 
 * Duplicate Detection: Similar to Lomuto's partition, it can be used to detect
 * duplicate elements.
 * 
 */