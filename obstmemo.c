#include <stdio.h>
#include <stdlib.h>// for INT_MAX
#include<limits.h>
#define MAX_SIZE 100

int obst(int i, int j, int flag[], int sum[][MAX_SIZE + 1], int a[][MAX_SIZE]);
int sum_freq(int flag[], int i, int j);

int main() {
    int n, i, j;

    // Input number of nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    int flag[MAX_SIZE];
    int a[MAX_SIZE][MAX_SIZE]; // frequency matrix

    // Input frequencies
    printf("Enter the frequency values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Initialize flag array (assuming flags for each node)
    printf("Enter the flags:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &flag[i]);
    }

    // Initialize sum array
    int sum[MAX_SIZE][MAX_SIZE + 1] = {0};

    // Calculate cumulative sums
    for (i = 0; i < n; i++) {
        sum[i][i] = a[i][i];
        for (j = i + 1; j < n; j++) {
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    }

    // Calculate minimum cost of optimal BST using memoization
    int min_cost = obst(0, n - 1, flag, sum, a);

    printf("Minimum cost of optimal binary search tree is: %d\n", min_cost);

    return 0;
}

// Recursive function with memoization to calculate minimum cost of OBST
int obst(int i, int j, int flag[], int sum[][MAX_SIZE + 1], int a[][MAX_SIZE]) {
    static int memo[MAX_SIZE][MAX_SIZE];

    if (i > j) return 0;
    if (i == j) return a[i][i]; // or flag[i], depends on your logic

    if (memo[i][j] != 0) return memo[i][j];

    int min_cost = INT_MAX; // Declare min_cost here

    for (int k = i; k <= j; k++) {
        int cost = obst(i, k - 1, flag, sum, a) + obst(k + 1, j, flag, sum, a) + sum_freq(flag, i, j);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }

    return memo[i][j] = min_cost;
}

// Helper function to calculate sum of frequencies from index i to j
int sum_freq(int flag[], int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += flag[k];
    }
    return sum;
}

