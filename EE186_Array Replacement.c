#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int errorCheck(char num[], int i, char newNum, bool test) { //provided by henry (me)
	for (int x = 0; x < i; x++) {
		if (num[x] == newNum) {
			test = false;
		}
	}
	return test;
}
int uniqueNumbers(char num[]) { //provided by henry (me)
	char newNum;
	bool test;

	for (int i = 0; i < 6; i++) {
		do {
			newNum = (rand() % 12) + 1;
			test = true;
			test = errorCheck(num, i, newNum, test);

		} while (!test);
		num[i] = newNum;
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

		flag = characterCheck(userInput, flag);
		if (!flag) {
			goto InputStart;
		}
		else if (value < 1 || value > 12) {
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
		}

	} while (!flag);
	printf("\t[User Inputed Value = %d]\n", value);
	return value;
}
int userCharInput() {
	char charInput;
	bool flag;

	do {

		flag = true; 
		printf("\n\n\tInput: ");
		scanf_s(" %c", &charInput);

		if (isdigit(charInput)) {
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
		}
	} while (!flag);
	printf("\t[User Inputed Character = %c]\n", charInput);
	return charInput;
}
int characterCheck(char input[], bool flag) { //provided chracter checker by (me)
	for (int i = 0; input[i] != '\0'; i++) {
		if (isalpha(input[i])) {
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
			break;
		}
	}
	return flag;
}
int outputNumbers(char num[]) {
	printf("\tNumber Output:\t");
		
	for (int count = 0; count < 6; count++) {
		if (isalpha(num[count])) {
			printf("%c\t", num[count]); //displays number in array according to count
		}
		else {
			printf("%d\t", num[count]);
		}
	}
}
int multipleExchange(char num[], int multipleValue, char characterChange) {
	int test;
	int i = multipleValue;
	char a = characterChange;
	for (int x = 0; x < 6; x++) {
		test = num[x] - '0';
		if (test % 1 == 0) {
			num[x] = a;
		}
	}
}

int main(void) {
	int userValue;
	char randomValues[6];
	char userCharacter;

		srand(time(NULL));

	printf("\n\tPlease input an integer from 1-12:");
	userValue = userInput();

	printf("\n\n\tPlease input a character from A-Z:");
	userCharacter = userCharInput();

	uniqueNumbers(randomValues);
	printf("\n\t[Before Values]");
	outputNumbers(randomValues);

	multipleExchange(randomValues, userValue, userCharacter);
	printf("\n\t[After Values]");
	outputNumbers(randomValues);

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
	//system pause -- leo
}	
