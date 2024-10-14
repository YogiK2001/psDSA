// Excellent insight! You've grasped the core concept of the algorithm. Let's refine your understanding:

// You're absolutely right that we're essentially calculating the sum of logarithms (base 10) of numbers from 1 to N.
// Starting with a count of 1 is a good approach, as it accounts for log10(1), which is 0.
// By adding log10 of each number, we're effectively finding the logarithm of their product (remember the logarithm rule: log(a*b) = log(a) + log(b)).

// Now, let's think about why this works:

// If we have a number x, the number of digits in x is floor(log10(x)) + 1.
// For a factorial N!, we're looking for floor(log10(N!)) + 1.
// Using the logarithm rule: log10(N!) = log10(1) + log10(2) + ... + log10(N)

class Solution
{
public:
    int digitsInFactorial(int N)
    {
        // code here
        double res = 1;
        for (int i = 2; i <= N; i++)
        {
            res = res + log10(i);
        }
        return floor(res);
    }
};