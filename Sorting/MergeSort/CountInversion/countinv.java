// Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

package Sorting.MergeSort.CountInversion;

public class countinv {
    static long countMerge(long arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        long left[] = new long[n1];
        long right[] = new long[n2];
        for (int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++) {
            right[i] = arr[m + 1 + i];
        }
        long res = 0;
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
                res = res + (n1 - i); // Explained Below

            }
            k++;
        }
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
        return res;
    }

    static long countInv(long arr[], int l, int r) {

        long res = 0;
        if (l < r) {
            int m = l + (r - l) / 2;
            res += countInv(arr, l, m);
            res += countInv(arr, m + 1, r);
            res += countMerge(arr, l, m, r);
        }
        return res;
    }

    static long inversionCount(long arr[], long N) {
        return countInv(arr, 0, (int) N - 1); // Corrected index range
    }
}

// Time Complexity: O(nlogn)
/*
 * Code Summary:
 * This Java code defines a class Solution with methods to count the number of
 * inversions in an array using the merge sort algorithm. An inversion occurs
 * when a pair of elements in the array is out of their natural order. The
 * countMerge method combines two sorted subarrays while counting the
 * inversions. The countInv method recursively divides the array and calculates
 * inversions using the merge process. The inversionCount method initializes the
 * counting process by calling countInv. The code ensures correct array index
 * handling to avoid errors during array manipulation.
 */
// ------------------------------------------------------------------------------
// Explanation of the line: res = res + (n1 - i);
/*
 * In the given code, the statement `res = res + (n1 - i);` is used to count
 * inversions during the merging of two sorted subarrays. Inversions occur when
 * an element from the right subarray is smaller than an element from the left
 * subarray, indicating that the elements are out of their natural order.
 * 
 * Here's the logic behind this statement:
 * 
 * 1. `res`: This variable holds the running count of inversions.
 * 
 * 2. `n1`: It represents the length of the left subarray.
 * 
 * 3. `i`: This variable is used to iterate through the elements of the left
 * subarray.
 * 
 * When merging the sorted subarrays, if an element from the right subarray
 * (`right[j]`) is less than an element from the left subarray (`left[i]`), then
 * it implies that there are `(n1 - i)` elements in the left subarray that are
 * greater than `right[j]`, causing `(n1 - i)` inversions.
 * 
 * Adding `(n1 - i)` to the running count `res` updates the inversion count for
 * the current merge operation. This step ensures that the inversions are
 * accurately counted as the merging progresses.
 */