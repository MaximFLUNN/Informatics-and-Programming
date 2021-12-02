/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
| [ENG] Task 1: Given a chess board. For two different squares K1, K2 of the board and the chosen shape (king, queen, rook, bishop, knight) |
| Determine: 1) Can a piece move from K1 to K2 in one move? | 2) If not, can any of the other shapes do this? List them if they can.|
| [RU] Task 1: Дана шахматная доска. Для двух различных клеток К1, К2 доски и выбранной пользователем фигуры (король, ферзь, ладья, слон, конь) |
| Определить: 1) Может ли фигура за один ход перейти из К1 в К2? | 2) Если нет, могут ли это сделать какие-то из остальных фигур? Если могут, вывести их список|
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main()
{
    // | [ENG] Variables | [RU] Переменные |
    int x1, x2, y1, y2, n, n1, n2, n3, n4, n5;
    // | [ENG] Introduction of parameters | [RU] Введение параметров |
    printf("Select chess(1-King,2-Elephant,\n3-Rook,4-Queen,5-Hourse): \n");
    scanf("%d", &n);
    printf("Inpunt position K1(x, y): \n");
    scanf("%d %d", &x1, &y1);
    printf("Inpunt position K2(x, y): \n");
    scanf("%d %d", &x2, &y2);
    n1 = n2 = n3 = n4 = n5 = 0;

    // [ENG] n1 King | [RU] Король |
    if (x1 == x2 && y1 == y2 || x1 == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && y1 == y2 || x1 == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && y1 == y2 || (x1 - 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 - 1) == y2)
    {
        n1 = 1;
    }
    else
    {
        n1 = 0;
    }
    // [ENG] n2 Elephant | [RU] Слон |
    if ((x1 - 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && (y1 - 1) == y2 || (x1 + 1) == x2 && (y1 + 1) == y2 || (x1 + 2) == x2 && (y1 + 2) == y2 || (x1 + 3) == x2 && (y1 + 3) == y2 || (x1 + 4) == x2 && (y1 + 4) == y2 || (x1 + 5) == x2 && (y1 + 5) == y2 || (x1 + 6) == x2 && (y1 + 6) == y2 || (x1 + 7) == x2 && (y1 + 7) == y2 || (x1 + 8) == x2 && (y1 + 8) == y2 || (x1 + 2) == x2 && (y1 - 2) == y2 || (x1 + 3) == x2 && (y1 - 3) == y2 || (x1 + 4) == x2 && (y1 - 4) == y2 || (x1 + 5) == x2 && (y1 - 5) == y2 || (x1 + 6) == x2 && (y1 - 6) == y2 || (x1 + 7) == x2 && (y1 - 7) == y2 || (x1 + 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 - 2) == y2 || (x1 - 3) == x2 && (y1 - 3) == y2 || (x1 - 4) == x2 && (y1 - 4) == y2 || (x1 - 5) == x2 && (y1 - 5) == y2 || (x1 - 6) == x2 && (y1 - 6) == y2 || (x1 - 7) == x2 && (y1 - 7) == y2 || (x1 - 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 + 2) == y2 || (x1 - 3) == x2 && (y1 + 3) == y2 || (x1 - 4) == x2 && (y1 + 4) == y2 || (x1 - 5) == x2 && (y1 + 5) == y2 || (x1 - 6) == x2 && (y1 + 6) == y2 || (x1 - 7) == x2 && (y1 + 7) == y2 || (x1 - 8) == x2 && (y1 + 8) == y2)
    {
        n2 = 1;
    }
    else
    {
        n2 = 0;
    }
    // [ENG] n3 Rook | [RU] Ладья |
    if (x1 == x2 && y1 < y2 || x1 == x2 && y1 > y2 || x1 > x2 && y1 == y2 || x1 < x2 && y1 == y2)
    {
        n3 = 1;
    }
    else
    {
        n3 = 0;
    }
    // [ENG] n4 Queen | [RU] Королева |
    if (x1 == x2 && y1 == y2 || x1 == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && y1 == y2 || x1 == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && (y1 - 1) == y2 || (x1 - 1) == x2 && y1 == y2 || (x1 - 1) == x2 && (y1 + 1) == y2 || (x1 + 1) == x2 && (y1 - 1) == y2 || x1 == x2 && y1 < y2 || x1 == x2 && y1 > y2 || x1 > x2 && y1 == y2 || x1 < x2 && y1 == y2 || (x1 + 2) == x2 && (y1 + 2) == y2 || (x1 + 3) == x2 && (y1 + 3) == y2 || (x1 + 4) == x2 && (y1 + 4) == y2 || (x1 + 5) == x2 && (y1 + 5) == y2 || (x1 + 6) == x2 && (y1 + 6) == y2 || (x1 + 7) == x2 && (y1 + 7) == y2 || (x1 + 8) == x2 && (y1 + 8) == y2 || (x1 + 2) == x2 && (y1 - 2) == y2 || (x1 + 3) == x2 && (y1 - 3) == y2 || (x1 + 4) == x2 && (y1 - 4) == y2 || (x1 + 5) == x2 && (y1 - 5) == y2 || (x1 + 6) == x2 && (y1 - 6) == y2 || (x1 + 7) == x2 && (y1 - 7) == y2 || (x1 + 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 - 2) == y2 || (x1 - 3) == x2 && (y1 - 3) == y2 || (x1 - 4) == x2 && (y1 - 4) == y2 || (x1 - 5) == x2 && (y1 - 5) == y2 || (x1 - 6) == x2 && (y1 - 6) == y2 || (x1 - 7) == x2 && (y1 - 7) == y2 || (x1 - 8) == x2 && (y1 - 8) == y2 || (x1 - 2) == x2 && (y1 + 2) == y2 || (x1 - 3) == x2 && (y1 + 3) == y2 || (x1 - 4) == x2 && (y1 + 4) == y2 || (x1 - 5) == x2 && (y1 + 5) == y2 || (x1 - 6) == x2 && (y1 + 6) == y2 || (x1 - 7) == x2 && (y1 + 7) == y2 || (x1 - 8) == x2 && (y1 + 8) == y2)
    {
        n4 = 1;
    }
    else
    {
        n4 = 0;
    }
    // [ENG] n5 Hourse | [RU] Конь |
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
    // [ENG] Debug var | [RU] Показ переменных для отладки |
    printf("Debug test: n=%d n1=%d n2=%d n3=%d n4=%d n5=%d x1=%d x2=%d y1=%d y2=%d \n", n, n1, n2, n3, n4, n5, x1, x2, y1, y2);
    // [ENG] Response output | [RU] Вывод ответа |
    switch (n)
    {
    case 1: if (n1 == 1) { printf("King can it\n"); }
          else { printf("King can`t it\n"); }
          break;
    case 2: if (n2 == 1) { printf("Elephnt can it\n"); }
          else { printf("Elephant can`t it\n"); }
          break;
    case 3: if (n3 == 1) { printf("Rook can it\n"); }
          else { printf("Rook can`t it\n"); }
          break;
    case 4: if (n4 == 1) { printf("Queen can it\n"); }
          else { printf("Queen can`t it\n"); }
          break;
    case 5: if (n5 == 1) { printf("Hourse can it\n"); }
          else { printf("Hourse can`t it\n"); }
          break;
    }
    printf("All list:\n");
    if (n1 == 1) { printf("-> King\n"); }
    if (n2 == 1) { printf("-> Elephnt\n"); }
    if (n3 == 1) { printf("-> Rook\n"); }
    if (n4 == 1) { printf("-> Queen\n"); }
    if (n5 == 1) { printf("-> Hourse\n"); }
    system("PAUSE");

    return 0;
}
