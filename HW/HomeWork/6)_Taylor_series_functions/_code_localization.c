﻿/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                    | Source localization file |
*/

#include "Header_code_Func_Taylor.h"

// [ENG] Localization | [RU] Функции локализации |
void Select_Mode_L(int language) {
    if (language == 1) printf("| Select mode (One-time settlement - 1 | Serial experiment - 2 | Derivative calculation - 3)\n| Enter: ");
    else printf("| Выберите режим (Единоразовый эксперемент - 1 | Серийный эксперимент - 2 | Рассчёт производной - 3)\n| Введите: ");
}

void Select_Mode_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - select mode] \n| You entered a non-existent value, try againg!\n| \n");
    else printf("| \n| [Предупреждение - выбор режима] \n| Вы ввели не существующее значение, попробуйте снова!\n| \n");
}

void Select_Func_L(int language) {
    if (language == 1) printf("| Select Func f(x):\n| 1 -> sin(x)\n| 2 -> cos(x)\n| 3 -> exp(x)\n| 4 -> tg(x)\n| Enter: ");
    else printf("| Выбор функции f(x):\n| 1 -> sin(x)\n| 2 -> cos(x)\n| 3 -> exp(x)\n| 4 -> tg(x)\n| Введите: ");
}

void Select_Func_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - select func] \n| You entered a non-existent value, try againg!\n| \n");
    else printf("| \n| [Предупреждение - выбор функции] \n| Вы ввели не существующее значение, попробуйте снова!\n| \n");
}

void Select_Settings_L(int language) {
    if (language == 1) printf("| Select settings (Default - 1 | Custom - 2)\n| Enter: ");
    else printf("| Выбор настроек (Стандартные - 1 | Пользовательские - 2)\n| Введите: ");
}

void Select_Settings_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - select settings] \n| You entered a non-existent value, try againg!\n| \n");
    else printf("| \n| [Предупреждение - выбор настроек] \n| Вы ввели не существующее значение, попробуйте снова!\n| \n");
}

void Select_Settings_L_Default_1(int language, int N, double x, double eps) {
    if (language == 1) printf("| Default settings selected:\n| Language -> English\n| Сount N -> %d\n| X -> %f\n| Eps -> %f\n-----------------------------\n", N, x, eps);
    else printf("| Выбраны стандартные настройки:\n| Язык -> Русский\n| Кол-во N -> %d\n| X -> %f\n| Eps -> %f\n-----------------------------\n", N, x, eps);
}

void Select_Settings_L_Custom_2(int language) {
    if (language == 1) printf("| Custom settings selected:\n");
    else printf("| Выбраны пользовательские настройки:\n");
}

void Select_Settings_L_Custom_2_Access(int language, int N, double x, double eps) {
    if (language == 1) printf("-----------------------------\n| Custom settings entered:\n| Language -> English\n| Сount N -> %d\n| X -> %f\n| Eps -> %f\n-----------------------------\n| Calculating\n", N, x, eps);
    else printf("-----------------------------\n| Пользовательские настройки введены:\n| Язык -> Русский\n| Кол-во N -> %d\n| X -> %f\n| Eps -> %f\n-----------------------------\n| Вычисление \n", N, x, eps);
}

void Get_Value_N_L(int language) {
    if (language == 1) printf("| Enter count 'N' (range: 1 - 1000): ");
    else printf("| Введите количество 'N' (диапазон: 1 - 1000): ");
}

void Get_Value_N_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - variable definition error - N] \n| You entered an invalid value, try again!\n| \n");
    else printf("| \n| [Предупреждение - ошибка определения переменной - N] \n| Вы ввели недопустимое значение, попробуйте еще раз!\n| \n");
}

void Get_Value_X_L(int language) {
    if (language == 1) printf("| Enter value 'X' (range: -9999999 - 9999999): ");
    else printf("| Введите значение 'X' (диапазон: -9999999 - 9999999): ");
}

void Get_Value_X_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - variable definition error - X] \n| You entered an invalid value, try again!\n| \n");
    else printf("| \n| [Предупреждение - ошибка определения переменной - X] \n| Вы ввели недопустимое значение, попробуйте еще раз!\n| \n");
}

void Get_Value_Eps_L(int language) {
    if (language == 1) printf("| Enter value 'Eps' (range: 0.000001 - 1): ");
    else printf("| Введите значение 'Eps' (диапазон: 0.000001 - 1): ");
}

void Get_Value_Eps_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - variable definition error - Eps] \n| You entered an invalid value, try again!\n| \n");
    else printf("| \n| [Предупреждение - ошибка определения переменной - Eps] \n| Вы ввели недопустимое значение, попробуйте еще раз!\n| \n");
}

void Get_Value_Nmax_L(int language) {
    if (language == 1) printf("| Enter value 'Nmax' (range: 1 - 25): ");
    else printf("| Введите значение 'Nmax' (диапазон: 1 - 25): ");
}

void Get_Value_Nmax_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - variable definition error - Nmax] \n| You entered an invalid value, try again!\n| \n");
    else printf("| \n| [Предупреждение - ошибка определения переменной - Nmax] \n| Вы ввели недопустимое значение, попробуйте еще раз!\n| \n");
}

void Restart_L(int language) {
    if (language == 1) printf("|\n| Restart? (1/0): ");
    else printf("|\n| Перезапустить? (1/0): ");
}

void Restart_L_Warning(int language) {
    if (language == 1) printf("| \n| [Warning - variable definition error - X] \n| You entered an invalid value, try again!\n| \n");
    else printf("| \n| [Предупреждение - ошибка определения переменной - X] \n| Вы ввели недопустимое значение, попробуйте еще раз!\n| \n");
}

void Calculating_Mode_1_L(int language, struct Answer final_result) {
    if (language == 1) printf("| Etalon value: %.12lf\n| f(x) = %.12lf\n| Error: %.12lf\n| Count of elements: %d\n-----------------------------\n", final_result.etalon, final_result.f, final_result.error, final_result.count);
    else printf("| Эталонное значение: %.12lf\n| f(x) = %.12lf\n| Разница: %.12lf\n| Количество элементов: %d\n-----------------------------\n", final_result.etalon, final_result.f, final_result.error, final_result.count);
}

void Calculating_Mode_2_L(int language, struct Answer final_result, int i, int N, double x, double eps) {
    if (language == 1) printf("| %d) | Сount N -> %d | X -> %f | Eps -> %f |\n", i + 1, N, x, eps);
    else printf("| %d) | Количество N -> %d | Значение X -> %f | Точность Eps -> %f |\n", i + 1, N, x, eps);
    if (language == 1) printf("| Etalon value: %.12lf | f(x) = %.12lf | Error: %.12lf | Count of elements: %d\n-----------------------------\n", final_result.etalon, final_result.f, final_result.error, i + 1);
    else printf("| Эталонное значение: %.12lf | f(x) = %.12lf | Разница: %.12lf | Количество элементов: %d\n-----------------------------\n", final_result.etalon, final_result.f, final_result.error, i + 1);
}

void test_start_fx_find(int language, double x) {
    if (language == 1) printf("| Tesr start (x * x): \n| x = %lf\n", x);
    else printf("| Тестовый запуск (x * x): \n| x = %lf\n", x);
}

void equation_fx_find(int language) {
    if (language == 1) printf("| \n| Enter the equation: ");
    else printf("| \n| Введите уравнение: ");
}

void x_fx_find(int language) {
    if (language == 1) printf("| Enter 'x': ");
    else printf("| Введите 'x': ");
}