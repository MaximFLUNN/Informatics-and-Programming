// Powered by @MaximFLUNN
#include <stdio.h>
int main() {
	int i, sum2elements = 0, sum2index = 0, sum2znach = 0, index1, index2, safe, arraysafe, x = 0, SIZE, g = 0;
	char YN = ' ';
	printf("| Powered by @MaximFLUNN\n|\n");
	printf("| Input size array: ");
	scanf_s("%d", &SIZE);
	int* array = (int*)malloc(SIZE * sizeof(int));
	int* array2 = (int*)malloc(SIZE * sizeof(int));
	int* array3 = (int*)malloc(SIZE * sizeof(int));
	printf("| Filling the array, autocomplete? (Y - N): ");
	while (1) {
		scanf_s("%c", &YN);
		if (YN == 'N') {
			for (i = 0; i < SIZE; i++) {
				printf("| Array[%d] = ", i + 1);
				scanf_s("%d", &array[i]);
			}
			printf("| Filling completed\n|");
			break;
		}
		else if (YN == 'Y') {
			for (i = 0; i < SIZE; i++) {
				array[i] = i + 1;
			}
			printf("| Filling completed");
			break;
		}
	}
	for (int i = 0; i < SIZE; i++) {
		if (i % 2 == 0) {
			sum2index += array[i];
		}
		else {
			sum2elements += array[i];
		}
		if (array[i] % 2 != 0) {
			sum2znach += array[i];
		}
	}
	for (i = SIZE - 1; i >= 0; i--, x++) {
		array2[x] = array[i];
		array3[i] = array[i];
	}
	for (i = 0; i < SIZE / 2; i++) {
		x = array3[i];
		array3[i] = array3[SIZE - 1 - i];
		array3[SIZE - 1 - i] = x;
	}
	printf("\n| Default array -> [");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}
	printf("]");
	printf("\n| Sum of even elements: %d\n| Sum of elements with even indices: %d\n| Sum of even elements with even values: %d\n|", sum2elements, sum2index, sum2znach);
	printf("\n| Begin swapping elements\n");
	printf("| Enter the indexes of elements (a, b)\n");
	scanf_s("%d %d", &index1, &index2);
	printf("| Array after:  ");
	printf("[");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}
	printf("]");
	safe = array[index2];
	array[index2] = array[index1];
	array[index1] = safe;
	printf("\n| Array before: [");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}
	printf("]");
	printf("\n| Inverse array (method: two array) -> [");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array2[i]);
	}
	printf("]\n| Inverse array (method: one array) - > ["); 
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array3[i]);
	}
	printf("]\n\n\n");
	system("pause");
}


