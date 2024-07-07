#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100


int matrixChainOrder(int p[], int n) {
    int dp[MAX_SIZE][MAX_SIZE];  
    
    // Single matrix chain has no cost
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // 'l' is chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }

    return dp[1][n - 1];  
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int arr[MAX_SIZE];
    printf("Enter the dimensions of the matrices sequentially:\n");
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n + 1));

    return 0;
}

