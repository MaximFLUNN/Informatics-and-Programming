#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#define MAX_INPUT_LENGTH 255
// Find func 
char findfunc(WIN32_FIND_DATA FindFileData, int n, char** allname, int* allsize) {
    wprintf(L"File Name - %-34s | ", FindFileData.cFileName);
    if (FindFileData.dwFileAttributes == 32) {
        allsize[n] = FindFileData.nFileSizeLow;
        printf("File Size - %lu bite\n", FindFileData.nFileSizeLow);
    }
    else if (FindFileData.dwFileAttributes == 16) {
        allsize[n] = -1;
        printf("it`s folder\n");
    }
    else {
        allsize[n] = -2;
        printf("Unknown type\n");
    }
    int sizen = wcslen(FindFileData.cFileName); // size filename
    for (int i = 0; i < sizen; i++) {  // add name in array
        allname[n][i] = FindFileData.cFileName[i];
        allname[n][sizen] = 0;
    }
    return allname, allsize;
}
// Shellsort
void shellsort(int count, int* size, char* tempname, char** names) {
    int i, j, step;
    int temp;
    for (step = count / 2; step > 0; step /= 2) {
        for (i = step; i < count; i++) {
            temp = size[i];
            for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
                tempname[g] = names[i][g];
            }
            for (j = i; j >= step; j -= step) {
                if (temp < size[j - step]) {
                    size[j] = size[j - step];
                    for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
                        names[j][g] = names[j - step][g];
                    }
                }
                else {
                    break;
                }
            }
            size[j] = temp;
            for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
                names[j][g] = tempname[g];
            }
        }
    }
}
// Building a tree
void siftDown(int* size, int root, int bottom, char* tempname, char** names) {
    int maxChild;
    int done = 0;

    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom) {
            maxChild = root * 2;
        }
        else if (size[root * 2] > size[root * 2 + 1]) {
            maxChild = root * 2;
        }
        else {
            maxChild = root * 2 + 1;
        }
        if (size[root] < size[maxChild]) {
            int temp = size[root];
            for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
                tempname[g] = names[root][g];
            }
            size[root] = size[maxChild];
            for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
                names[root][g] = names[maxChild][g];
            }
            size[maxChild] = temp;
            for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
                names[maxChild][g] = tempname[g];
            }
            root = maxChild;
        }
        else {
            done = 1;
        }
    }
}
// Thee sort
void heapSort(int* size, int array_size, char** names, char* tempname)
{
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(size, i, array_size - 1, tempname, names);
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = size[0];
        for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
            tempname[g] = names[0][g];
        }
        size[0] = size[i];
        for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
            names[0][g] = names[i][g];
        }
        size[i] = temp;
        for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
            names[i][g] = tempname[g];
        }
        siftDown(size, 0, i - 1, tempname, names);
    }
}
// Sort by selection method 
void sortselection(int* allsize, char** allname, int a, char* tempname) {
    int minPosition, tempsize;
    for (int i = 0; i < a; i++) {
        minPosition = i;
        for (int j = i + 1; j < a; j++) {
            if (allsize[minPosition] > allsize[j]) {
                minPosition = j;
            }
        }
        tempsize = allsize[minPosition];
        for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
            tempname[g] = allname[minPosition][g];
        }
        allsize[minPosition] = allsize[i];
        for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
            allname[minPosition][g] = allname[i][g];
        }
        allsize[i] = tempsize;
        for (int g = 0; g < MAX_INPUT_LENGTH; g++) {
            allname[i][g] = tempname[g];
        }
    }
}
void main()
{
    // get path and size 
    wchar_t wstr[MAX_INPUT_LENGTH];
    char mb_str[MAX_INPUT_LENGTH * 3 + 1];
    unsigned long read;
    printf("Input path to dir: ");
    void* con = GetStdHandle(STD_INPUT_HANDLE);
    ReadConsole(con, wstr, MAX_INPUT_LENGTH, &read, NULL);
    int size = WideCharToMultiByte(CP_UTF8, 0, wstr, read, mb_str, sizeof(mb_str), NULL, NULL);
    mb_str[size] = 0;
    printf("Scan folder: %s", mb_str);
    // Transformate path 
    wchar_t* tmp = (wchar_t*)malloc(size * sizeof(wchar_t));
    for (int i = 0; i < size - 2; i++) {
        tmp[i] = wstr[i];
    }
    tmp[size - 2] = '\\';
    tmp[size - 1] = '*';
    tmp[size] = 0;
    int n = 0;
    int a = 0;
    char tempname[MAX_INPUT_LENGTH];
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;
    LPCWSTR file = tmp;
    hFindFile = FindFirstFile(file, &FindFileData);
    // Counting the number 'a' (count files)
    FindNextFile(hFindFile, &FindFileData);
    while (FindNextFile(hFindFile, &FindFileData)) {
        a++;
    }
    FindClose(hFindFile);
    /////////////////////////////// Dynamic memory allocation (allname[][] and allsize[])
    char** allname = (char**)malloc(a * sizeof(char*));
    for (int i = 0; i < a; i++) {
        allname[i] = (char*)malloc(MAX_INPUT_LENGTH * sizeof(char));
    }
    int* allsize = (int*)malloc(a * sizeof(int*));
    /////////////////////////////// Start finding 
    hFindFile = FindFirstFile(file, &FindFileData);
    if (INVALID_HANDLE_VALUE == hFindFile) {
        printf("Error in Finding File\n");
        printf("Error - %ñ\n", GetLastError());
    }
    else
    {
        FindNextFile(hFindFile, &FindFileData);
        FindNextFile(hFindFile, &FindFileData);
        printf("Found files:\n");
        findfunc(FindFileData, n, allname, allsize);
        n++;
    }
    // Cycle find file
    while (FindNextFile(hFindFile, &FindFileData)) {
        findfunc(FindFileData, n, allname, allsize);
        n++;
    }
    FindClose(hFindFile);
    printf("\nCount files in folder: %d\n", a);
    // Select method
    int flagselect = 0;
    int time;
    while (flagselect == 0) {
        printf("\nSelect sort method (1 - Selection sort | 2 - Heap sort | 3 - Shell sort)\n-> ");
        char p;
        p = getch();
        printf("%c\n", p);
        if (p == '1' || p == '2' || p == '3') {
            if (p == '1') {
                time = clock();
                sortselection(allsize, allname, a, tempname);
                time = clock() - time;
                flagselect = 1;
            }
            else if (p == '2') {
                time = clock();
                heapSort(allsize, a, allname, tempname);
                time = clock() - time;
                flagselect = 1;
            }
            else if (p == '3') {
                time = clock();
                shellsort(a, allsize, tempname, allname);
                time = clock() - time;
                flagselect = 1;
            }
        }
        else {
            printf("'\nError, try again!");
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Sorted: %-38s | %d Bite\n", allname[i], allsize[i]);
    }
    if (time > 0) {
        printf("\nTime of work: %d ms\n\n", time);
    }
    else {
        printf("\nTime of work: < 0 ms\n\n");
    }
    // free memory
    for (int i = 0; i < a; i++) {
        free(allname[i]);
    }
    free(allname);
    free(allsize);
    // exit
    system("PAUSE");
    system("cls");\
        while (flagselect != 2) {
            printf("\n\n\nRestart? (0/1)\n-> ");
            char yn = getch();
            printf("%c\n", yn);
            if (yn == '1') {
                system("cls");
                flagselect = 2;
                main();
            }
            else if (yn == '0') {
                system("cls");
                printf("\n\n\nClosed\n\n\n");
                return 0;
            }
            else
            {
                printf("Error, try again!\n");
            }
        }
}
