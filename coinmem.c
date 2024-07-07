#include <stdio.h>


#define MAX_COINS 100

int memo[MAX_COINS][1000]; 


int coinChange(int coins[], int numCoins, int amount) {
    
    if (amount == 0)
        return 1;

    
    if (amount < 0)
        return 0;

    
    if (numCoins <= 0 && amount >= 1)
        return 0;

    
    if (memo[numCoins][amount] != -1)
        return memo[numCoins][amount];

  
    memo[numCoins][amount] = coinChange(coins, numCoins - 1, amount) + coinChange(coins, numCoins, amount - coins[numCoins - 1]);
    return memo[numCoins][amount];
}

int main() {
    int amount, numCoins;
    
    printf("Enter the amount: ");
    scanf("%d", &amount);
    
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);
    
    int coins[numCoins];
    
    printf("Enter the coin denominations:\n");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    // Initialize memoization table with -1
    for (int i = 0; i <= numCoins; i++) {
        for (int j = 0; j <= amount; j++) {
            memo[i][j] = -1;
        }
    }

    int ways = coinChange(coins, numCoins, amount);
    printf("Number of ways to make change: %d\n", ways);

    return 0;
}

