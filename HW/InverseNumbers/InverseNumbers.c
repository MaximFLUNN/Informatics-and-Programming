#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int number, isWork = 1, choose;
	printf("Mode one - inverse numbers\n");
	printf("Mode two - sum numbers\n");
	printf("Choose mode (1 or 2): ");
	scanf("%d", &choose);
	if (choose > 2 || choose < 1) {
		printf("\nError mode number!\n");
		return 0;
	}
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
		int inverse = 0, sum = 0, numberclone = number;
		while (numberclone) {
			sum += numberclone % 10;
			numberclone = numberclone / 10;
		}
		while (number) {
			inverse *= 10;
			inverse += number % 10;
			number = number / 10;
		}
		if (isWork == 1 & choose == 1) printf("\nResult: %d\n\n", inverse);
		if (isWork == 1 & choose == 2) printf("\nResult: %d\n\n", sum);
		if (!isWork) printf("\n\nEXIT\n\n");
	}
	return 0;
}