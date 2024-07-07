
//unbounded knapsack recursion

#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int unboundedKnapsack(int W, int weights[], int values[], int n) {
    
    if (W == 0 || n == 0) {
        return 0;
    }

    
    
    if (weights[n - 1] > W) {
        return unboundedKnapsack(W, weights, values, n - 1);
    }


    return max(values[n - 1] + unboundedKnapsack(W - weights[n - 1], weights, values, n),
               unboundedKnapsack(W, weights, values, n - 1));
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

