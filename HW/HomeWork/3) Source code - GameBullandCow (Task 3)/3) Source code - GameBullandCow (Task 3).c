/*
				| Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
				|      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
| [ENG] Task 3: Develop a program that implements the game "Bulls and Cows" |
| Rules: 1) Two players play (human and computer) | 2) The player chooses the length of the guessing number - n (from 2 to 5) |
| 3) The computer "thinks" of an n-digit number with non-repeating digits | 4) The player makes an attempt to guess the number - enters an n-digit number with non-repeating digits |
| 5) The computer reports how much is guessed without a match in the guessed number and how many guessed up to the position | 6) The player tries until he guesses the whole sequence |
| [RU] Task 3: Разработать программу, реализующую игру «Быки и коровы» |
| Правила: 1) Играют два игрока (человек и компьютер) | 2) Игрок выбирает длину загадываемого числа – n (от 2 до 5) |
| 3) Компьютер «задумывает» n-значное число с неповторяющимися цифрами | 4) Игрок делает попытку отгадать число – вводит n-значное число с неповторяющимися цифрами |
| 5) Компьютер сообщает, сколько цифр угадано без совпадения и сколько угадано вплоть до позиции | 6) Игрок делает попытки, пока не отгадает всю последовательность |
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	// | [ENG] Variables | [RU] Переменные |
	int x, i, inspect, n, usernumber, userlengh = 5, invalid, correct, correctfinal, inspection, exitprogramm, notexactposition, exactposition;
	x = i = inspect = invalid = correct = correctfinal = inspection = exitprogramm = notexactposition = exactposition = 0;
	int* ArrayComputer = (int*)malloc(userlengh * sizeof(int));
	int* ArrayUserinverse = (int*)malloc(userlengh * sizeof(int));
	char try = ' ';
	srand(time(NULL));

	// | [ENG] Main cycle | [RU] Основной цикл выполнения |
	while (exactposition != userlengh) {
		if (exitprogramm == 0) {
			while (correctfinal == 0) { // | [ENG] Cycle input lenght number 2-5 | [RU] Цикл ввода чисел с проверкой на правильность | 
				correctfinal++;
				printf("Enter length number (2-5): ");
				scanf("%d", &userlengh);
				if (userlengh > 5 || userlengh < 2) {
					printf("\nError number, try again!\n\n");
					correctfinal--;
				}
			}
			ArrayComputer = (int*)malloc(userlengh * sizeof(int));
			ArrayUserinverse = (int*)malloc(userlengh * sizeof(int));
			while (inspection < userlengh) { // | [ENG] Filling the array (Computer) | [RU] Заполнение массива |
				n = 0;
				x = rand() % 10;
				for (i = 0; i < userlengh; i++) {
					if (x != ArrayComputer[i]) {
						n++;
					}
					if (n == userlengh) {
						ArrayComputer[inspection] = x;
						inspection++;
					}
				}
			}
			exitprogramm = 1;
		}
		printf("\n\nEnter your number: "); scanf("%d", &usernumber);
		correct = usernumber;
		inspection = n = 0;
		x = userlengh - 1;
		for (i = 0; i < userlengh; i++) { // | [ENG] Dividing a number into digits | [RU] Разделение числа на отдельные цифры | 
			ArrayUserinverse[x] = usernumber % 10;
			x--;
			usernumber = usernumber / 10;
		}
		for (x = 0; x < userlengh; x++) { // | [ENG] Search duplicate numbers | [RU] Поиск дублирующихся чисел |
			for (i = 0; i < userlengh; i++) {
				if (ArrayUserinverse[x] == ArrayUserinverse[i]) {
					n++;
				}
			}
			if (n != userlengh & x == userlengh - 1) {
				printf("\nDuplicate numbers found, try again!\n");
				inspection = 1;
			}
		}
		x = exactposition = notexactposition = 0;
		correctfinal = 0;
		for (i = 0; i < userlengh; i++) { // | [ENG] Сhecking the correctness of the number | [RU] Проверка правильности номера |
			correctfinal *= 10;
			correctfinal += ArrayUserinverse[i];
		}
		if (correct != correctfinal & inspection == 0) {
			printf("\nInput invalid number!");
			inspection = 1;
		}
		for (i = 0; i < userlengh; i++) { // | [ENG] Search bull | [RU] Поиск быков |
			if (ArrayUserinverse[i] == ArrayComputer[i]) {
				if (!inspection) {
					printf("\nBull detected: %d", ArrayComputer[i]);
				}
				exactposition += 1;
			}
		}
		for (x = 0; x < userlengh; x++) { // | [ENG] Search cow | [RU] Поиск коров |
			for (i = 0; i < userlengh; i++) {
				if (ArrayUserinverse[x] == ArrayComputer[i] & ArrayUserinverse[i] != ArrayComputer[i]) {
					if (!inspection) {
						printf("\nCow detected: %d", ArrayUserinverse[x]);
					}
					notexactposition += 1;
				}
			}
		}
		if (!inspection) {
			printf("\n\nCount 'Bull' - %d, count 'Cow' - %d", exactposition, notexactposition);
		}
		if (exactposition == userlengh & !inspection) {
			printf("\n\nYou win!");
			printf("\n\nDo you want to play more?\nInput character (Y - yes , N - no)\n->");
			while (try != 'Y' || try != 'N') { // | [ENG] Cicle continue or break | [RU] Завершение или продолжение главного цикла |
				scanf("\n%c", &try);
				if (try == 'Y') {
					printf("\n\nContinue");
					exactposition = userlengh - 1;
					exitprogramm = correctfinal = 0;
					break;
				}
				else if (try == 'N') {
					printf("\n\nExit\n\n\n");
					break;
				}
				else {
					printf("\n\nInvalid character, try again! (Y - yes , N - no)\n-> ");
				}
			}
		}
	}
}

