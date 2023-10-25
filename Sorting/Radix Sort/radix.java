import java.util.*;
import java.lang.*;
import java.io.*;

/**
 * This class implements the Radix Sort algorithm to sort an array of integers
 * in ascending order.
 * The radix sort algorithm sorts the elements by first grouping the individual
 * digits of the same place value.
 * Then, the elements are sorted based on the value of digits from least
 * significant digit to most significant digit.
 * 
 * The main method initializes an integer array with some values, calls the
 * radixsort method to sort the array,
 * and then prints the sorted array.
 * 
 * The countingSort method is a helper method that performs the counting sort
 * algorithm on the given array based on
 * the given exponent value. It uses the count array to store the frequency of
 * each digit in the array, and then
 * modifies the count array to store the position of each digit in the output
 * array. Finally, it copies the elements
 * from the output array to the input array.
 * 
 * The radixsort method initializes the maximum value of the array, and then
 * calls the countingSort method for each
 * digit position from least significant to most significant. It uses the
 * maximum value to determine the number of
 * digits in the maximum value, and then uses the exponent value to extract the
 * digits from the elements in the array.
 */
class radix {
    public static void main(String[] args) {
        int arr[] = { 319, 212, 6, 8, 100, 50 };
        int n = arr.length;
        radixsort(arr, n);

        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");

    }

    static void countingSort(int arr[], int n, int exp) {
        int[] output = new int[n];
        int[] count = new int[10];
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }

    public static void radixsort(int arr[], int n) {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];

        for (int exp = 1; mx / exp > 0; exp *= 10)
            countingSort(arr, n, exp);
    }
}
