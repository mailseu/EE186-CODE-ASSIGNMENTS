//Henry Samala
//Modify Matrix Assignment 2
//SID #3522
//11.7.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char tempMatrix[6][6];
char matrix[6][6] = {
	"147dE7",
	"23406g",
	"nOTRYx",
	"QGp50t",
	"AseE7m",
	"198mbO" };

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
		} if (value == 9) {
			continue;
		}
		else if (value < 1 || value > 6) {
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
		projectIntroductionChoice();
		break;


	case 'y':
		printf("\n\n\t[Resuming Program...]\n\n");
		projectIntroductionChoice();
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
	printf("\n\t****** Welcome to the Modify Matrix Program ******");
	printf("\n\n\tDirections: Please follow the prompts on the screen and input accordingly\n");
}
int projectIntroductionChoice() {
	printf("\n\tInput an integer to choose one the following to do:");
	printf("\n\t1 = Count number of integers, lower, and upper case letters w/printout for each one");
	printf("\n\t2 = Replace all uppercase E and O with z");
	printf("\n\t3 = Replace all even integers with letter E");
	printf("\n\t4 = Reaplce all odd integers with letter O");
	printf("\n\t5 = Sum of all integers (not letters)");
	printf("\n\t6 = Replace diagonal with character 'number'");
	printf("\n\n\t9 = Reset matrix to original");
}
int printingMatrix(char num[6][6]) {
	for (int i = 0; i < 6; i++) {
		printf("\n\t");
		for (int x = 0; x < 6; x++) {
			printf("%c        ", num[i][x]);
		}
	}
}
int taskSwitch(int userChoice, char num[6][6]) {

	switch (userChoice) {

	case 1:
		printf("\n\n\t[Option 1 Selected] (Count number of integers, lower, and upper case letters w/printout for each one)");
		countingNumbers(num);
		break;
	case 2:
		printf("\n\n\t[Option 2 Selected] (Replace all uppercase E and O with z)");
		replaceEandO(num);
		break;

	case 3: 
		printf("\n\n\t[Option 3 Selected] (Replace all even integers with letter E)");
		evenIntegers(num);
		break;
	case 4:
		printf("\n\n\t[Option 4 Selected] (Reaplce all odd integers with letter O)");
		oddIntegers(num);
		break;

	case 5:
		printf("\n\n\t[Option 5 Selected] (Sum of all integers (not letters))");
		sumIntegers(num);
		break;

	case 6:
		printf("\n\n\t[Option 6 Selected] (Replace diagonal with character 'number')");
		diagonalReplacement(num);
		break;
	case 9:
		printf("\n\t[Option 9 Selected] (Reseting to orginial matrix)");
		tempToOrginal(matrix);
		break;
	}
}
int countingNumbers(char num[6][6]) {
	int integerCount = 0, lowerCount = 0, upperCount = 0;

	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 6; x++) {
			if (isdigit(num[i][x])) {
				integerCount++;
				continue;
			} 
			else if (isalpha(num[i][x])) {
				if (num[i][x] >= 97 && num[i][x] <= 122) {
					lowerCount++;
					continue;
				} else if (num[i][x] >= 65 && num[i][x] <= 90) {
					upperCount++;
				}

			}
		}
	}
	printf("\n\n\t[Integer Count = %d]", integerCount);
	printf("\n\t[Lower Case Count = %d]", lowerCount);
	printf("\n\t[Upper Case Count = %d]", upperCount);
}
int replaceEandO(char num[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 6; x++) {
			if (num[i][x] == 69 || num[i][x] == 79) {
				num[i][x] = 'Z';
			}
		}
	}
}
int evenIntegers(char num[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 6; x++) {
			if (isdigit(num[i][x])) {
				if (num[i][x] % 2 == 0) {
					num[i][x] = 'E';
				}
			}
		}
	}
}
int oddIntegers(char num[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 6; x++) {
			if (isdigit(num[i][x])) {
				if (num[i][x] % 2 != 0) {
					num[i][x] = 'O';
				}
			}
		}
	}
}
int sumIntegers(char num[6][6]) {
	int value = 0, sum = 0;

	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 6; x++) {
			if (isdigit(num[i][x])) {
				value = num[i][x] - '0';
				sum = sum + value;
			}
		}
	}
	printf("\n\n\t[Sum of Integers = %d]", sum);
}
int diagonalReplacement(char num[6][6]) {
	char replacement[6] = {"number"};

	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 6; x++) {
			if (i == x) {
				num[i][x] = replacement[i];
			}
		}
	}
}
int tempToOrginal(char num[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 6; x++) {
			tempMatrix[i][x] = matrix[i][x];
		}
	}
}

int main(void) {
	int userSelection;
	bool programContinue = true;

	projectIntroduction();
	projectIntroductionChoice();

	printf("\n\n\t[Original Matrix]");
	printingMatrix(matrix);

	tempToOrginal(matrix);

	do {
		userSelection = userInputDIGIT();

		taskSwitch(userSelection, tempMatrix);

		printf("\n\n\t[After Results Matrix]");
		printingMatrix(tempMatrix);

		programContinue = programRestart();

	} while (programContinue = true);


	systemPause();
	return 0;

}
