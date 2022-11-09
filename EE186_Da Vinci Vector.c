//Henry Samala
//Da Vinci Vector
//SID #3522
//11.7.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

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
int systemPause() {
	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
	//system pause -- leo
}
int projecDescription() {
	printf("\n\n\tHow are you doing today in at least 5 words? (100 Characters Max)");
	printf("\n\tInput: ");
}
int printArray(char input[], int array) {

	printf("\n\t[Original Order]\n\t");
	for (int i = 0; i < array; i++) {
		printf("%c", input[i]);
	}
	printf("\n\n\t[Reversed Order]\n\t");
	for (int x = array - 2; x >= 0; x--) {
		printf("%c", input[x]);
	}
}
int testWords(char input[], int array) {
	bool flag = true;
	int count = 0;

	for (int i = 0; i < array; i++) {
		if (input[i] == 32) {
			count++;
		}
	}
	if (count < 4) {
		flag = false;
		printf("\n\t[Less than 5 words inputed, please try again]");
	}
	return flag;
}

int main(void) {
	char userInput[100];
	int arrayValue = 0;
	bool programContinue = true, testing;

	printf("\n\n\tDirections: Please follow the prompts on the screen and input accordingly");

	do {

		testing = true;

		do {

			projecDescription();
			fgets(userInput, sizeof(userInput), stdin);
			arrayValue = strlen(userInput);
			testing = testWords(userInput, arrayValue);

		} while (testing == false);

		printArray(userInput, arrayValue);
		programContinue = programRestart();

	} while (programContinue == true);

	systemPause();
	return 0;
}
