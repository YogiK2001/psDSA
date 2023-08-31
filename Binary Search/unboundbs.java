// Searching a Target in a Infinite Sorted Array and returning its index

// import java.util.*;
// import java.io.*;
// import java.lang.*;

class GFG {
    static int bSearch(int arr[], int low, int high, int x) {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            return bSearch(arr, low, mid - 1, x);

        else
            return bSearch(arr, mid + 1, high, x);
    }

    static int search(int arr[], int x) {
        if (arr[0] == x)
            return 0;

        int i = 1;

        while (arr[i] < x)
            i = i * 2;

        if (arr[i] == x)
            return i;

        return bSearch(arr, i / 2 + 1, i - 1, x);
    }

    public static void main(String args[]) {

        int arr[] = { 1, 2, 3, 40, 50 };

        int x = 4;

        System.out.println(search(arr, x));

    }

}

/*
 * Working of the above code:
 * The method search takes in an array arr[] and an integer x as parameters. The
 * array is the data set in which we are searching, and x is the value we are
 * looking for.
 * 
 * If the first element of the array is equal to x, the method returns 0,
 * indicating that the element was found at the first position of the array.
 * 
 * If x is not the first element, the method initializes a counter i at 1 and
 * enters a while loop. This loop continues to double i as long as the ith
 * element of the array is less than x. This is a form of exponential search
 * where we are trying to find a range in which x might exist.
 * 
 * After the loop, if the ith element of the array is equal to x, the method
 * returns i, indicating the position of x in the array.
 * 
 * If x is not equal to the ith element, the method calls a binary search
 * function bSearch on a subarray from i/2 + 1 to i - 1. This is because we know
 * that x must be in this range if it exists in the array. The binary search
 * function will return the index of x in the array if it exists, or -1 if it
 * does not.
 * 
 * 
 */
