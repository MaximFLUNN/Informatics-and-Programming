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

// [ENG] Function pointer type | [RU] Тип указателя на функцию |
typedef struct Answer(*Type_Func) (double, double, int, int);
Type_Func func[4];

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

// [ENG] Functions (int) | [RU] Функции (int) |
int Select_language();
int Select_mode();
int Select_func();
int Select_settings();
int Get_Value_N();
int Get_Value_Nmax();

// [ENG] Functions (double) | [RU] Функции (double) |
double Get_Value_X();
double Get_Value_Eps();
double Calculating();
double Calculating_mode_1();
double Calculating_mode_2();
double Best_experiment(int language, int Number_experiment, double Best_result_error);

// [ENG] Functions (void) | [RU] Функции (void) |
void funcs();
void restart();
void Select_Mode_L(int language);
void Select_Mode_L_Warning(int language);
void Select_Func_L(int language);
void Select_Func_L_Warning(int language);
void Select_Settings_L(int language);
void Select_Settings_L_Warning(int language);
void Select_Settings_L_Default_1(int language, int N, double x, double eps);
void Select_Settings_L_Custom_2(int language);
void Select_Settings_L_Custom_2_Access(int language, int N, double x, double eps);
void Get_Value_N_L(int language);
void Get_Value_N_L_Warning(int language);
void Get_Value_X_L(int language);
void Get_Value_X_L_Warning(int language);
void Get_Value_Eps_L(int language);
void Get_Value_Eps_L_Warning(int language);
void Get_Value_Nmax_L(int language);
void Get_Value_Nmax_L_Warning(int language);
void Restart_L(int language);
void Restart_L_Warning(int language);
void Calculating_Mode_1_L(int language, struct Answer final_result);
void Calculating_Mode_2_L(int language, struct Answer final_result, int i, int N, double x, double eps);

// [ENG] Function (long long) | [RU] Функция (long long) |
long long Fact(double x);

// [ENG] Functions that return values ​​to a structure | [RU] Функции возвращающие значения в структуру |
struct Answer Sin(double x, double eps, int N, int i);
struct Answer Cos(double x, double eps, int N, int i);
struct Answer Exp(double x, double eps, int N, int i);
struct Answer Tg(double x, double eps, int N, int i);
#endif