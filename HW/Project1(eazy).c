#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
int main() {
	int n, x, A, number, i = 0, sdvig, k;
	srand(time(NULL));
	printf("\nInput number(N): ");
	scanf("%d", &n);
	printf("\nInput number(-A): ");
	scanf("%d", &x);
	printf("\nInput number(A): ");
	scanf("%d", &A);
	
	int* MainArr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		MainArr[i] = number = rand() % (A + x + 1) - x;
		printf("%d ", MainArr[i]);
	}
	printf("\nInput number(k): ");
	scanf("%d", &k);
	for (int g = 0; g < k; g++) {
		sdvig = MainArr[n - 1];
		for (i = n - 1; i > 0; i--) {
			MainArr[i] = MainArr[i - 1];
		}
		MainArr[0] = sdvig;
	}
	printf("\n Before:\n");
	for (i = 0; i < n; i++)
	printf("%d ", MainArr[i]);
	return 0;
}