// Two Pointer Approach
// Find the Sum of two elements equal to the target in a Sorted Array
// Leetcode Problem: 167. Two Sum II - Input Array Is Sorted


class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] arr = new int[2];
        int i = 0 , j = numbers.length-1;
        while(i<=j)
        {
            if((numbers[i] + numbers[j]) == target)
            {
                arr[0] = i+1;
                arr[1] = j+1;
                return arr;
            }
            else if((numbers[i] + numbers[j]) > target)
            {
                j--;
            }
            else 
                i++;
        }
        return arr;
    }
}
