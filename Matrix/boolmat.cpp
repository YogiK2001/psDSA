/*Given a boolean matrix of size RxC where each cell contains
either 0 or 1, modify it such that if a matrix cell matrix[i][j]
is 1 then all the cells in its ith row and jth column will become 1.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        // code here
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> rowFlag(rows, false);
        vector<bool> colFlag(cols, false);

        // Step 1: Mark rows and columns that need to be set to 1
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 1)
                {
                    rowFlag[i] = true;
                    colFlag[j] = true;
                }
            }
        }

        // Step 2: Modify the matrix based on the marked rows and columns
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (rowFlag[i] || colFlag[j])
                {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};