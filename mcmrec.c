#include <stdio.h>
#include <limits.h>


int matrixChainOrder(int dims[], int i, int j) {
    if (i == j) 
        return 0;

    int minCost = INT_MAX;

    
    for (int k = i; k < j; k++) {
        int cost = matrixChainOrder(dims, i, k) + 
                   matrixChainOrder(dims, k + 1, j) + 
                   dims[i-1] * dims[k] * dims[j];

        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
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

    
    int minMultiplications = matrixChainOrder(dims, 1, n);

    printf("Minimum number of scalar multiplications needed: %d\n", minMultiplications);

    return 0;
}

