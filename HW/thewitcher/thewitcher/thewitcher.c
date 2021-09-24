#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c, c25, c10, c5, c1;
	printf("Input money: ");
	scanf("%d", &a);
	if (a > 0) {
		for (int i = 25; i >= 0; i -= 1) {
			if ((i == 25 || i == 10 || i == 5 || i == 1) & a > -10) {
				b = a % i;
				a = a / i;
				if (i == 25) { c25 = a; }
				if (i == 10) { c10 = a; }
				if (i == 5) { c5 = a; }
				if (i == 1) { c1 = a; }
				a = b;
			}
		}
	}
	else
	{
		printf("\nNegative number entered!\n\n\n\n\n\n\n\n\n");
		return 0;
	}
	printf("\nMin money: %d\n", c25+c10+c5+c1);
	printf("\nMoney list: \n(25) => %d\n(10) => %d\n( 5) => %d\n( 1) => %d \n\n\n\n\n\n\n\n\n", c25, c10, c5, c1);
}