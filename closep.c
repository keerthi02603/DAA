#include <stdio.h>
#include <math.h>
#include <limits.h>

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to calculate the squared distance between two points
int squaredDistance(struct Point p1, struct Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Function to find the closest pair of points and their distance
void closestPair(struct Point p[], int n) {
    int minDist = INT_MAX;
    int index1 = -1, index2 = -1;

    // Iterate through all pairs of points
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = squaredDistance(p[i], p[j]);
            if (dist < minDist) {
                minDist = dist;
                index1 = i;
                index2 = j;
            }
        }
    }

    // Output the closest pair and their distance
    if (index1 != -1 && index2 != -1) {
        printf("Closest pair is (%d, %d) and (%d, %d)\n", p[index1].x, p[index1].y, p[index2].x, p[index2].y);
        printf("Distance between them is %.2f\n", sqrt((double)minDist));
    } else {
        printf("No valid pairs found.\n");
    }
}

int main() {
    struct Point p[10]; // Assuming maximum 10 points
    int n;

    printf("Enter the number of points (max 10): ");
    scanf("%d", &n);

    printf("Enter the points (format: x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    closestPair(p, n);

    return 0;
}

