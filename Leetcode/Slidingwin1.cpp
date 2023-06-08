// Leetcode Problem: 239. Sliding Window Maximum
//  Case Failed : [...] k = 50K Time Limit Exceeded

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
class Solution
{
public:
    int findMaxElement(const std::vector<int> &vec)
    {
        // Using std::max_element to find the maximum element in the vector

        auto maxElement = std::max_element(vec.begin(), vec.end());
        // Checking if the vector is empty

        if (maxElement == vec.end())
        {
            throw std::runtime_error("Vector is empty.");
        }

        // Returning the maximum element
        return *maxElement;
    }

    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        std::vector<int> outP;
        std::vector<int> maxWin;

        for (int i = 0; i < k; i++)
        {
            maxWin.push_back(nums[i]);
        }
        int maxE = findMaxElement(maxWin);
        outP.push_back(maxE);

        for (int i = k; i < nums.size(); i++)
        {
            maxWin.erase(maxWin.begin()); // iter1
            /*I wrote maxWin.erase(nums.begin()); which caused OutOfBounds Error*/
            maxWin.push_back(nums.at(i)); // iter2
            /*I wrote  maxWin.push_back(nums[i]);
            In the line maxWin.push_back(nums[i]); within the first loop, you are directly accessing nums[i]
            and pushing it into maxWin. However, since nums is a reference to the original vector,
            you should use nums.at(i) instead to access elements.
            The corrected line should be maxWin.push_back(nums.at(i));
            */
            maxE = findMaxElement(maxWin);
            outP.push_back(maxE);
        }
        // for(int i = 0; i < outP.size(); i++)
        // {
        //     cout << outP[i];
        // }
        return outP;
    }
};

// Second Attempt: Using Deque Cpp STL

#include <vector>
#include <deque>

class Solution2
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        std::vector<int> result;
        std::deque<int> window;

        for (int i = 0; i < nums.size(); i++)
        {
            // Remove elements that are outside the window
            if (!window.empty() && window.front() <= i - k)
                window.pop_front();

            // Remove elements smaller than the current element from the back of the window
            while (!window.empty() && nums[window.back()] < nums[i])
                window.pop_back();

            window.push_back(i);

            // Process the window when it reaches the required size
            if (i >= k - 1)
                result.push_back(nums[window.front()]);
        }

        return result;
    }
};
