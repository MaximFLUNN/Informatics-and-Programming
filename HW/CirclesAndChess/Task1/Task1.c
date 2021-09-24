#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
// Powered by Maximka (MaximFLUNN)
int main()
{
    int x1, x2, y1, y2, n, n1, n2, n3, n4, n5;
    printf("Select chess(1-King,2-Elephant,\n3-Rook,4-Queen,5-Hourse): \n");
    scanf("%d", &n);
    printf("Inpunt position K1(x, y): \n");
    scanf("%d %d", &x1, &y1);
    printf("Inpunt position K2(x, y): \n");
    scanf("%d %d", &x2, &y2);
    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    n5 = 0;
    // n1 King
    if (x1 == x2 && y1 == y2 || x1 == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && y1 == y2 || x1 == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && y1 == y2 || (x1 - 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 - 1) == y2)
    {
        n1 = 1;
    }
    else 
    {
        n1 = 0;
    }
    // n2 Elephant
    if ((x1 - 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && (y1 - 1) == y2 || (x1 + 1) == x2 && (y1 + 1) == y2 || (x1 + 2) == x2 && (y1 + 2) == y2 || (x1 + 3) == x2 && (y1 + 3) == y2 || (x1 + 4) == x2 && (y1 + 4) == y2 || (x1 + 5) == x2 && (y1 + 5) == y2 || (x1 + 6) == x2 && (y1 + 6) == y2 || (x1 + 7) == x2 && (y1 + 7) == y2 || (x1 + 8) == x2 && (y1 + 8) == y2 || (x1 + 2) == x2 && (y1 - 2) == y2 || (x1 + 3) == x2 && (y1 - 3) == y2 || (x1 + 4) == x2 && (y1 - 4) == y2 || (x1 + 5) == x2 && (y1 - 5) == y2 || (x1 + 6) == x2 && (y1 - 6) == y2 || (x1 + 7) == x2 && (y1 - 7) == y2 || (x1 + 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 - 2) == y2 || (x1 - 3) == x2 && (y1 - 3) == y2 || (x1 - 4) == x2 && (y1 - 4) == y2 || (x1 - 5) == x2 && (y1 - 5) == y2 || (x1 - 6) == x2 && (y1 - 6) == y2 || (x1 - 7) == x2 && (y1 - 7) == y2 || (x1 - 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 + 2) == y2 || (x1 - 3) == x2 && (y1 + 3) == y2 || (x1 - 4) == x2 && (y1 + 4) == y2 || (x1 - 5) == x2 && (y1 + 5) == y2 || (x1 - 6) == x2 && (y1 + 6) == y2 || (x1 - 7) == x2 && (y1 + 7) == y2 || (x1 - 8) == x2 && (y1 + 8) == y2)
    {
        n2 = 1;
    }
    else
    {
        n2 = 0;
    }
    // n3 Rook
    if (x1 == x2 && y1 < y2 || x1 == x2 && y1 > y2 || x1 > x2 && y1 == y2 || x1 < x2 && y1 == y2)
    {
        n3 = 1;
    }
    else
    {
        n3 = 0;
    }
    // n4 Queen
    if (x1 == x2 && y1 == y2 || x1 == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && y1 == y2 || x1 == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && y1 == y2 || (x1 - 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 - 1) == y2 || x1 == x2 && y1 < y2 || x1 == x2 && y1 > y2 || x1 > x2 && y1 == y2 || x1 < x2 && y1 == y2 || (x1 + 2) == x2 && (y1 + 2) == y2 || (x1 + 3) == x2 && (y1 + 3) == y2 || (x1 + 4) == x2 && (y1 + 4) == y2 || (x1 + 5) == x2 && (y1 + 5) == y2 || (x1 + 6) == x2 && (y1 + 6) == y2 || (x1 + 7) == x2 && (y1 + 7) == y2 || (x1 + 8) == x2 && (y1 + 8) == y2 || (x1 + 2) == x2 && (y1 - 2) == y2 || (x1 + 3) == x2 && (y1 - 3) == y2 || (x1 + 4) == x2 && (y1 - 4) == y2 || (x1 + 5) == x2 && (y1 - 5) == y2 || (x1 + 6) == x2 && (y1 - 6) == y2 || (x1 + 7) == x2 && (y1 - 7) == y2 || (x1 + 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 - 2) == y2 || (x1 - 3) == x2 && (y1 - 3) == y2 || (x1 - 4) == x2 && (y1 - 4) == y2 || (x1 - 5) == x2 && (y1 - 5) == y2 || (x1 - 6) == x2 && (y1 - 6) == y2 || (x1 - 7) == x2 && (y1 - 7) == y2 || (x1 - 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 + 2) == y2 || (x1 - 3) == x2 && (y1 + 3) == y2 || (x1 - 4) == x2 && (y1 + 4) == y2 || (x1 - 5) == x2 && (y1 + 5) == y2 || (x1 - 6) == x2 && (y1 + 6) == y2 || (x1 - 7) == x2 && (y1 + 7) == y2 || (x1 - 8) == x2 && (y1 + 8) == y2)
    {
        n4 = 1;
    }
    else
    {
        n4 = 0;
    }
    // n5 Hourse
    if (x1 + 1 == x2 && y1 + 2 == y2 || x1 + 2 == x2 && y1 + 1 == y2 || x1 + 2 == x2 && y1 - 1 == y2 || x1 + 1 == x2 && y1 - 2 == y2 || x1 - 1 == x2 && y1 - 2 == y2 || x1 - 2 == x2 && y1 - 1 == y2 || x1 - 2 == x2 && y1 + 1 == y2 || x1 - 1 == x2 && y1 + 2 == y2)
    {
        n5 = 1;
    }
    else
    {
        n5 = 0;
    }
    if (x1 == x2 && y1 == y2) {
        n1 = 1;
        n2 = 1;
        n3 = 1;
        n4 = 1;
        n5 = 1;
    }
    else {}
    printf("Debug test: n=%d n1=%d n2=%d n3=%d n4=%d n5=%d x1=%d x2=%d y1=%d y2=%d \n", n, n1, n2, n3, n4, n5, x1, x2, y1, y2);
    switch (n)
    {
    case 1: if (n1 == 1) { printf("King can it\n"); } else { printf("King can`t it\n"); }
        break;
    case 2: if (n2 == 1) { printf("Elephnt can it\n"); } else { printf("Elephant can`t it\n"); }
        break;
    case 3: if (n3 == 1) { printf("Rook can it\n"); } else { printf("Rook can`t it\n"); }
        break;
    case 4: if (n4 == 1) { printf("Queen can it\n"); } else { printf("Queen can`t it\n"); }
        break;
    case 5: if (n5 == 1) { printf("Hourse can it\n"); } else { printf("Hourse can`t it\n"); }
        break;
    }
    printf("All list:\n");
    if (n1 == 1) { printf("-> King\n"); } else { }
    if (n2 == 1) { printf("-> Elephnt\n"); } else { }
    if (n3 == 1) { printf("-> Rook\n"); } else { }
    if (n4 == 1) { printf("-> Queen\n"); } else { }
    if (n5 == 1) { printf("-> Hourse\n"); } else { }
    system("PAUSE");

    return 0;
}
