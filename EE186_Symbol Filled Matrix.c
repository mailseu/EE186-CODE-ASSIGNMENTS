//Henry Samala
//Symbol Filled Matrix
//SID #3522
//11.9.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int userRows, userColumns;
char matrixBackground, matrixDiagonal;

int userInputDIGIT() {
	char userInput[10];
	bool flag;
	int value;

	do {

	InputStart:

		flag = true;

		printf("\n\tInput: ");
		scanf_s("%s", &userInput, 10);
		sscanf_s(userInput, "%d", &value);

		flag = characterCheck(userInput);
		if (!flag) {
			goto InputStart;
		}
		else if (value < 1 || value > 7) {
			printf("\n\t[Input Invalid, Please Try Again]\n");
			flag = false;
		}

	} while (!flag);
	printf("\n\t[User Inputed Value = %d]\n", value);
	return value;
}
int characterCheck(char input[]) { //provided chracter checker by me (henry)
	bool flag = true;

	for (int i = 0; input[i] != '\0'; i++) {
		if (isalpha(input[i])) {
			printf("\n\t[Input Invalid, Please Try Again]\n");
			flag = false;
			break;
		}
	}
	return flag;
}
int userInputCHARACTER() {
	char userInput[10];
	bool flag;
	char value;

	do {

	InputStart:

		flag = true;

		printf("\n\tInput: ");
		scanf_s("%s", &userInput, 10);
		sscanf_s(userInput, "%c", &value);

		flag = digitCheck(userInput);
		if (!flag) {
			printf("\n\t[Input Invalid, Please Try Again]\n");
			goto InputStart;
		}

	} while (!flag);
	printf("\n\t[User Inputed Value = %c]\n", value);
	return value;
}
int userInputSYMBOL() {
	char userInput[10];
	bool flag;
	char value;

	do {

	InputStart:

		flag = true;

		printf("\n\tInput: ");
		scanf_s("%s", &userInput, 10);
		sscanf_s(userInput, "%c", &value);

		flag = digitCheck(userInput);
		if (!flag) {
			goto InputStart;
		}
		else if ((value < 33 || value > 46) && (value < 58 || value > 64)) {
			printf("\n\t[Input Invalid, Please Try Again]\n");
			flag = false;
		}

	} while (!flag);

	printf("\n\t[User Inputed Value = %c]\n", value);
	return value;
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
int systemPause() {
	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
	//system pause -- leo
}

int projectIntroduction() {
	printf("\n\t ***** Welcome to the Symbol Filled Matrix Program *****");
	printf("\n\n\tDirections: Please follow the prompts on the screen and input accordingly\n");
}
int userInputs() {
	printf("\n\tPlease input an INTEGER 1-7 to determine the amount of ROWS for the matrix.");
	userRows = userInputDIGIT();

	printf("\n\tPlease input an INTEGER 1-7 to determine the amount of ROWS for the matrix.");
	userColumns = userInputDIGIT();

	printf("\n\tPlease input a single CHARACTER to determine the BACKGROUND for the matrix.");
	matrixBackground = userInputCHARACTER();

	printf("\n\tPlease input a single SYMBOL to determine the DIAGNOL for the matrix.");
	printf(" Example: (!,@,#,$...)");
	matrixDiagonal = userInputSYMBOL();
}
int matrixManipulation() {
	char matrix[7][7];

	for (int i = 0; i < userRows; i++) {
		for (int x = 0; x < userColumns; x++) {
			matrix[i][x] = matrixBackground;
		}
	}
	printf("\n\n\t[Matrix Unmodified]");
	printingMatrix(matrix);

	for (int i = 0; i < userRows; i++) {
		for (int x = 0; x < userColumns; x++) {
			if (i == x) {
				matrix[i][x] = matrixDiagonal;
			}
		}
	}
	printf("\n\n\t[Matrix Modified]");
	printingMatrix(matrix);
}
int printingMatrix(char input[7][7]) {
	for (int i = 0; i < userRows; i++) {
		printf("\n\t");
		for (int x = 0; x < userColumns; x++) {
			printf("%c  ", input[i][x]);
		}
	}
}

int main(void) {
	bool programContinue = true;

	projectIntroduction();

	do {

		userInputs();
		matrixManipulation();

		programContinue = programRestart();

	} while (programContinue == true);

	systemPause();
}
