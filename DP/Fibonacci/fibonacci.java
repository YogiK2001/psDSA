package DP.Fibonacci;

/*
 * Here we use 2 Approach of Dynamic Programming to calculate the nth Fibonacci function in the most efficient way.
 * 1. Memoization (Top-down)
 * 2. Tabulation (Bottom-Up)
 */

/* Java program for Memoized version */
public class fibonacci {
    final int MAX = 100;
    final int NIL = -1;

    int lookup[] = new int[MAX];

    /* Function to initialize NIL values in lookup table */
    void _initialize() {
        for (int i = 0; i < MAX; i++)
            lookup[i] = NIL;
    }

    /* Function for nth Fibonacci number */
    int fib(int n) {
        if (lookup[n] == NIL) {
            if (n <= 1)
                lookup[n] = n;
            else
                lookup[n] = fib(n - 1) + fib(n - 2);
        }

        return lookup[n];
    }

    // Driver Code
    public static void main(String[] args) {
        fibonacci f = new fibonacci();
        int n = 40;
        f._initialize();
        System.out.println("Fibonacci number is" + " " + f.fib(n));
    }
}

// 2. Tabulation (Bottom-Up)

/* Java program for Tabulated version */

public class fibonacci2 {

    int fib(int n) {
        int f[] = new int[n + 1];
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; i++)
            f[i] = f[i - 1] + f[i - 2];

        return f[n];
    }

    public static void main(String[] args) {
        fibonacci f = new fibonacci();
        int n = 9;
        System.out.println("Fibonacci number is" + " " + f.fib(n));
    }
}
