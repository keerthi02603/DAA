#include <stdio.h>

#define MAX 100
int memo[MAX]; 

void initialize() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }
}

int fibonacci(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 1) {
        return memo[n] = n;
    }
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    initialize(); 
    printf("Enter the value of n to find the nth Fibonacci number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    return 0;
}
