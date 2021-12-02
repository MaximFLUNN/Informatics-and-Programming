#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() { // Powered by MaximFLUNN (Maxim Filatov 3821B1PR2) Game: Bull and cow :)
	int x, i, inspect, n, usernumber, userlengh = 5, invalid, correct, correctfinal, inspection, exitprogramm, notexactposition, exactposition;
	x = i = inspect = invalid = correct = correctfinal = inspection = exitprogramm = notexactposition = exactposition = 0;
	int* ArrayComputer = (int*)malloc(userlengh * sizeof(int)); 
	int* ArrayUserinverse = (int*)malloc(userlengh * sizeof(int));
	char try = ' ';
	srand(time(NULL));
	while (exactposition != userlengh) { // Main cycle
		if (exitprogramm == 0) {
			while (correctfinal == 0) { // Cycle input lenght number 2-5
				correctfinal++;
				printf("Enter length number (2-5): ");
				scanf("%d", &userlengh);
				if (userlengh > 5 || userlengh < 2) { 
					printf("\nError number, try again!\n\n");
					correctfinal--;
				} 
			}
			ArrayComputer = (int*)malloc(userlengh * sizeof(int));
			ArrayUserinverse = (int*)malloc(userlengh * sizeof(int));
			while (inspection < userlengh) { // Filling the array (Computer)
				n = 0;
				x = rand() % 10;
				for (i = 0; i < userlengh; i++) {
					if (x != ArrayComputer[i]) {
						n++;
					}
					if (n == userlengh) {
						ArrayComputer[inspection] = x;
						inspection++;
					}
				}
			}
			exitprogramm = 1;
		}
		printf("\n\nEnter your number: "); scanf("%d", &usernumber);
		correct = usernumber;
		inspection = n = 0;
		x = userlengh - 1;
		for (i = 0; i < userlengh; i++) { // Dividing a number into digits
			ArrayUserinverse[x] = usernumber % 10;
			x--;
			usernumber = usernumber / 10;}
		for (x = 0; x < userlengh; x++) { // Search duplicate numbers
			for (i = 0; i < userlengh; i++) {
				if (ArrayUserinverse[x] == ArrayUserinverse[i]) {
					n++;
				}
			}
			if (n != userlengh & x == userlengh - 1) {
				printf("\nDuplicate numbers found, try again!\n");
				inspection = 1;
			}
		}
		x = exactposition = notexactposition = 0;
		correctfinal = 0;
		for (i = 0; i < userlengh; i++) { // Ñhecking the correctness of the number
			correctfinal *= 10;
			correctfinal += ArrayUserinverse[i];
		}
		if (correct != correctfinal & inspection == 0) {
			printf("\nInput invalid number!");
			inspection = 1;
		}
		for (i = 0; i < userlengh; i++) { // Search bull
			if (ArrayUserinverse[i] == ArrayComputer[i]) {
				if (!inspection) { 
					printf("\nBull detected: %d", ArrayComputer[i]); 
				}
				exactposition += 1;
			}
		}
		for (x = 0; x < userlengh; x++) { // Search cow
			for (i = 0; i < userlengh; i++) {
				if (ArrayUserinverse[x] == ArrayComputer[i] & ArrayUserinverse[i] != ArrayComputer[i]) {
					if (!inspection) { 
						printf("\nCow detected: %d", ArrayUserinverse[x]); 
					}
					notexactposition += 1;
				}
			}
		}
		if(!inspection){ 
			printf("\n\nCount 'Bull' - %d, count 'Cow' - %d", exactposition, notexactposition); 
		}
		if (exactposition == userlengh & !inspection) {
			printf("\n\nYou win!");
			printf("\n\nDo you want to play more?\nInput character (Y - yes , N - no)\n->");
			while (try != 'Y' || try != 'N') { // Cicle continue or break
				scanf("\n%c", &try);
				if (try == 'Y') {
					printf("\n\nContinue");
					exactposition = userlengh - 1;
					exitprogramm = correctfinal = 0;
					break;
				}
				else if (try == 'N') {
					printf("\n\nExit\n\n\n");
					break;
				}
				else {
					printf("\n\nInvalid character, try again! (Y - yes , N - no)\n-> ");
				}
			}
		}
	}
}

