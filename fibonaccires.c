#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the value of n to find the nth Fibonacci number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    return 0;
}
