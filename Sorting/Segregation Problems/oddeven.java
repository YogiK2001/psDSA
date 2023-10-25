// package Sorting.Segregation Problems;

public class oddeven {

    static void segregate(int arr[], int N) {
        // Your code goes here
        int low = 0;
        int high = N - 1;
        while (low < high) {
            if (arr[low] % 2 == 0) {
                low++;
            } else {
                int temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
                high--;
            }
        }
    }
}
