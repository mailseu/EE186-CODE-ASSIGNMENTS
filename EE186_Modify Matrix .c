//Henry Samala
//Modify Matrix Code
//SID #3522
//10.26.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int randomMatrix(int num[2][10]) {
	for (int i = 0; i < 2; i++) {
		for (int x = 0; x < 10; x++) {
			num[i][x] = (rand() % 9) + 1;
		}
	}
}
int printingMatrix(int num[2][10]) {
	for (int i = 0; i < 2; i++) {
		printf("\n\t");
		for (int x = 0; x < 10; x++) {
			printf("%d ", num[i][x]);
		}
	}
}
int userInput() {
	char userInput[10];
	bool flag;
	int value;

	do {

	InputStart:

		flag = true;

		printf("\n\n\tInput: ");
		scanf_s("%s", &userInput, 10);
		sscanf_s(userInput, "%d", &value);

		flag = characterCheck(userInput);
		if (!flag) {
			goto InputStart;
		}
		else if (value < 0 || value > 9) {
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
		}

	} while (!flag);
	printf("\t[User Inputed Value = %d]\n", value);
	return value;
}
int multipleExchange(int num[2][10], int multipleValue, int numberChange) {
	for (int i = 0; i < 2; i++) {
		for (int x = 0; x < 10; x++) {
			if (num[i][x] % multipleValue == 0) {
				num[i][x] = numberChange;
			}
		}
	}
}
int characterCheck(char input[]) { //provided chracter checker by me (henry)
	bool flag = true;
	
	for (int i = 0; input[i] != '\0'; i++) {
		if (isalpha(input[i])) {
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
			break;
		}
	}
	return flag;
}
int digitCheck(char input[]) { //provided integer checker by me (henry)
	bool flag = true;
	
	for (int i = 0; input[i] != '\0'; i++) {
		if (isdigit(input[i])) {
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
			break;
		}
	}
	return flag;
}
int programRestart() { //provided by me (henry)
	char value;
	char userChoice[10];
	bool test, ending = true;

InputStart:

	do {
		test = true;

		printf("\n\n\tWould you like to conitnue program, input Y or y for YES, input N or n for NO: ");
		scanf_s("%s", &userChoice, 10);
		sscanf_s(userChoice, "%c", &value);

		test = digitCheck(userChoice);

	} while (!test);

	switch (value) {

	case 'N':
		printf("\n\n\t[Exiting Program...]\n\n");
		ending = false;
		break;

	case 'n':
		printf("\n\n\t[Exiting Program...]\n\n");
		ending = false;
		break;

	case 'Y':
		printf("\n\n\t[Resuming Program...]\n\n");
		break;


	case 'y':
		printf("\n\n\t[Resuming Program...]\n\n");
		break;


	default:
		printf("\n\t[Invalid Input, Please Try Again]\n");
		goto InputStart;
	}
	return ending;
}
int main(void) {
	int programMatrix[2][10];
	int userMultiple, userExchange;
	bool programContinue;

	srand(time(NULL));

	do {

		programContinue = true;

		printf("\n\tDirections: This will be used to check if a number from matrix is a multiple.");
		printf("\n\tPlease input an integer from 0 - 9:");
		userMultiple = userInput();

		printf("\n\tDirections: This will be used to replace the number if a number from matrix is a multiple.");
		printf("\n\tPlease input a integer from 0 - 9:");
		userExchange = userInput();

		printf("\n\t[Before Matrix Output]");
		randomMatrix(programMatrix);
		printingMatrix(programMatrix);

		printf("\n\n\t[After Matrix Output] (User Inputed Multiple = %d) (User Inputed Replacement = %d)", userMultiple, userExchange);
		multipleExchange(programMatrix, userMultiple, userExchange);
		printingMatrix(programMatrix);

		programContinue = programRestart();

	} while (programContinue == true);

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
	//system pause -- leo

	return 0;
}
