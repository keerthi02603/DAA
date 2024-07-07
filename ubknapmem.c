
//unbounded knapsack memorization
#include <stdio.h>


#define MAX_N 1000
#define MAX_W 1000


int memo[MAX_N + 1][MAX_W + 1];


int max(int a, int b) {
    return (a > b) ? a : b;
}


int unboundedKnapsack(int W, int weights[], int values[], int n) {
    
    if (W == 0 || n == 0) {
        return 0;
    }

    
    if (memo[n][W] != -1) {
        return memo[n][W];
    }

    // If the weight of the current item exceeds the capacity W,
    // then this item cannot be included in the optimal solution
    if (weights[n - 1] > W) {
        memo[n][W] = unboundedKnapsack(W, weights, values, n - 1);
    } else {
        // Return the maximum of two cases:
        // 1. Including the current item and recursively computing the remaining capacity
        // 2. Excluding the current item and recursively computing the remaining items
        memo[n][W] = max(values[n - 1] + unboundedKnapsack(W - weights[n - 1], weights, values, n),
                         unboundedKnapsack(W, weights, values, n - 1));
    }

    // Return the computed value
    return memo[n][W];
}

int main() {
    int n, W;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    // Input weights of items
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &weights[i]);
    }

    // Input values of items
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &values[i]);
    }

    // Input knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    // Initialize memoization table with -1 (indicating no computations done yet)
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            memo[i][j] = -1;
        }
    }

    // Compute maximum value using memoized recursive function
    int maxValue = unboundedKnapsack(W, weights, values, n);

    printf("Maximum value that can be obtained is: %d\n", maxValue);

    return 0;
}

