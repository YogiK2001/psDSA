#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &A, int B)
    {
        int n = A.size();

        // Step 1: Compute the prefix XOR array
        vector<int> prefix_xor(n, 0);
        prefix_xor[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            prefix_xor[i] = prefix_xor[i - 1] ^ A[i];
        }

        // Step 2: Use a hashmap to store the frequency of prefix XOR values
        unordered_map<int, int> mp;
        int count = 0;

        // Step 3: Traverse the prefix XOR array
        for (int i : prefix_xor)
        {
            // Calculate the XOR needed to form the subarray with XOR equal to B
            int xor_needed = B ^ i;

            // If the needed XOR is found in the map, add its frequency to the count
            if (mp.find(xor_needed) != mp.end())
            {
                count += mp[xor_needed];
            }

            // If the current prefix XOR itself is equal to B, increment the count
            if (i == B)
            {
                count++;
            }

            // Increment the frequency of the current prefix XOR in the map
            mp[i]++;
        }

        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> A = {4, 2, 2, 6, 4}; // Example input
    int B = 6;                       // Example input
    cout << "Number of subarrays with XOR equal to " << B << " is " << solution.solve(A, B) << endl;
    return 0;
}