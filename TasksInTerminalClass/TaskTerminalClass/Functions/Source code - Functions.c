/*
                | Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
*/

/*
Problem statement.

Some program has been implemented that works with matrix operations.

The programmer started working on it and realized that there was a lot of code duplication in it.
He looked at his code and saw no problems in the code itself. To fix the
duplication problem, he decided to take out part of the code in the function.
Help him with this, and also add the functionality that he did not have time to.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
//Powered MaximFLUNN 3821B1PR2 Update ENG language
/// <summary>
/// generating a random number from a specified range
/// </summary>
/// <param name="maximum">maximum allowable random value</param>
/// <param name="minimun">minimum allowable random value</param>
/// <returns>generated random value</returns>
int generateRandNumber(int max, int min) {
    int value = min + rand() % (max - min + 1);
    return value;
}

/// <summary>
/// allocation of the specified memory size
/// </summary>
/// <param name="matrix">matrix</param>
/// <param name="n">number of rows</param>
/// <param name="m">number of columns</param>
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// matrix output to the screen
/// </summary>
/// <param name="matrix">matrix</param>
/// <param name="n">number of rows</param>
/// <param name="m">number of columns</param>
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printVector(int x, int y) {
    printf("(%d, %d)\n", x, y);
}

/// <summary>
/// multiplying a matrix by a number
/// </summary>
/// <param name="matrix"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <param name="value"></param>
/// <returns></returns>
int** multMatrixOnNumber(int** matrix, int n, int m, int* value) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * (*value);
        }
    }
    return res;
}

int** multTwoMatrix(int** matrix_A, int** matrix_B, int n, int k, int m) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            for (int l = 0; l < m; l++) {
                res[i][j] += matrix_A[i][l] * matrix_B[l][j];
            }
        }
    }
    return res;
}

int** additionTwoMatrix(int** matrix_A, int** matrix_B, int n, int m) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
    return res;
}

int** matrixTransposition(int** matrix, int m, int n) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}

void multVectorOnNumber(int* resx, int* resy, int x, int y, int value) {
    *resx = x * value;
    *resy = y * value;
}

void multTwoVectors(int* resx, int* resy, int ax, int ay, int bx, int by) {
    *resx = ax * bx;
    *resy = ay * by;
}

void additionTwoVectors(int* resx, int* resy, int ax, int ay, int bx, int by) {
    *resx = ax + bx;
    *resy = ay + by;
}

void fillArrayRandValues(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = generateRandNumber(max, min);
        }
    }
}

void freeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
    matrix = setMemory(matrix, n, m);
    fillArrayRandValues(matrix, n, m, max, min);
    printf("\nMatrix %c =\n", name);
    printMatrix(matrix, n, m);
    return matrix;
}

void inputSize(int* N, int* M, int* K) {
    scanf_s("%d %d %d", N, M, K);
}

void inputData(int* min, int* max) {
    scanf_s("%d %d", min, max);
}

void inputVector(int* x, int* y) {
    scanf_s("%d %d", x, y);
}

int main() {
    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL;
    int N = 0, M = 0, K = 0;
    int max = 0, min = 0, value = 0;

    srand(time(0));

    printf("Enter sizes of matrix ( A[N,M] B[M,K] ) : ");
    inputSize(&N, &M, &K);
    printf("Enter minimum and maximum of numbers: ");
    inputData(&min, &max);

    matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
    matrix_B = createMatrix(matrix_B, M, K, max, min, 'B');
    value = generateRandNumber(max, min);
    // multiplying a matrix by a number

    result = setMemory(result, N, M);
    result = multMatrixOnNumber(matrix_A, N, M, &value);
    printf("\nMatrix Ax%d =\n", value);
    printMatrix(result, N, M);
    freeMemory(result, N, M);

    // matrix transposition
    result = setMemory(result, M, N);
    result = matrixTransposition(matrix_A, M, N);
    printf("\nMatrix AT =\n");
    printMatrix(result, M, N);
    // clearing the result after output
    freeMemory(result, M, N);

    // multiplication of two matrices
    result = setMemory(result, N, K);
    result = multTwoMatrix(matrix_A, matrix_B, N, K, M);
    printf("\nMatrix AxB =\n");
    printMatrix(result, N, K);
    // clearing the result after output
    freeMemory(result, N, K);

    // addition of two matrices
    if (N == M && M == K) {
        result = setMemory(result, N, M);
        result = additionTwoMatrix(matrix_A, matrix_B, N, M);
        printf("\nMatrix A+B =\n");
        printMatrix(result, N, M);
        freeMemory(result, N, K);
    }
    else printf("\nDifferent sizes of matrix, addition is impossible\n");

    int ax = 0, ay = 0, bx = 0, by = 0;
    value = generateRandNumber(max, min);
    int resx = 0, resy = 0;

    printf("\nEnter vectors a and b ( vector x, vector y ) : ");
    inputVector(&ax, &ay);
    inputVector(&bx, &by);

    // multiplying a vector by a number
    printf("\nVector a*%d = ", value);
    multVectorOnNumber(&resx, &resy, ax, ay, value);
    printVector(resx, resy);

    // addition of two vectors
    printf("\nVector a+b = ");
    additionTwoVectors(&resx, &resy, ax, ay, bx, by);
    printVector(resx, resy);

    // multiplication of two vectors
    printf("\nVector a*b = ");
    multTwoVectors(&resx, &resy, ax, ay, bx, by);
    printVector(resx, resy);

    // clearing all allocated memory
    freeMemory(matrix_A, N, M);
    freeMemory(matrix_B, M, K);

    return 0;
}
