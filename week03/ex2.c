#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double distance(struct Point a, struct Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b. y)*(a.y - b.y));
}

double area(struct Point a, struct Point b, struct Point c){
    return (a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y) / 2;
}

int main() {
    struct Point A, B, C;
    A.x = 2.5;
    A.y = 6;
    B.x = 1;
    B.y = 2.2;
    C.x = 10;
    C.y = 6;
    double s = area(A, B, C), d = distance(A, B);
    printf("Distance AB : %f\nArea of ABC : %f\n", d, s);
}