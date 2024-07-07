#include <stdio.h>
#include<string.h>

int coinChange(int coins[], int numCoins, int amount) {
  
    int table[amount + 1];
    
    memset(table, 0, sizeof(table));

    
    table[0] = 1;

   
    for (int i = 0; i < numCoins; i++)
        for (int j = coins[i]; j <= amount; j++)
            table[j] += table[j - coins[i]];

    return table[amount];
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

    int ways = coinChange(coins, numCoins, amount);
    printf("Number of ways to make change: %d\n", ways);

    return 0;
}

