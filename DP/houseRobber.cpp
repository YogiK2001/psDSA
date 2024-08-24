#include <iostream>
#include <vector>
#include <algorithm> // For std::max
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the amount of money in each house: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "The maximum amount of money that can be robbed is " << solution.rob(nums) << endl;
    return 0;
}