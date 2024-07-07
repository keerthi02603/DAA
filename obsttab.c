
#include<stdio.h>
#include<stdlib.h> 
#include<limits.h>
int obst(int n, int freq[]);

int main() {
    int n, i;

    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int freq[n];

    
    printf("Enter the frequency values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    
    int min_cost = obst(n, freq);

    printf("Minimum cost of optimal binary search tree is: %d\n", min_cost);

    return 0;
}


int obst(int n, int freq[]) {
    int dp[n][n];
    int sum[n + 1]; 
    int i, j, l, k;

    
    sum[0] = 0;
    for (i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + freq[i - 1];
    }

    
    for (i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }

    
    for (l = 2; l <= n; l++) { 
        for (i = 0; i <= n - l; i++) {
            j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k <= j; k++) {
                int cost = ((k > i) ? dp[i][k - 1] : 0) +
                           ((k < j) ? dp[k + 1][j] : 0) +
                           sum[j + 1] - sum[i];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

