/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                       | Header main file |
*/
#ifndef _MAIN_H
#define _MAIN_H

#include "Header_code_Func_Taylor.h"
#include "Header_code_localization.h"

#define PI 3.1415926535897931

// [ENG] Variables | [RU] Переменные |
float eps;
int N, SelectFunc, SelectMode, i, language, mode, settings, Nmax, Number_experiment;
double x, xtmp, X_clone, Best_result_error;



// [ENG] Functions (int) | [RU] Функции (int) |
int Select_language();
int Select_mode();
int Select_func();
int Select_settings();
int Get_Value_N();
int Get_Value_Nmax();
int clear_input_buffer();

// [ENG] Functions (double) | [RU] Функции (double) |
double Get_Value_X();
double Get_Value_Eps();
double f();
double fx();


// [ENG] Function (void) | [RU] Функция (void) |
void restart();
void Fx_find();

#endif 