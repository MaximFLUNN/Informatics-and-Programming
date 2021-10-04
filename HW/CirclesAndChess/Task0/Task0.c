#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x1, y1, r1, x2, y2, r2, d, rmax, rmin;
    //input
    printf("Input circle 1 x, y, r: \n");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Input circle 2 x, y, r: \n");
    scanf("%f %f %f", &x2, &y2, &r2);
    //calculating distance
    if (r1 > r2) { rmin = r2; rmax = r1; } else { rmin = r1; rmax = r2; }
    d = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
    //calculating the cause
	if (d == (r1 + r2)) {printf("The circles touch\n");}
	if ((d < (r1 + r2)) && (d > rmax)) {printf("The circles intersect\n");}
	if (d > (r1 + r2) && (d > rmax)) {printf("Circles don't touch\n");}
	if ((d + rmin) < rmax) {printf("Circle inside other\n");}
    system("PAUSE");
    return 0;
}
//Powered MaximFLUNN (Maxim Filatov 3821b1pr2)