/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                       | Header main file |
*/
#ifndef _MAIN_H
#define _MAIN_H

#include "Source_code_Func_Taylor.h"
#include "Source_code_localization.h"

// default settings

#define PI 3.1415926535897931

// [ENG] Variables | [RU] Переменные |
float eps = 0.000001;
int N = 1000, SelectFunc, SelectMode, i = 0, language, mode, settings, Nmax = 25, best_experiment_number;
double x = 11, xtmp = 0, best_experiment_error = 999999.999999;

// [ENG] Language selection function | [RU] Функция выбора языка |
int Select_language() {
    printf("| Select Language (Eng: 1 | Ru: 2)\n| Enter: ");
    if (scanf("%d", &language) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (!(language == 1 || language == 2)) {
        printf("| \n| [Warning - select language] \n| You entered a non-existent value, try againg!\n| \n");
        Select_language();
    }
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
}

// [ENG] Mode selection | [RU] Выбор режима |
int Select_mode() {
    Select_Mode_L(language);
    if (scanf("%d", &mode) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (!(mode == 1 || mode == 2)) {
        Select_Mode_L_Warning(language);
        Select_mode();
    }
}

// [ENG] Function selection | [RU] Выбор функции |
int Select_func() {
    Select_Func_L(language);
    if (scanf("%d", &SelectFunc) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (!(SelectFunc == 1 || SelectFunc == 2 || SelectFunc == 3 || SelectFunc == 4)) {
        Select_Func_L_Warning(language);
        Select_func();
    }
}

// [ENG] Selecting settings | [RU] Выбор настроек |
int Select_settings() {
    Select_Settings_L(language);
    if (scanf("%d", &settings) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (!(settings == 1 || settings == 2)) {
        Select_Settings_L_Warning(language);
            Select_settings();
    }
    if (settings == 1) {
        Select_Settings_L_Default_1(language, N, x, eps);
        }
    else if (settings == 2) {
        Select_Settings_L_Custom_2(language);
        N = x = eps = -9999999;
        if (mode == 2) {
            x = 11;
            eps = 0.000001;
            Nmax = 25;
        }
        if (mode == 1) N = Get_Value_N();
        x = Get_Value_X();
        if (mode == 1) eps = Get_Value_Eps();
        else Nmax = Get_Value_Nmax();
        Select_Settings_L_Custom_2_Access(language, N, x, eps);
    }
    if (x > PI) {
        while (xtmp < x) xtmp += PI;
        x -= xtmp;
    }
}

// [ENG] Retrieving a value N | [RU] Получение значения N |
int Get_Value_N() {
    Get_Value_N_L(language);
    if (scanf("%d", &N) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (N < 1 || N > 1000) {
        Get_Value_N_L_Warning(language);
        Get_Value_N();
    }
    return N;
}

// [ENG] Retrieving a value X | [RU] Получение значения X |
double Get_Value_X() {
    Get_Value_X_L(language);
    if (scanf("%lf", &x) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (x < -9999999 || x > 9999999) {
        Get_Value_X_L_Warning(language);
        Get_Value_X();
    }
    return x;
}

// [ENG] Retrieving a value Eps | [RU] Получение значения Eps |
double Get_Value_Eps() {
    Get_Value_Eps_L(language);
    if (scanf("%f", &eps) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (eps < 0.0000001 || eps > 1) {
        Get_Value_Eps_L_Warning(language);
        Get_Value_Eps();
    }
    return eps;
}

// [ENG] Retrieving a value Nmax | [RU] Получение значения Nmax |
int Get_Value_Nmax() {
    Get_Value_Nmax_L(language);
    if (scanf("%d", &N) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (N < 1 || N > 25) {
        Get_Value_Nmax_L_Warning(language);
        Get_Value_N();
    }
    return Nmax;
}

// [ENG] Restart capability | [RU] Возможность рестарта |
void restart() {
    Restart_L(language);
    if (scanf("%lf", &x) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (!(x == 1 || x == 0)) {
        Restart_L_Warning(language);
    }
    else if (x == 0) return 0;
    else main();
}

// [ENG] Calculations | [RU] Вычисления |
double Calculating() {
    if (mode == 1) return Calculating_mode_1();
    else return Calculating_mode_2();
}

// [ENG] Calculations 1 mode| [RU] Вычисления в 1 режиме |
double Calculating_mode_1() {
    if (mode == 1) {
        final_result = func[SelectFunc - 1](x, eps, N, i);
        Calculating_Mode_1_L(language, final_result);
    }
}

// [ENG] Calculations 2 mode| [RU] Вычисления во 2 режиме |
double Calculating_mode_2() {
    if (mode == 2) {
        for (i = 0; i < Nmax; i++) {
            final_result = func[SelectFunc - 1](x, eps = 0.000001 * (rand() % 1000001), N = rand() % 999 + 1, i);
            if (best_experiment_error > abs(final_result.error)) {
                best_experiment_error = abs(final_result.error);
                best_experiment_number = i + 1;
            }
            Calculating_Mode_2_L(language, final_result, i, N, x, eps);
        }
    }
}


#endif 