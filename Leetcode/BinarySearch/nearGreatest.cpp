// LeetCode: 744. Find Smallest Letter Greater Than Target

#include <iostream>
#include <vector>
class nearGreatest
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        // TLE Solution (Normal Binary Search)
        // int left = 0;
        //    int right = letters.size()-1;
        //    int mid;
        //    while(left <= right)
        //    {
        //        mid = (left+right)/2;
        //        if(letters[mid] <= left)
        //        {
        //            left = mid + 1;
        //        }
        //        else
        //        {
        //            right = mid + 1;
        //        }
        //    }
        //     return left == letters.size() ? letters[0] : letters[left];
        // }

        // The Linear Search takes less time than the Binary Search :) Justt Leeetcode things

        // Brute Force Solution
        for (char letter : letters)
        {
            if (letter > target)
            {
                return letter;
            }
        }
        return letters[0];

        // Simple For Loop
        // for (int i = 0; i < letters.size(); i++)
        // {
        //     if (letters[i] > target)
        //         return letters[i];
        // }
        // return letters[0]

        /*
       The range-based for loop offers a more concise and readable syntax,
       especially when you need to iterate over all elements in a container
       without explicitly working with iterators or indices.
       It can simplify the code and make it easier to understand.

       On the other hand, the traditional for loop provides more flexibility
       and control, allowing you to access elements using indices and perform
       more complex iterations, such as iterating in reverse or skipping elements
       based on certain conditions. It can be useful in situations where you
       need more fine-grained control over the iteration process.
       */

        // Upper Bound Solution
    }
};