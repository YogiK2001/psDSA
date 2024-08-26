#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm> // For std::max
using namespace std;

class Solution
{
public:
    /**
     * This function finds the length of the longest substring without repeating characters.
     *
     * @param s The input string.
     * @return The length of the longest substring without repeating characters.
     */
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length(); // Get the length of the input string
        int maxLen = 0;       // Initialize the maximum length of substring without repeating characters
        int left = 0;         // Initialize the left pointer of the sliding window

        // Hash map to store the last index of each character
        unordered_map<char, int> charIndex;

        // Iterate over the string with the right pointer of the sliding window
        for (int r = 0; r < len; r++)
        {
            // If the character is already in the hash map and its index is within the current window
            if (charIndex.find(s[r]) != charIndex.end() && charIndex[s[r]] >= left)
            {
                // Move the left pointer to the right of the last occurrence of the current character
                left = charIndex[s[r]] + 1;
            }
            // Update the last index of the current character
            charIndex[s[r]] = r;

            // Update the maximum length of the substring
            maxLen = max(maxLen, r - left + 1);
        }
        return maxLen; // Return the maximum length of the substring
    }
};

int main()
{
    Solution solution;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "The length of the longest substring without repeating characters is " << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}