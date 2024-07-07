#include <stdio.h>
#include <limits.h>


int matrixChainOrder(int dims[], int n) {
    
    int memo[n][n];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }

 
    int mcm(int i, int j) {
        
        if (memo[i][j] != -1)
            return memo[i][j];

        
        if (i == j)
            return memo[i][j] = 0;

        int min = INT_MAX;

        
        for (int k = i; k < j; k++) {
            int cost = mcm(i, k) + mcm(k + 1, j) + dims[i - 1] * dims[k] * dims[j];
            if (cost < min)
                min = cost;
        }

        
        return memo[i][j] = min;
    }

    
    return mcm(1, n - 1);
}

int main() {
    int n; 
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dims[n + 1]; 
    printf("Enter the dimensions of matrices (separated by spaces):\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dims[i]);
    }

   
    int minMultiplications = matrixChainOrder(dims, n + 1);

    printf("Minimum number of scalar multiplications needed: %d\n", minMultiplications);

    return 0;
}

