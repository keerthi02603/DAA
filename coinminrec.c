#include <stdio.h>
#include <limits.h>

int minCoinsRecursive(int denoms[], int n, int amount) {
    
    if (amount == 0) {
        return 0;
    }

    
    int result = INT_MAX;

    // Go through all denominations and recursively find the minimum number of coins
    for (int i = 0; i < n; i++) {
        if (denoms[i] <= amount) {
            int sub_res = minCoinsRecursive(denoms, n, amount - denoms[i]);
            if (sub_res != INT_MAX && sub_res + 1 < result) {
                result = sub_res + 1;
            }
        }
    }

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

    int minCoinsRequired = minCoinsRecursive(denoms, n, amount);

    if (minCoinsRequired == INT_MAX) {
        printf("Cannot make the amount %d with the given denominations.\n", amount);
    } else {
        printf("Minimum number of coins required to make %d: %d\n", amount, minCoinsRequired);
    }

    return 0;
}

