//unbounded knapsack tabulation
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int unboundedKnapsack(int W, int weights[], int values[], int n) {
    int dp[W + 1]; 

   
    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
    }

    
    for (int i = 0; i < n; i++) {
        
        for (int j = weights[i]; j <= W; j++) {
            
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    
    return dp[W];
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

    
    int maxValue = unboundedKnapsack(W, weights, values, n);

    printf("Maximum value that can be obtained is: %d\n", maxValue);

    return 0;
}

