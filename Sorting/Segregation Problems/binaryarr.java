/**
 * Sorts an input binary array using the Dutch National Flag problem algorithm,
 * which partitions the array into three sections: 0s, 1s, and 2s, and then
 * swaps
 * elements to segregate the 1s from the 0s and 2s.
 *
 * @param A An array of integers containing binary values (0s and 1s).
 * @param N The number of elements in the input array A.
 */
class Solution {

    static void binaryarr(int A[], int N) {
        // Initialize low to point to the beginning of the array
        int low = 0;
        // Initialize high to point to the end of the array
        int high = N - 1;

        // Loop until low and high pointers meet
        while (low < high) {
            // If the element at the low index is 1, swap it with the element at the high
            // index
            // and move the high pointer one step left.
            if (A[low] == 1) {
                A[low] = A[low] + A[high];
                A[high] = A[low] - A[high];
                A[low] = A[low] - A[high];
                high--;
            } else {
                // If the element at the low index is 0, move the low pointer one step right.
                low++;
            }
        }
    }
}

/*
 * Method Description:
 * This method implements the Dutch National Flag problem algorithm to sort an
 * input binary array consisting of 0s and 1s. It uses two pointers, low and
 * high, to divide the array into three sections: elements before low are 0s,
 * elements between low and high are 1s (not processed yet), and elements after
 * high are 2s. The algorithm swaps elements when A[low] is 1, segregating the
 * 1s from the 0s and 2s.
 * 
 * Parameters:
 * 
 * A[]: An array of integers representing binary values (0s and 1s).
 * N: An integer representing the number of elements in the input array A.
 * Time Complexity: The algorithm has a linear time complexity of O(N), where N
 * is the number of elements in the input array.
 * 
 * 
 */
