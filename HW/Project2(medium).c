#include <stdio.h>
#include <math.h>
int main() {
	int n, k, y1, y2, y3, i, g, x;
	printf("Input number (k - N): ");
	scanf_s("%d %d", &k, &n);
	int* All = (int*)malloc(n * sizeof(int));
	int* Crytie = (int)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("input score user (%d): ", i + 1);
		scanf_s("%d %d %d", &y1, &y2, &y3);
		All[i] = y1 + y2 + y3;
	}
	for (i = 0; i < n; i++) {
		Crytie[i] = i;
	}
	for (i = 0; i < n - 1; i++) {
		for (g = 0; g < n - i - 1; g++) {
			if (All[g] < All[g + 1]) {
				x = All[g];
				All[g] = All[g + 1];
				All[g + 1] = x;
				x = All[g];
				Crytie[g] = Crytie[g + 1];
				Crytie[g + 1] = x;
			}
		}
	}
	printf("Prohodnoy ball - %d", All[k - 1]);
	printf("\nList of applicants: ");
	for (int i = 0; i < k; i++) {
		printf("%d ", Crytie[i] + 1);
	}

}