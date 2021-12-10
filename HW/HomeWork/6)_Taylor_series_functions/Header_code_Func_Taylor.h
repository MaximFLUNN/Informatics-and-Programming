/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                       | Header func file |
*/
#ifndef _FUNC_H
#define _FUNC_H
#define _CRT_SECURE_NO_WARNINGS // [ENG] Disable warnings | [RU] Отключение предупреждений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>



// [ENG]  Struct | [RU]  Структура |
struct Answer
{
    double f;
    double error;
    double etalon;
    int count;
};

// [ENG] Defining a new structure | [RU] Определение новой структуры |
struct Answer final_result;

// [ENG] Function (long long) | [RU] Функция (long long) |
long long Fact(double x);

// [ENG] Functions that return values ​​to a structure | [RU] Функции возвращающие значения в структуру |
struct Answer Sin(double x, double eps, int N, int i);
struct Answer Cos(double x, double eps, int N, int i);
struct Answer Exp(double x, double eps, int N, int i);
struct Answer Tg(double x, double eps, int N, int i);




/*
 
Задание: Добавить функцию, которая вычисляет производную (ввод по математической формуле)

*/
#endif