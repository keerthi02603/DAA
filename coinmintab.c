#include <stdio.h>
#include <limits.h>


int minCoinsTabulation(int denoms[], int n, int amount) {
    
    int dp[amount + 1];

   
    dp[0] = 0;

    
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    
    for (int i = 1; i <= amount; i++) {
        
        for (int j = 0; j < n; j++) {
            if (denoms[j] <= i) {
                int sub_res = dp[i - denoms[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    
    return dp[amount];
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

    int minCoinsRequired = minCoinsTabulation(denoms, n, amount);

    if (minCoinsRequired == INT_MAX) {
        printf("Cannot make the amount %d with the given denominations.\n", amount);
    } else {
        printf("Minimum number of coins required to make %d: %d\n", amount, minCoinsRequired);
    }

    return 0;
}

