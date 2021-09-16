#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>


int main()
{
    int h, a, r;
    float triangle, rectangle, circle;
    // triangle
    printf("Triangle\n");
    printf("input height: ");
    scanf("%d", &h);
    printf("input base: ");
    scanf("%d", &a);
    triangle = h * a * 0.5;
    printf("Square triangle: %f", triangle);
    //rectangle
    printf("\nRectangle\n");
    printf("input height: ");
    scanf("%d", &h);
    printf("input base: ");
    scanf("%d", &a);
    rectangle = h * a;
    printf("Square rectangle: %f", rectangle);
    //circle
    printf("\nCircle\n");
    printf("input radius: ");
    scanf("%d", &r);
    circle = (r * r * M_PI);
    printf("Circle rectangle: %f", circle);
    scanf("%d", &r);
    return 0;
}
