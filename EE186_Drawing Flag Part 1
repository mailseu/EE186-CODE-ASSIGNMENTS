//Henry Samala
//Drawing Flag Assignment Part 1
//SID #3522
//11.15.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int systemPause() { // system pause provided by leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
}
int programRestart() { //provided by me (henry samala)
	char valueOutput;
	char userChoice[10];
	bool validInput, validEnding;

	do {
		validInput = true;

		do {

			printf("\n\n\tWould you like to be patriotic again, input Y for YES, input N for NO: ");
			scanf_s("%s", &userChoice, 10);
			sscanf_s(userChoice, "%c", &valueOutput);

			validInput = digitCheck(userChoice);

		} while (!validInput);

		validEnding = true;

		switch (valueOutput) {

		case 'N':
			printf("\n\n\t[Exiting Program...]\n\n");
			validEnding = false;
			break;

		case 'n':
			printf("\n\n\t[Exiting Program...]\n\n");
			validEnding = false;
			break;

		case 'Y':
			printf("\n\n\t[Resuming Program...]\n\n");
			system("pause");
			break;


		case 'y':
			printf("\n\n\t[Resuming Program...]\n\n");
			system("pause");
			break;


		default:
			printf("\n\t[Invalid Input, Please Try Again]\n");
			validInput = false;
		}

	} while (!validInput);

	return validEnding;
}
int digitCheck(char input[]) { //provided integer checker by me (henry samala)
	bool digitInput = true;
	int stringLength;

	stringLength = strlen(input);

	for (int i = 0; i < stringLength; i++) {
		if (isdigit(input[i])) {
			printf("\t[Input Invalid, Please Try Again]\n");
			digitInput = false;
			break;
		}
	}
	return digitInput;
}
int drawFlag(char input[10][40]) {
	for (int i = 0; i < 10; i++) {
		printf("\n\t");
		for (int a = 0; a < 40; a++) {
			printf("%c", input[i][a]);
		}
	}
}

int main(void) {
	bool programContinue;
	char flagMatrix[10][40] =
	{ "**********-----------------------------",
	"**********-----------------------------",
	"**********-----------------------------",
	"**********-----------------------------",
	"**********-----------------------------",
	"---------------------------------------",
	"---------------------------------------",
	"---------------------------------------",
	"---------------------------------------",
	"---------------------------------------"};

	do {
		programContinue = true;
		drawFlag(flagMatrix);
		programContinue = programRestart();

	} while (programContinue);

	systemPause();

}
