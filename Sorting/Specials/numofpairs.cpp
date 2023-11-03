#include <iostream>
#include <algorithm>
using namespace std;

class Solution
/**
 * @class Solution
 * @brief A class that counts the number of pairs such that x^y is greater than y^x.
 */
{
public:
    /**
     * @brief A function that counts the number of pairs such that x^y is greater than y^x.
     * @param X[] An array of integers
     * @param Y[] An array of integers
     * @param M The size of array X[]
     * @param N The size of array Y[]
     * @return The number of pairs such that x^y is greater than y^x.
     *
     * This function takes two arrays X[] and Y[] as input and their sizes M and N respectively.
     * It counts the number of pairs such that x^y is greater than y^x.
     * It first sorts the array Y[] in ascending order.
     * Then it takes count of occurances of 1, 2, 3 and 4 in array Y[].
     * It then handles the exceptions and counts the number of pairs such that x^y is greater than y^x.
     * Finally, it returns the count of such pairs.
     */
    long long countPairs(int X[], int Y[], int M, int N)
    {
        long long count = 0;
        sort(Y, Y + N);
        int count1 = 0, count2 = 0, count3 = 0, count4 = 0; // taking count of 1,2,3,4's occurances
        for (int i = 0; i < N; i++)
        {
            if (Y[i] > 4)
                break;

            if (Y[i] == 1)
                count1++;
            else if (Y[i] == 2)
                count2++;
            else if (Y[i] == 3)
                count3++;
            else if (Y[i] == 4)
                count4++;
        }
        for (int i = 0; i < M; i++) // Now handle the exceptions
        {
            if (X[i] == 0) // handling exceptions
                continue;
            else if (X[i] == 1) // handling exceptions
            {
                for (int j = 0; j < N; j++)
                {
                    if (Y[j] == 0)
                        count++;
                    else
                        break;
                }
            }
            else
            {
                int j = upper_bound(Y, Y + N, X[i]) - Y; // it gives the index of element just grater than X[i] or N if no such element is not present

                if (j != N)
                    count += N - j;

                if (X[i] == 2) // handling exceptions
                    count = count - count3 - count4;

                if (X[i] == 3) // handling exceptions
                    count = count + count2;

                count += count1; // handling exceptions
            }
        }
        return count;
    }
};

// Concept: https://www.youtube.com/watch?v=CafQe7sfdfY