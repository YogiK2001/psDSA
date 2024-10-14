// # Longest Common Prefix Algorithm Explanation

// This algorithm finds the longest common prefix shared by all strings in an array. Here's how it works:

// ## Algorithm Overview

// 1. Assume the first string is the longest common prefix.
// 2. Compare this prefix with each subsequent string, shortening it as necessary.
// 3. If the prefix becomes empty at any point, return an empty string.
// 4. After comparing with all strings, return the final prefix.

// ## Detailed Breakdown

var longestCommonPrefix = function (strs) {
    let pref = strs[0];
    let prefLen = pref.length;

    for (let i = 1; i < strs.length; i++) {
        let s = strs[i];
        while (pref !== s.substring(0, prefLen)) {
            prefLen--;
            if (prefLen === 0) {
                return "";
            }
            pref = pref.substring(0, prefLen);
        }
    }
    return pref;
};
// ```

// ### Step 1: Initialize
// - `pref` is set to the first string in the array (`strs[0]`).
// - `prefLen` is set to the length of this first string.

// ### Step 2: Iterate Through Strings
// - The loop starts from the second string (`i = 1`) and goes through all strings.

// ### Step 3: Compare and Adjust
// - For each string `s`:
//   - Compare `pref` with the substring of `s` of length `prefLen`.
//   - If they're not equal, enter a while loop:
//     - Decrease `prefLen` by 1.
//     - If `prefLen` becomes 0, return an empty string (no common prefix).
//     - Shorten `pref` to the new length.
//   - Repeat until `pref` matches the start of `s`.

// ### Step 4: Return Result
// - After comparing with all strings, return the final `pref`.

// ## Example

// Let's walk through an example:

// ```javascript
// strs = ["flower", "flow", "flight"]
// ```

// 1. Initialize: `pref = "flower"`, `prefLen = 6`
// 2. Compare with "flow":
//    - "flower" ≠ "flow", so enter while loop
//    - Shorten to "flowe", then "flow"
//    - "flow" = "flow", exit while loop
// 3. Compare with "flight":
//    - "flow" ≠ "flig", so enter while loop
//    - Shorten to "flo", then "fl"
//    - "fl" = "fl", exit while loop
// 4. Return "fl" as the longest common prefix

// This algorithm efficiently finds the longest common prefix by making a single pass through the array and adjusting the prefix as needed.