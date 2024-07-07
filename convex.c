#include <stdio.h>

typedef struct {
    int x, y;
} Point;

// Function to compute the cross product of vectors p1p2 and p2p3
int crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

// Function to check if points i and j are on the convex hull
int onConvexHull(Point p[], int n, int i, int j) {
    int np = 0, nn = 0;
    int a = p[j].y - p[i].y;
    int b = p[i].x - p[j].x;
    int c = p[i].x * p[j].y - p[j].x * p[i].y;

    for (int k = 0; k < n; k++) {
        int val = a * p[k].x + b * p[k].y - c;
        if (val > 0)
            np++;
        else if (val < 0)
            nn++;
    }

    // If np or nn is 0, all points lie on one side of the line segment
    if (np == 0 || nn == 0)
        return 1; // Points i and j are on the convex hull
    else
        return 0; // Points i and j are not on the convex hull
}

// Function to find and print convex hull edges
void findConvexHull(Point p[], int n) {
    printf("Convex Hull Edges:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (onConvexHull(p, n, i, j))
                printf("(%d, %d) to (%d, %d)\n", p[i].x, p[i].y, p[j].x, p[j].y);
        }
    }
}

// Example usage
int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[n];
    printf("Enter the points (format: x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    findConvexHull(points, n);

    return 0;
}

