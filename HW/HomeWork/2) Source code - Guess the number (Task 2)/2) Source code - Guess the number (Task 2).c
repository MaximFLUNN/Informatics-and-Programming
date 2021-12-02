/*
				| Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
				|      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
| [ENG] Task 2: Write a program "Guess the number" with two modes of operation, where the computer and the user guess |
| [RU] Task 2: Написать программу "Угадай число" с двумя режимами работы, где угадывает компьютер и пользователь |
*/

#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

int main() {
	// | [ENG] Variables | [RU] Переменные |
	int mode, x, number, attempts, HN, hn, maxhn, minhn;
	char simbol;
	number = attempts = 0;
	HN = 500;
	hn = 500;
	printf("Mode one: The computer hides the number and you are looking for it\n");
	printf("Mode two: you hide the number, and the computer looks for it\n");

	// | [ENG] Select mode | [RU] Выбор режима |
	printf("Select mode (1 or 2): ");
	scanf("%d", &mode);
	if (mode > 2 || mode < 1) {
		printf("\nERROR mode number!\n\n\n");
		return 0;
	}
	// | [ENG] Mode one: User find | [RU] Режим первый: Угадывает пользователь |
	if (mode == 1) {
		srand(time(NULL));
		x = rand() % 1000 + 1;
		while (number != x) {
			printf("\nInput number: ");
			scanf("%d", &number);
			attempts += 1;
			if (number > x) { printf("\nHidden number is less"); }
			if (number < x) { printf("\nHidden number is greater"); }
			if (number == x) { printf("\nYeah, hidden number = %d\nYou won!(mode: one)\nYou made %d attempts\n\n\n\n", number, attempts); return 0; }
		}
	}
	// | [ENG] Mode two: Computer find | [RU] Режим второй: Угадывает компьютер |
	if (mode == 2) {
		maxhn = 1001;
		minhn = 0;
		printf("Input number: ");
		scanf("%d", &number);
		if (number > 1000 || number < 1) {
			printf("ERROR number!");
			return 0;
		}
		printf("I think it's %d (range: %d - %d) | ", HN, minhn + 1, maxhn - 1);
		attempts = 1;
		while (maxhn - minhn > 10) {
			if (number > maxhn || number < minhn) {
				printf("\nYou are cheating!\n");
				return 0;
			}
			scanf("%c", &simbol);
			if (simbol == '>' & number == 500 || simbol == '<' & number == 500) {
				printf("\nYou are cheating!\n");
				return 0;
			}
			if (simbol == '>') {
				minhn = HN + 1;
				HN += hn / 2;
				hn /= 2;
				printf("I think it's %d (range: %d - %d) | ", HN, minhn - 1, maxhn - 1);
				attempts++;
			}
			if (simbol == '<') {
				maxhn = HN - 1;
				HN -= hn / 2;
				hn /= 2;
				printf("I think it's %d (range: %d - %d) | ", HN, minhn + 1, maxhn + 1);
				attempts++;
			}
			if (simbol == '=') {
				if (HN == number) {
					printf("\nYeah, im won!\nAttempts: %d\n", attempts);
					return 0;
				}
				if (HN != number) {
					printf("\nERROR number\n");
					return 0;
				}
			}
		}
		while (maxhn - minhn >= 1) {
			if (number > maxhn || number < minhn) {
				printf("\nYou are cheating!\n");
				return 0;
			}
			scanf("%c", &simbol);
			if (simbol == '>') {
				HN += 1;
				minhn = HN;
				if (minhn == maxhn) {
					printf("\nERROR number!\n");
					return 0;
				}
				printf("I think it's %d (range: %d - %d) | ", HN, minhn - 1, maxhn - 1);
				attempts++;
			}
			if (simbol == '<') {
				HN -= 1;
				maxhn = HN;
				if (minhn == maxhn) {
					printf("\nERROR number!\n");
					return 0;
				}
				printf("I think it's %d (range: %d - %d) | ", HN, minhn + 1, maxhn + 1);
				attempts++;
			}
			if (simbol == '=') {
				if (HN == number) {
					printf("\nYeah, im won!\nAttempts: %d\n", attempts);
					system("pause");
					return 0;
				}
				if (HN != number) {
					printf("\nERROR number\n");
					return 0;
				}
			}
		}
	}
	system("pause");
}