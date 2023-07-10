// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
class sortrotated {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
}

// Working of the above code:
/*
 * Here we check in which half of the array the target lies. If the target lies
 * in the first half of the array, we update the end to mid-1, else we update
 * the start to mid+1. plus we also check if the array is sorted or not. If the
 * array is sorted, we simply apply binary search on the array. If the array is
 * not sorted, we check if the target lies in the first half of the array or the
 * second half. If the target lies in the first half of the array, we update the
 * end to mid-1, else we update the start to mid+1.
 */