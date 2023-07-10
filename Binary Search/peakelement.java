/* https://leetcode.com/problems/find-peak-element/ 
 * Time Complexity: O(logn)
*/

public class peakelement {
    public int findPeakElement(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // Checking the corner cases
            if ((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == nums.length - 1 || nums[mid + 1] <= nums[mid]))
                return mid;
            if (mid > 0 && nums[mid - 1] >= nums[mid])
                /*
                 * If the element on the left of mid is greater than mid, then the peak element
                 * lies on the left side of the mid. (Interesting to note)
                 */
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
}
