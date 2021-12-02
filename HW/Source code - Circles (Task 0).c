/*
| Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
|      GitHub profile link: https://github.com/MaximFLUNN      |
| [ENG] Task: Determine what is the relative position of two circles with given coordinates and radii |
| [RU] Task: Определить, каково взаимное расположение двух окружностей с заданными координатами центров и радиусами |
*/

#define _CRT_SECURE_NO_WARNINGS // [ENG] Disable warnings | [RU] Отключение предупреждений
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main() 
{
    // | [ENG] Variables | [RU] Переменные |
    double x1, y1, r1, x2, y2, r2, d, rmax, rmin; 

    // | [ENG] Input sizes | [RU] Введение размеров |
    printf("Input circle 1 x, y, r: \n");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Input circle 2 x, y, r: \n");
    scanf("%f %f %f", &x2, &y2, &r2);

    // | [ENG] Calculating distance | [RU] Расчёт дистанции |
    if (r1 > r2) { rmin = r2; rmax = r1; }
    else { rmin = r1; rmax = r2; }
    d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    
    // | [ENG] Calculating the cause | [RU] Определение результата |
    if (d == (r1 + r2)) { printf("The circles touch\n"); }
    if ((d < (r1 + r2)) && (d > rmax)) { printf("The circles intersect\n"); }
    if (d > (r1 + r2) && (d > rmax)) { printf("Circles don't touch\n"); }
    if ((d + rmin) < rmax) { printf("Circle inside other\n"); }
    system("PAUSE");
    return 0;
}
