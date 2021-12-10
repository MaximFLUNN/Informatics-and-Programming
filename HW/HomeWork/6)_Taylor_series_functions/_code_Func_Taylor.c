/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                       | Source func file |
*/
#include "Header_code_Func_Taylor.h"


// | [ENG] Factorial | [RU] Факториал |
long long Fact(double x) {
    if (x < 0) return 0;
    if (x == 1 || x == 0) return 1;
    return x * Fact(x - 1);
}

// [ENG] Calculation sin(x) | [RU] Рассчёт sin(x) |
struct Answer Sin(double x, double eps, int N, int i) {
    struct Answer result;
    result.etalon = sin(x);
    result.f = 0;
    for (i = 1; i <= N; i++) {
        result.f += pow(-1, i + 1) * pow(x, 2 * i - 1) / (long double)Fact(2 * i - 1);
        if (fabs(result.etalon - result.f) < eps) break;
    }
    result.error = fabs(result.etalon - result.f);
    result.count = i - 1;
    return result;
}

// [ENG] Calculation cos(x) | [RU] Рассчёт cos(x) |
struct Answer Cos(double x, double eps, int N, int i) {
    struct Answer result;
    result.etalon = cos(x);
    result.f = 0;
    for (i = 0; i < N; i++) {
        result.f += pow(-1, i) * pow(x, 2 * i) / (long double)Fact(2 * i);
        if (fabs(result.etalon - result.f) < eps) break;
    }
    result.error = fabs(result.etalon - result.f);
    result.count = i;
    return result;
}

// [ENG] Calculation exp(x)| [RU] Рассчёт exp(x) |
struct Answer Exp(double x, double eps, int N, int i) {
    struct Answer result;
    result.etalon = exp(x);
    result.f = 0;
    for (i = 0; i < N; i++) {
        result.f += pow(x, i) / (long double)Fact(i);
        if (fabs(result.etalon - result.f) < eps) break;
    }
    result.error = fabs(result.etalon - result.f);
    result.count = i;
    return result;
}

// [ENG] Calculation tg(x)| [RU] Рассчёт tg(x) |
struct Answer Tg(double x, double eps, int N, int i) {
    struct Answer result;
    struct Answer resultSin = Sin(x, eps, N, i);
    struct Answer resultCos = Cos(x, eps, N, i);
    result.etalon = sin(x) / cos(x);
    result.f = resultSin.f / resultCos.f;
    result.error = result.etalon - result.f;
    result.count = resultSin.count + resultCos.count;
    return result;
}

