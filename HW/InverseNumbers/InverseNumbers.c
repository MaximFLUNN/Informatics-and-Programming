#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int number, isWork = 1;
	while (isWork) {
		printf("Let`s input numbers!\n");
		printf("For exit enter 0\n");
		int isError = 0;
		do {
			if (isError) printf("Wrong input! Try again.");

			printf("\nInput positive number: ");
			scanf("%d", &number);
			if (number == 0) isWork = 0; break;

			isError = (number <= 0);

		} while (isError);
		int cicle = 1;
		int inverse = 0;
		while (number) {
			inverse *= 10;
			inverse += number % 10;
			number = number / 10;
		}
		if (isWork) printf("\nResult: %d\n\n", inverse);
	}
	return 0;
}