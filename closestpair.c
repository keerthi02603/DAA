#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    Point p1, p2;
    int index1, index2;

    
    printf("Enter coordinates of first point (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);

   
    printf("Enter coordinates of second point (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);

   
    index1 = 1; 
    index2 = 2; 

    
    double dist = distance(p1, p2);

   
    printf("Distance between (%.2lf, %.2lf) (index %d) and (%.2lf, %.2lf) (index %d) is: %.6lf\n",
           p1.x, p1.y, index1, p2.x, p2.y, index2, dist);

    return 0;
}

