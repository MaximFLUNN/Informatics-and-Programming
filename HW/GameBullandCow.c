#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() { //Powered by MaximFLUNN (Maxim Filatov 3821B1PR2) Game: Bull and cow :)
	int x = 0, i = 0, usernumber, userlengh, inspection = 0,  notexactposition = 0, exactposition = 0; int* ArrayComputer; int* ArrayUser; int* ArrayUserinverse;
	srand(time(NULL));
	printf("Enter length number (2-5): "); scanf("%d", &userlengh);
	if (userlengh > 5 || userlengh < 2) { printf("Error number!");return 0; } //checking correct input
	ArrayComputer = (int*)malloc(userlengh * sizeof(int)); 
	ArrayUserinverse = (int*)malloc(userlengh * sizeof(int));
	ArrayUser = (int*)malloc(userlengh * sizeof(int));
	while (i < userlengh) {
		x = rand() % 10; //generate random array
		if (x != ArrayComputer[0] & x != ArrayComputer[1] & x != ArrayComputer[2] & x != ArrayComputer[3] & x != ArrayComputer[4]) {
			ArrayComputer[i] = x;i++;}}
	while (exactposition != userlengh) { // Main cicle
		printf("\n\nEnter your number: "); scanf("%d", &usernumber);
		inspection = 0;
		switch (userlengh){ //checking correct input
		case 5: if (usernumber > 99999 || 10000 > usernumber) { printf("\n\nError number, try again!\n\n"); inspection = 1;} break;
		case 4: if (usernumber > 9999 || 1000 > usernumber) { printf("\n\nError number, try again!\n\n"); inspection = 1; } break;
		case 3: if (usernumber > 999 || 100 > usernumber) { printf("\n\nError number, try again!\n\n"); inspection = 1; } break;
		case 2: if (usernumber > 99 || 10 > usernumber) { printf("\n\nError number, try again!\n\n"); inspection = 1; } break;}
		x = userlengh - 1;
		for (i = 0; i < userlengh; i++) { //dividing a number into digits
			ArrayUser[i] = usernumber % 10;
			ArrayUserinverse[x] = usernumber % 10;
			x--;
			usernumber = usernumber / 10;}
		x = exactposition = notexactposition = 0;
		for (i = 0; i < userlengh; i++) { //find bull
			if (ArrayUserinverse[i] == ArrayComputer[i]) {
				if (!inspection) { printf("\nBull detected: %d", ArrayComputer[i]); }
				exactposition += 1;}}
		for (x = 0; x < userlengh; x++) { //find cow
			for (i = 0; i < userlengh; i++) {
				if (ArrayUserinverse[x] == ArrayComputer[i] & ArrayUserinverse[i] != ArrayComputer[i]) {
					if (!inspection) { printf("\nCow detected: %d", ArrayUserinverse[x]); }
					notexactposition += 1;}}}
		if(!inspection){ printf("\n\nCount 'Bull' - %d, count 'Cow' - %d", exactposition, notexactposition); }
	}
	if (!inspection) { printf("\n\nYou win!"); }
	return 0;
}