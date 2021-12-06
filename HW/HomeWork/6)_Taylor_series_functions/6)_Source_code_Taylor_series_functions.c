/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                       | Source main file |
| [ENG] Task 6 : Develop a program that allows you to calculate values ​​for a certain set of functions at a given point with a given error by expanding these functions in a Taylor series |
| 2 modes must be implemented (Single calculation and Serial experiment) |
| [RU] Task 6: Разработать программу, позволяющую выполнять расчет значений для некоторого набора функций в заданной точке с заданной погрешностью за счет разложения этих функций в ряд Тейлора |
| Должно быть реализовано 2 режима (Однократный расчет и Серийный эксперимент) |
*/

#include "Source_code_Main_Taylor.h"

int main() {

    Select_language(); // [ENG] Language selection | [RU] Выбор языка |
    Select_mode(); // [ENG] Mode selection | [RU] Выбор режима |
    Select_func(); // [ENG] Function selection | [RU] Выбор функции |
    Select_settings(); // [ENG] Selecting settings | [RU] Выбор настроек |
    funcs(); // [ENG] Adding functions | [RU] Добававление функций |
    Calculating(); // [ENG] Calculations | [RU] Вычисления |
    restart(); // [ENG] Restart capability | [RU] Возможность рестарта |
    return 0;
}