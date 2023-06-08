/*Majority element is an element that appears more than n/2 times in an array of size n. */

// import java.util.*;
// import java.io.*;
// import java.lang.*;

public class mva {

    // Moore Voting Algo
    // Time Complexity: O(n)
    static int findMajority(int arr[], int n) {
        int res = 0, count = 1;
        // find a candidate
        for (int i = 1; i < n; i++) {
            if (arr[res] == arr[i])
                count++;
            else
                count--;

            if (count == 0) {
                res = i;
                count = 1;
            }
        }

        /*
         * The for loop iterates through the array from index 1 to n-1 to
         * find the candidate majority element. It compares the element at the current
         * index with
         * the element at index res (the current candidate). If they are equal, the
         * count is incremented;
         * otherwise, it is decremented. If the count becomes 0, it means the previous
         * candidate
         * is no longer valid, so a new candidate is chosen, and res and count are
         * updated accordingly.
         */

        count = 0;
        // check if the candidate is actually a majority element
        for (int i = 0; i < n; i++)
            if (arr[res] == arr[i])
                count++;

        if (count <= n / 2)
            res = -1;

        return res;
    }

    public static void main(String args[]) {
        int arr[] = { 8, 8, 6, 6, 6, 4, 6 }, n = 7;

        System.out.println(findMajority(arr, n));

    }

}

// Naive Approach
// Time Complexity: O(n^2)
/*
 * Use two loops to find the maxCount if arr[i] = arr[j]
 * and print arr[index] if maxCount > n/2
 */