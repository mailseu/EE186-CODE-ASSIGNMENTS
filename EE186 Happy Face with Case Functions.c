//Henry Samala
//Happy Face with Case Functions
//SID #3522
//11.14.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int userSelections[10];

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
int characterCheck(char input[]) { //provided chracter checker by me (henry samala)
	bool charInput = true;
	int stringLength;

	stringLength = strlen(input);

	for (int i = 0; i < stringLength; i++) {
		if (isalpha(input[i])) {
			printf("\t[Input Invalid, Please Try Again]\n");
			charInput = false;
			break;
		}
	}
	return charInput;
}
int userInputDIGIT() { //provided digit input by me (henry)
	char userInput[10];
	bool flagInput, validInput;
	int valueOutput;

	do {
		flagInput = true;
		validInput = true;

		do {

			printf("\n\n\tInput: ");
			scanf_s("%s", &userInput, 10);
			sscanf_s(userInput, "%d", &valueOutput);

			validInput = characterCheck(userInput);

		} while (!validInput);

		if (valueOutput == 9) {
			return valueOutput;
		}
		else if (valueOutput < 1 || valueOutput > 4) { //change according to input reqiurements
			printf("\t[Input Invalid, Please Try Again]");
			flagInput = false;
		}

	} while (!flagInput);
	printf("\t[User Inputed Value = %d]\n", valueOutput);
	return valueOutput;
}
int userInputCHARACTER() { //provided character input by me (henry)
	char userInput[10], valueOutput;
	bool flagInput, validInput;

	do {
		flagInput = true;
		validInput = true;

		do {

			printf("\n\n\tInput: ");
			scanf_s("%s", &userInput, 10);
			sscanf_s(userInput, "%c", &valueOutput);

			validInput = digitCheck(userInput);

		} while (!validInput);

		if ((valueOutput < 65 || valueOutput > 90) && (valueOutput < 97 || valueOutput > 122)) { //change according to input reqiurements A-Z and a-z (ascii code)
			printf("\t[Input Invalid, Please Try Again]");
			flagInput = false;
		}

	} while (!flagInput);
	printf("\n\t[User Inputed Value = %c]\n", valueOutput);

	return valueOutput;
}
int programRestart() { //provided by me (henry samala)
	char valueOutput;
	char userChoice[10];
	bool validInput, validEnding;

	do {
		validInput = true;

		do {

			printf("\n\n\tWould you like to conitnue program, input Y for YES, input N for NO: ");
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
			break;


		case 'y':
			printf("\n\n\t[Resuming Program...]\n\n");
			break;


		default:
			printf("\n\t[Invalid Input, Please Try Again]\n");
			validInput = false;
		}

	} while (!validInput);

	return validEnding;
}
int systemPause() { // system pause provided by leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
}

int userInputDIGIT2() { //provided digit input by me (henry)
	char userInput[10];
	bool flagInput, validInput;
	int valueOutput;

	do {
		flagInput = true;
		validInput = true;

		do {

			printf("\n\tInput: ");
			scanf_s("%s", &userInput, 10);
			sscanf_s(userInput, "%d", &valueOutput);

			validInput = characterCheck(userInput);

		} while (!validInput);


		if (valueOutput < 1 || valueOutput > 9) { //change according to input reqiurements
			printf("\t[Input Invalid, Please Try Again]");
			flagInput = false;
		}

	} while (!flagInput);
	printf("\t[User Inputed Value = %d]\n", valueOutput);
	return valueOutput;
}
int projectIntroduction() {
	printf("\n\t*****Welcome to the Happy Face with Case Functions Program");
	printf("\n\tDirections: Please follow all prompts on the screen and input accordingly.");
}
int projectChoice() {
	int userTrack = 0, userValue, stringLength;
	bool endOutput = false;

	printf("\n\n\tPlease select one by one which body parts would you like to generate below.");
	printf("\n\tDepending on the selection, a body part may have unqiue parameters:\n");

	printf("\n\t1 = Head");
	printf("\n\t2 = Body");
	printf("\n\t3 = Arms & Hands");
	printf("\n\t4 = Legs & Feet");

	printf("\n\n\t9 = Finished Selection");

	do {

	InputStart:

		userValue = userInputDIGIT();

		if (userValue == 9) {
			endOutput = true;
		}
		for (int i = 0; i < userTrack; i++) {
			if (userValue == userSelections[i]) {
				printf("\t[Matching Selection, Please try Again...]");
				goto InputStart;
			}
		}
		userSelections[userTrack] = userValue;
		userTrack++;

	} while (!endOutput);

	printf("\n\tSelections = ");
	for (int i = 0; i < userTrack; i++) {
		printf("%d ", userSelections[i]);
	}
	printf("\n");

	return userTrack;
}
int bodyVariables(int repeat, int *output2, int *output3, int *output4) {
	int tempValue;

	for (int i = 0; i < repeat; i++) {
		tempValue = userSelections[i];

		switch (tempValue) {

		case 2: //body
			printf("\n\tPlease input an integer for the length of body (1-9)");
			*output2 = userInputDIGIT2();
			break;

		case 3: //arms
			printf("\n\tPlease input an integer for the length of arms (1-9)");
			*output3 = userInputDIGIT2();
			break;

		case 4: //legs
			printf("\n\tPlease input an integer for the length of legs (1-9)");
			*output4 = userInputDIGIT2();
			break;

		case 9:
			printf("\n\t[Generating Picture...]");
			break;
		}
	}
}
int bodyOutput(int repeat, int body, int arm, int leg) {
	int tempValue;

	printf("\n\n");
	for (int i = 0; i < repeat; i++) { //head
		if (userSelections[i] == 1) {
			printf("\t\t//////////\n");
			printf("\t\t|--------|\n");
			printf("\t\t| _    _ |\n");
			printf("\t\t| *    * |\n");
			printf("\t\t|    L   |\n");
			printf("\t\t|  _____ |\n");
			printf("\t\t|--------|\n");
		}
	}
	for (int i = 0; i < repeat; i++) { //arm
		if (userSelections[i] == 3) {
			printf("\t");
			for (int a = 0; a < body; a++) {
				printf("=====");
			}
		}
	}
	for (int i = 0; i < repeat; i++) { //body
		if (userSelections[i] == 2) {
			printf("\n");
			for (int a = 0; a < arm; a++) {
				printf("\t\t    ||\n");
				printf("\t\t    ||\n");
			}
		}
	}
	for (int i = 0; i < repeat; i++) { //leg
		if (userSelections[i] == 4) {
			printf("\t\t============\n");
			for (int a = 0; a < leg; a++) {
				printf("\t\t||        ||\n");
				printf("\t\t||        ||\n");
			}
			printf("\t       _||        ||_\n");
		}
	}
}

int main(void) {
	int selectionTrack, bodyValue, armValue, legValue;
	bool programContinue;

	projectIntroduction();

	do {
		programContinue = true;

		selectionTrack = projectChoice();
		bodyVariables(selectionTrack, &bodyValue, &armValue, &legValue);
		bodyOutput(selectionTrack, bodyValue, armValue, legValue);

		programContinue = programRestart();

	} while (programContinue);

	systemPause();

}
