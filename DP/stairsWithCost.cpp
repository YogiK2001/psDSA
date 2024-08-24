#include <iostream>
#include <vector>
#include <algorithm> // For std::min
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            int op1 = dp[i - 1] + cost[i - 1];
            int op2 = dp[i - 2] + cost[i - 2];
            dp[i] = min(op1, op2);
        }

        return dp[n];
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    vector<int> cost(n);
    cout << "Enter the cost for each step: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> cost[i];
    }
    cout << "The minimum cost to climb the stairs is " << solution.minCostClimbingStairs(cost) << endl;
    return 0;
}