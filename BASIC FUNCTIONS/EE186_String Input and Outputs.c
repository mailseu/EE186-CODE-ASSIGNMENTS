#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int inputStringChar(char input[]) { //user input character string provided by me (henry samala)
	bool flagInput;

	do {

		flagInput = true;

		printf("\n\tInput: ");
		fgets(input, 100, stdin);
		flagInput = digitCheck(input);

	} while (!flagInput);

	printf("\n\tOutput: %s", input);
}
int inputStringInt(char input[]) { //user input digit string provided by me (henry samala)
	bool flagInput;

	do {

		flagInput = true;

		printf("\n\tInput: ");
		fgets(input, 100, stdin);
		flagInput = characterCheck(input);

	} while (!flagInput);

	printf("\n\tOutput: %s", input);
}
int reversedStringInputOutput(char input[]) { //reversed string output provided by me (henry samala)
	int stringLength;
	bool flagInput;

	do {

		flagInput = true;

		printf("\n\tInput: ");
		fgets(input, 100, stdin);
		flagInput = digitCheck(input); //change depending on contraints

	} while (!flagInput);

	printf("\n\tOutput: %s", input);

	stringLength = strlen(input);

	printf("\n\t[Reversed Order]\n\t");
	for (int x = stringLength - 2; x >= 0; x--) {
		printf("%c", input[x]);
	}
}
int uniqueString(int input[]) {
	int newNum;
	bool testOutput;

	for (int i = 0; i < 10; i++) { //generates number according to i count
		do {
			newNum = (rand() % 10) + 1; //generates random number from 1- 60
			testOutput = true;
			testOutput = errorCheckRandom(input, i, newNum, testOutput);

		} while (!testOutput);

		input[i] = newNum; //places number into array
	}
}
int errorCheckRandom(int input[], int count, int newNum, bool numberCheck) {
	for (int x = 0; x < count; x++) { //for loops checks if generated number is equal to any number in array
		if (input[x] == newNum) {
			numberCheck = false;
		}
	}
	return numberCheck;
}
int printingString(int input[]) {
	
	printf("\n\t");
	for (int i = 0; i < sizeof(input); i++) {
		printf("%d", input[i]);
	}
}
