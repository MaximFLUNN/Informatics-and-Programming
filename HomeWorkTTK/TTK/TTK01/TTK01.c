#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	float average, avgx2, avgm, sqrtnum;
	printf("Input three number(through a space)\n");
	scanf("%d %d %d", &a, &b, &c);
	//Average
	average = (a + b + c) / 3.0;
	printf("Average: %f4", average);
	//Average(square)
	avgx2 = (pow(a, 2) + pow(b, 2) + pow(c, 2)) / 3.0;
	printf("\nAverage(square): %f4", avgx2);
	//Average(module)
	avgm = (fabs(a) + fabs(b) + fabs(c)) / 3.0;
	printf("\nAverage(module): %f4", avgm);
	//Average(sqrt)
	sqrtnum = (fabs(sqrt(a)) + fabs(sqrt(b)) + fabs(sqrt(c)) / 3.0);
	printf("\nAverage(sqrt): %f4", sqrtnum);
	scanf("%d", &a);
	return 0;
}