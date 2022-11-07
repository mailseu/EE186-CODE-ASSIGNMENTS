//Henry Samala
//Modify Matrix In Class Assignment
//SID #3522
//11.2.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int userInputDIGIT() {
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
		else if (value < 1 || value > 3) { //change according to range
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
		}

	} while (!flag);
	printf("\t[User Inputed Value = %d]\n", value);
	return value;
}
int userInputCHARACTER() {
	char userInput[10];
	bool flag;
	int value;

	do {

	InputStart:

		flag = true;

		printf("\n\n\tInput: ");
		scanf_s("%s", &userInput, 10);
		sscanf_s(userInput, "%d", &value);

		flag = digitCheck(userInput);
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

int taskSwitch(int userChoice, char num[6][6]) {

	switch (userChoice) {

	case 1:
		printf("\n\n\t[Option 1 Selected]");
		for (int i = 0; i < 6; i++) {
			for (int x = 0; x < 6; x++) {
				if (isdigit(num[i][x])) {
					if (num[i][x] % 2 == 0) {
						num[i][x] = 'E';
					}
				}
			}
		}
		break;
	case 2:
		printf("\n\n\t[Option 2 Selected]");
		for (int i = 0; i < 6; i++) {
			for (int x = 0; x < 6; x++) {
				if (isdigit(num[i][x])) {
					if (num[i][x] % 2 != 0) {
						num[i][x] = 'O';
					}
				}
			}
		}
		break;
	case 3:
		printf("\n\n\t[Option 3 Selected]");
		for (int i = 0; i < 6; i++) {
			for (int x = 0; x < 6; x++) {
				if (isdigit(num[i][x])) {
					if (num[i][x] % 3 == 0) {
						num[i][x] = '9';
					}
				}
			}
		}
		break;
	}
}
int printingMatrix(char num[6][6]) {
	for (int i = 0; i < 6; i++) {
		printf("\n\t");
		for (int x = 0; x < 6; x++) {
			
			printf("%c      ", num[i][x]);
		}
	}
}
int prorgramIntrodcion() {
	printf("\n\tPlease Choose your Selection");
	printf("\n\t1 = Replace even numbers with E");
	printf("\n\t2 = Replace odd numbers with O");
	printf("\n\t3 = Replace integers divisible by 3 with 9");
}

int main(void) {
	int userSelection;
	bool programContinue = true;
	char matrix[6][6] = {
	"147dh7",
	"23406g",
	"nyTRYx",
	"QGp50t",
	"Ase37m",
	"198mb3"};

	do {
		prorgramIntrodcion();
		userSelection = userInputDIGIT();

		printf("\n\t[Before Results Matrix]");
		printingMatrix(matrix);

		taskSwitch(userSelection, matrix);

		printf("\n\n\t[After Results Matrix]");
		printingMatrix(matrix);

		programContinue = programRestart();

	} while (programContinue);

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
	//system pause -- leo

	return 0;
}

