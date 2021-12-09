/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                    | Source localization file |
*/
#ifndef _localization_h
#define _localization_h

// [ENG] Function (void) | [RU] Функция (void) |
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

#endif 