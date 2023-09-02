// Normal Fibonacci using Recursion
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

/*
The problem with above approach is that it does a lot of repeated work. The problem is that the recursive tree
of the above solution is exponential (2^n). It can be easily seen by drawing a recursion tree.
*/

// Instead of doing repeated work, store the Fibonacci numbers calculated so far. (Dynamic Programming)

int fib2(int n)
{
    // Declare an array to store Fibonacci numbers
    int f[n + 2]; // 1 extra to handle case, n = 0
    int i;

    // 0th and 1st number of the series are 0 and 1
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        // Add the previous 2 numbers in the series
        // and store it
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

// Time Complexity is linear O(n) and space complexity is O(n)