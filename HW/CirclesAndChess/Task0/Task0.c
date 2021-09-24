#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x1, y1, r1, x2, y2, r2, d, t, u1, u2;
    t = 0.01;
    printf("Input circle 1 x, y, r: \n");
    scanf("%f %f %f", &x1, &y1, &r1);
    //printf("%f %f %f", x1, y1, r1);
    printf("Input circle 2 x, y, r: \n");
    scanf("%f %f %f", &x2, &y2, &r2);
    d = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
    if ((d > (r1 + r2)) && (r1 + d > r2) && (r2 + d > r1))
        printf("Circles are separated\n");
    else
        if ((r1 + r2 == d) || (abs(r1 - r2) == d))
            printf("Circles touch\n");
        else
            printf("Circles not touch");
    system("PAUSE");

    return 0;
}
/*
if (d > (r1 + r2))
    {
        printf("Circles are separated\n");
    }
    if (fabs(d - (r1 + r2)) < t)
    {
        printf("Circles touch\n");
    }
    if (d < r1 + r2)
    {
        if (d > r1 - r2)
        {
            printf("Circles intersect\n");
        }
        else
        {
            printf("Circles inside\n");
        }
    }
*/