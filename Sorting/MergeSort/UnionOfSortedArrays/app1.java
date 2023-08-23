package Sorting.MergeSort.UnionOfSortedArrays;

// 
import java.util.ArrayList;

public class app1 {
    // Function to return a list containing the union of the two arrays.

    /* Approach 1: Time Limit Exceeded */
    public static ArrayList<Integer> findUnion1(int arr1[], int arr2[], int n, int m) {
        // add your code here
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (i > 0 && arr1[i] == arr1[i - 1]) {
                i++;
                continue;
            } else if (arr1[i] > arr2[j]) {
                arr.add(arr2[j]);
                j++;
            } else if (arr1[i] < arr2[j]) {
                arr.add(arr1[i]);
                i++;
            } else {
                arr.add(arr1[i]);
                i++;
                j++;
            }
        }
        while (i < n) {
            if (i > 0 && arr1[i] != arr1[i - 1]) // Wrong Condition: Its not checking for the first element
                arr.add(arr1[i]);
        }
        while (j < m) {
            if (j > 0 && arr2[j] != arr2[j - 1]) // Wrong Condition: Its not checking for the first element
                arr.add(arr2[j]);
        }
        if (arr.isEmpty()) {
            arr.add(-1);
        }
        return arr;

        // Failed Testcase:
        // 1 19
        // 4
        // 6 6 17 17 24 30 30 33 37 38 38 39 40 44 46 47 48 50 50

        // Expected Output:
        // 4 6 17 24 30 33 37 38 39 40 44 46 47 48 50
        // My Output
        // 4 17 24 30 33 37 38 39 40 44 46 47 48 50
    }

    // Approach 2: Working Solution
    public static ArrayList<Integer> findUnion2(int arr1[], int arr2[], int n, int m) {
        // add your code here
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (i > 0 && arr1[i] == arr1[i - 1]) {
                i++;
                continue;
            }
            if (j > 0 && arr2[j] == arr2[j - 1]) {
                j++;
                continue;
            } else if (arr1[i] > arr2[j]) {
                arr.add(arr2[j]);
                j++;
            } else if (arr1[i] < arr2[j]) {
                arr.add(arr1[i]);
                i++;
            } else {
                arr.add(arr1[i]);
                i++;
                j++;
            }
        }
        while (i < n) {
            if (i == 0 || arr1[i] != arr1[i - 1]) {
                arr.add(arr1[i]);
            }
            i++;

        }
        while (j < m) {
            if (j == 0 || arr2[j] != arr2[j - 1]) {
                arr.add(arr2[j]);
            }
            j++;
        }
        if (arr.isEmpty()) {
            arr.add(-1);
        }
        return arr;
    }
}
