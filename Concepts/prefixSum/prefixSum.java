
/*
 * Given an array arr[] of size n, its prefix sum array is another array
 * prefixSum[]
 * of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] +
 * arr[2] … arr[i].
 * 
 * Examples :
 * 
 * Input : arr[] = {10, 20, 10, 5, 15}
 * Output : prefixSum[] = {10, 30, 40, 45, 60}
 * Explanation : While traversing the array, update the element by adding it
 * with its previous element.
 * prefixSum[0] = 10,
 * prefixSum[1] = prefixSum[0] + arr[1] = 30,
 * prefixSum[2] = prefixSum[1] + arr[2] = 40 and so on.
 */

/*
 * Given an array arr[] of size n. Given Q queries and in each query given L and
 * R, print sum of array elements from index L to R.
 * Time Complexity : O(n)
 */

import java.io.*;

class PrefixSum {
    private static void fillPrefix(int arr[], int preArray[], int n) {
        preArray[0] = arr[0];

        for (int i = 1; i < n; i++) {
            preArray[i] = preArray[i - 1] + arr[i];
        }
    }

    public static void main(String[] args) {
        int arr[] = { 3, 6, 2, 8, 9, 2 };
        int n = arr.length;

        int[] preArray = new int[n];

        fillPrefix(arr, preArray, n);

        int q = 4;
        int queries[][] = { { 2, 3 }, { 4, 6 }, { 1, 5 }, { 3, 6 } };

        for (int i = 0; i < q; i++) {
            int l = queries[i][0] - 1;
            int r = queries[i][1] - 1;

            if (l - 1 > 0) {
                System.out.print(preArray[r] - preArray[l - 1] + " ");
            } else {
                System.out.print(preArray[r] + " ");
            }

        }
    }
}