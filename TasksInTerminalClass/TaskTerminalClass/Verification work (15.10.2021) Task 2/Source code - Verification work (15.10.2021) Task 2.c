﻿/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	int n, k, y1, y2, y3, i, g, x;
	printf("Input number (k - N): ");
	scanf("%d %d", &k, &n);
	int* All = (int*)malloc(n * sizeof(int));
	int* Crytie = (int)malloc(k * sizeof(int));
	for (i = 0; i < n; i++) {
		printf("input score user (%d): ", i + 1);
		scanf("%d %d %d", &y1, &y2, &y3);
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
	for (i = 0; i < k; i++) {
		printf("%d ", Crytie[i] + 1);
	}

}
