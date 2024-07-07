#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

// Function prototypes
int obst(int i, int j, int freq[], int sum[]);
int sum_freq(int freq[], int i, int j);

int main() {
    int n;
    
    // Input size of values
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    
    int freq[MAX_SIZE];
    int sum[MAX_SIZE + 1]; 
    int i, j;
    
    // Input keys and their frequencies
    printf("Enter the keys:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &freq[i]);
    }
    
    
    sum[0] = 0;
    for (i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + freq[i];
    }
    
    
    int min_cost = obst(1, n, freq, sum);
    
    printf("Minimum cost of optimal binary search tree is: %d\n", min_cost);
    
    return 0;
}


int obst(int i, int j, int freq[], int sum[]) {
    if (i > j) return 0;
    if (i == j) return freq[i];
    
    int min_cost = INT_MAX;
    
    for (int k = i; k <= j; k++) {
        int cost = obst(i, k - 1, freq, sum) + obst(k + 1, j, freq, sum) + sum[j] - sum[i - 1];
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    
    return min_cost;
}


int sum_freq(int freq[], int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += freq[k];
    }
    return sum;
}

