#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#define MAX_INPUT_LENGTH 255
void sortselection();
void heapSort();
void siftDown();
void shellsort();
int main() {
    // Get path
    char tempname[MAX_INPUT_LENGTH], wstr[MAX_INPUT_LENGTH];
    printf("Input path to dir: ");
    gets(wstr);
    int size = strlen(wstr), a = 0, n = 0;
    printf("\nRoot directory: %s\n", wstr);
    wchar_t* tmp = (wchar_t*)malloc(size * sizeof(wchar_t));
    for (int i = 0; i < size; i++) {
        tmp[i] = wstr[i];
    }
    tmp[size] = 0;
    a = FindCountNumbers(tmp, a); // File count
    if (a > 899) {
        printf("\nNumber of files exceeded, programm closed!\n");
        return 0;
    }
    // Memory allocation
    char** allname = (char**)malloc(a * sizeof(char*));
    for (int i = 0; i < a; i++) {
        allname[i] = (char*)malloc(60 * sizeof(char));
    }
    int* allsize = (int*)malloc(a * sizeof(int*));
    FindRecursive(tmp, tmp, n, allname, allsize); // File find
    printf("\nCount files: %d\n", a);
    // Select method sort
    wchar_t pt[100];
    int flagselect = 0, countflag = 0;
    if (a > 20) {
        printf("\nThe number of files is more than 20 so the output is implemented in a text file\n");
        countflag = 1;
    }
    if (a == 0) flagselect = 2;
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
    // Print sorted array
    if (flagselect == 1) {
        if (countflag == 0) {
            for (int i = 0; i < a; i++) {
                if (allsize[i] > 0) printf("Sorted: %-38s | %d Bite\n", allname[i], allsize[i]);
                else printf("Sorted: %-38s | Folder\n", allname[i]);
            }
        }
        else {
            FILE* file = fopen("Result.txt", "w");
            for (int i = 0; i < a; i++) {
                if (allsize[i] > 0) fprintf(file, "Sorted: %-38s | %d Bite\n", allname[i], allsize[i]);
                else fprintf(file, "Sorted: %-38s | Folder\n", allname[i]);
            }
            if (time > 0) {
                fprintf(file, "\nTime of work: %d ms\n\n", time);
            }
            else {
                fprintf(file, "\nTime of work: < 1 ms\n\n");
            }
            fclose(file);
        }
        if (time > 0) {
            printf("\nTime of work: %d ms\n\n", time);
        }
        else {
            printf("\nTime of work: < 1 ms\n\n");
        }
    }
    // Free memory
    for (int i = 0; i < a; i++) {
        free(allname[i]);
    }
    free(allname);
    free(allsize);
    // Exit or restart
    system("PAUSE");
    system("cls");
    while (flagselect != 2) {
        printf("Restart? (0/1)\n-> ");
        char yn = getch();
        printf("%c\n", yn);
        if (yn == '1') {
            system("cls");
            flagselect = 2;
            main();
        }
        else if (yn == '0') {
            system("cls");
            printf("Closed\n\n\n");
            return 0;
        }
        else
        {
            printf("Error, try again!\n");
        }
    }
}
int FindCountNumbers(wchar_t* path, int a) {
    int size = wcslen(path);
    WIN32_FIND_DATA finddata;
    wchar_t p[512], buf[512], pathTMP[MAX_INPUT_LENGTH];
    HANDLE hFind;
    for (int i = 0; i < size; i++) {
        pathTMP[i] = path[i];
    }
    pathTMP[size] = '\\';
    pathTMP[size + 1] = '*';
    pathTMP[size + 2] = 0;
    hFind = FindFirstFile(pathTMP, &finddata);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (strcmp(finddata.cFileName, "..") && strcmp(finddata.cFileName, ".")) {
                a++;
            }
        } while (FindNextFile(hFind, &finddata));
    }
    FindClose(hFind);
    hFind = FindFirstFile(pathTMP, &finddata);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if ((finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                if (strcmp(finddata.cFileName, "..") && strcmp(finddata.cFileName, ".")) {
                    for (int i = 0; i < size; i++) {
                        buf[i] = pathTMP[i];
                    }
                    buf[size] = '\\';
                    int sizefilename = wcslen(finddata.cFileName);
                    for (int i = 0; i < sizefilename; i++) {
                        buf[i + size + 1] = finddata.cFileName[i];
                    }
                    buf[size + sizefilename + 1] = 0;
                    a = FindCountNumbers(buf, a);
                }
            }
        } while (FindNextFile(hFind, &finddata));
    }
    FindClose(hFind);
    return a;
}
///////////////////
int FindRecursive(wchar_t* path, wchar_t* rootpath, int n, char** allname, int* allsize)
{
    int size = wcslen(path), sizeR = wcslen(rootpath);
    WIN32_FIND_DATA finddata;
    wchar_t p[512], buf[512], pathTMP[MAX_INPUT_LENGTH];
    HANDLE hFind;
    for (int i = 0; i < size; i++) {
        pathTMP[i] = path[i];
    }
    pathTMP[size] = '\\';
    pathTMP[size + 1] = '*';
    pathTMP[size + 2] = 0;
    hFind = FindFirstFile(pathTMP, &finddata);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (strcmp(finddata.cFileName, "..") && strcmp(finddata.cFileName, ".")) {
                if (size == sizeR) {
                    wprintf(L"Root folder: %-32s | ", finddata.cFileName);
                    if (finddata.dwFileAttributes == 16) printf("it`s folder\n");
                    else printf("Size: %lu (bite)\n", finddata.nFileSizeLow);
                }
                else {
                    for (int i = sizeR; i < size; i++) {
                        p[i - sizeR] = pathTMP[i + 1];
                    }
                    p[size - sizeR] = 0;
                    wprintf(L"In folders -> %s%s | ", p, finddata.cFileName);
                    if (finddata.dwFileAttributes == 16) printf("it`s folder\n");
                    else printf("Size: %lu (bite)\n", finddata.nFileSizeLow);
                }
                int sizen = wcslen(finddata.cFileName); // size filename
                for (int i = 0; i < sizen; i++) {  // add name in array
                    allname[n][i] = finddata.cFileName[i];
                    allname[n][sizen] = 0;
                }
                allsize[n] = finddata.nFileSizeLow;
                n++;
            }
        } while (FindNextFile(hFind, &finddata));
    }
    FindClose(hFind);
    hFind = FindFirstFile(pathTMP, &finddata);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if ((finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                if (strcmp(finddata.cFileName, "..") && strcmp(finddata.cFileName, ".")) {
                    for (int i = 0; i < size; i++) {
                        buf[i] = pathTMP[i];
                    }
                    buf[size] = '\\';
                    int sizefilename = wcslen(finddata.cFileName);
                    for (int i = 0; i < sizefilename; i++) {
                        buf[i + size + 1] = finddata.cFileName[i];
                    }
                    buf[size + sizefilename + 1] = 0;
                    n = FindRecursive(buf, rootpath, n, allname, allsize);
                }
            }
        } while (FindNextFile(hFind, &finddata));
    }
    FindClose(hFind);
    return n;
}
// Shellsort
void shellsort(int count, int* size, char* tempname, char** names) {
    int i, j, step;
    int temp;
    for (step = count / 2; step > 0; step /= 2) {
        for (i = step; i < count; i++) {
            temp = size[i];
            for (int g = 0; g < 60; g++) {
                tempname[g] = names[i][g];
            }
            for (j = i; j >= step; j -= step) {
                if (temp < size[j - step]) {
                    size[j] = size[j - step];
                    for (int g = 0; g < 60; g++) {
                        names[j][g] = names[j - step][g];
                    }
                }
                else {
                    break;
                }
            }
            size[j] = temp;
            for (int g = 0; g < 60; g++) {
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
            for (int g = 0; g < 60; g++) {
                tempname[g] = names[root][g];
            }
            size[root] = size[maxChild];
            for (int g = 0; g < 60; g++) {
                names[root][g] = names[maxChild][g];
            }
            size[maxChild] = temp;
            for (int g = 0; g < 60; g++) {
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
        for (int g = 0; g < 60; g++) {
            tempname[g] = names[0][g];
        }
        size[0] = size[i];
        for (int g = 0; g < 60; g++) {
            names[0][g] = names[i][g];
        }
        size[i] = temp;
        for (int g = 0; g < 60; g++) {
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
        for (int g = 0; g < 60; g++) {
            tempname[g] = allname[minPosition][g];
        }
        allsize[minPosition] = allsize[i];
        for (int g = 0; g < 60; g++) {
            allname[minPosition][g] = allname[i][g];
        }
        allsize[i] = tempsize;
        for (int g = 0; g < 60; g++) {
            allname[i][g] = tempname[g];
        }
    }
}

//Вывод в file 
// sort