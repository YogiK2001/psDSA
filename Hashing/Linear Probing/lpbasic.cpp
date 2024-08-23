#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        vector<int> result(hashSize, -1);

        for (int i = 0; i < sizeOfArray; i++)
        {
            int hashed = arr[i] % hashSize;

            if (result[hashed] == -1)
            {
                result[hashed] = arr[i];
            }
            else
            {
                int probe = 1;
                int index = (hashed + probe) % hashSize;

                // Continue probing until an empty slot is found
                while (result[index] != -1 && probe < hashSize)
                {
                    probe++;
                    index = (hashed + probe) % hashSize;
                }

                // If an empty slot is found, insert the value
                if (probe < hashSize)
                {
                    result[index] = arr[i];
                }
                // Otherwise, the hash table is full
                else
                {
                    break; // Exit the loop if the hash table is full
                }
            }
        }

        return result;
    }
};
