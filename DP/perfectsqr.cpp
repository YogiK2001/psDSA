#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The least number of perfect square numbers which sum to " << n << " is " << solution.numSquares(n) << endl;
    return 0;
}