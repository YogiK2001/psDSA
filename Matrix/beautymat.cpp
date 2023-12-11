#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief The Solution class contains a function to find the minimum number of operations required to make a matrix beautiful.
 *
 * Given a square matrix of size N x N, where N is an odd number, the task is to find the minimum number of operations required to make the matrix beautiful.
 * A matrix is considered beautiful if the sum of elements in each row and each column is the same.
 * An operation involves adding or subtracting a number from an element of the matrix.
 *
 * @tparam T The type of elements in the matrix.
 */
class Solution
{
public:
    /**
     * @brief Function to find the minimum number of operations required to make the matrix beautiful.
     *
     * @param matrix The input matrix.
     * @param n The size of the matrix.
     * @return int The minimum number of operations required.
     */
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        // Calculate the sum of elements in each row and each column
        vector<int> rowSum(n, 0);
        vector<int> colSum(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }

        // Find the maximum sum among row sums and column sums
        int targetSum = 0;
        for (int i = 0; i < n; i++)
        {
            targetSum = max(targetSum, max(rowSum[i], colSum[i]));
        }

        // Calculate the number of operations required to make each row and each column sum equal to the target sum
        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            operations += abs(targetSum - rowSum[i]);
            operations += abs(targetSum - colSum[i]);
        }

        return operations / 2; // Each operation is counted twice (once for row and once for column)
    }
};
