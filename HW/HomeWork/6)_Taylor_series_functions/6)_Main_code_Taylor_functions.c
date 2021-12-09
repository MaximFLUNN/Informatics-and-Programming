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

#include "Header_code_Main_Taylor.h"

// [ENG] Function pointer type | [RU] Тип указателя на функцию |
typedef struct Answer(*Type_Func) (double, double, int, int);
Type_Func func[4];

int main() {

    Select_language(); // [ENG] Language selection | [RU] Выбор языка |
    Select_mode(); // [ENG] Mode selection | [RU] Выбор режима |
    Select_func(); // [ENG] Function selection | [RU] Выбор функции |
    Select_settings(); // [ENG] Selecting settings | [RU] Выбор настроек |

    func[0] = Sin;
    func[1] = Cos;
    func[2] = Exp;
    func[3] = Tg;

    if (mode == 1) {
        final_result = func[SelectFunc - 1](x, eps, N, i);
        Calculating_Mode_1_L(language, final_result);
    }
    if (mode == 2) {
        for (i = 0; i < Nmax; i++) {
            final_result = func[SelectFunc - 1](x, eps = 0.000001 * (rand() % 1000001), N = rand() % 999 + 1, i);
            if (Best_result_error > fabs(final_result.error)) {
                Best_result_error = final_result.error;
                Number_experiment = i + 1;
            }
            Calculating_Mode_2_L(language, final_result, i, N, X_clone, eps);
        }
        Best_experiment(language, Number_experiment, Best_result_error);
    }
    restart(); // [ENG] Restart capability | [RU] Возможность рестарта |
    return 0;
}

// FUNC

// [ENG] Language selection function | [RU] Функция выбора языка |
int Select_language() {

    // default settings
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    N = 1000;
    eps = 0.000001;
    Best_result_error = 99999999;
    Nmax = 25;
    x = rand() % 999 + 1;
    i = xtmp = 0;
    SelectFunc = settings = language = mode = 0;

    printf("| Select Language (Eng: 1 | Ru: 2)\n| Enter: ");
    if (scanf("%d", &language) != 1) {
        while (fgetc(stdin) != '\n') continue;
    }
    if (!(language == 1 || language == 2)) {
        printf("| \n| [Warning - select language] \n| You entered a non-existent value, try againg!\n| \n");
        Select_language();
    }
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
            x = rand() % 999 + 1;
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
        X_clone = x;
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
        restart();
    }
    else if (x == 0) return 0;
    else if (x == 1) main();
}