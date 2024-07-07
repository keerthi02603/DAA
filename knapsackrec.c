#include <stdio.h>

#define MAX_ITEMS 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
   
    if (W == 0 || n == 0)
        return 0;

    
    if (weights[n - 1] > W)
        return knapsack(W, weights, values, n - 1);

    
    else
        return max(values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1),
                   knapsack(W, weights, values, n - 1));
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[MAX_ITEMS], values[MAX_ITEMS];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum value in the knapsack: %d\n", knapsack(W, weights, values, n));

    return 0;
}
