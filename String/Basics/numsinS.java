class Solution {
    // Function to calculate sum of all numbers present in a string.
    public static long findSum(String str) {
        int k = 0, i = 0;
        String s = "";
        int[] arr = new int[str.length()];
        while (i < str.length()) {
            while (i < str.length() && Character.isDigit(str.charAt(i))) {
                s += str.charAt(i);
                i++;
            }
            if (!s.isEmpty()) {
                arr[k] = Integer.parseInt(s);
                k++;
                s = "";
            } else {
                i++;
            }
        }
        long sum = 0;
        for (int j = 0; j < k; j++) {
            sum += arr[j];
        }
        return sum;
    }
}