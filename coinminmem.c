#include <stdio.h>
#include <limits.h>

#define MAX_AMOUNT 1000 

int memo[MAX_AMOUNT + 1];

int minCoinsMemo(int denoms[], int n, int amount) {
    
    if (amount == 0) {
        return 0;
    }

    
    if (memo[amount] != -1) {
        return memo[amount];
    }

   
    int result = INT_MAX;

   
    for (int i = 0; i < n; i++) {
        if (denoms[i] <= amount) {
            int sub_res = minCoinsMemo(denoms, n, amount - denoms[i]);
            if (sub_res != INT_MAX && sub_res + 1 < result) {
                result = sub_res + 1;
            }
        }
    }

    // Memoize the result
    memo[amount] = result;

    return result;
}

int main() {
    int n;

    printf("Enter the number of denominations: ");
    scanf("%d", &n);

    int denoms[n];

    printf("Enter %d denominations: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &denoms[i]);
    }

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Initialize memoization table
    for (int i = 0; i <= amount; i++) {
        memo[i] = -1; 
    }

    int minCoinsRequired = minCoinsMemo(denoms, n, amount);

    if (minCoinsRequired == INT_MAX) {
        printf("Cannot make the amount %d with the given denominations.\n", amount);
    } else {
        printf("Minimum number of coins required to make %d: %d\n", amount, minCoinsRequired);
    }

    return 0;
}

