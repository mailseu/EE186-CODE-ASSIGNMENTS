//Henry Samala
//Rigged Machine Using Case 
//SID #3522
//11.9.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char userInput[100];
char voteStorage[5][5];
int voteTrack = 1;

int characterCheck(char input[]) { //provided chracter checker by me (henry)
	bool charInput = true;

	for (int i = 0; input[i] != '\0'; i++) {
		if (isalpha(input[i])) {
			printf("\t[Input Invalid, Please Try Again]");
			charInput = false;
			break;
		}
	}
	return charInput;
}
int digitCheck(char input[]) { //provided integer checker by me (henry)
	bool digitInput = true;

	for (int i = 0; input[i] != '\0'; i++) {
		if (isdigit(input[i])) {
			printf("\t[Input Invalid, Please Try Again]\n");
			digitInput = false;
			break;
		}
	}
	return digitInput;
}
int programRestart() { //provided by me (henry)
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

int programIntroduction() {
	printf("\n\t[Welcome to the Rigged Machine Program]");
	printf("\n\tDirections: Please follow the prompt(s) on the screen and input accordingly.");
}
int voteInputTest(char input[]) {
	bool flagInput = true;
	
	for (int i = 0; i < 5; i++) {
		if (input[i] == 'n' || input[i] == 'y') {
			continue;
		}
		else {
			flagInput = false;
		}
	}
	return flagInput;
}
int userInputVote() { //provided character input by me (henry)
	bool flagInput;

	do {

	InputStart:

		flagInput = true;
		printf("\n\t(PROPOSITION VOTE #%d)", voteTrack);
		printf("\n\tInput: ");
		scanf_s("%s", &userInput, 100);
		flagInput = digitCheck(userInput);

	} while (!flagInput);

	if (strlen(userInput) != 5) {
		printf("\t[Input Invalid, Please Try Again]\n");
		goto InputStart;
	}
	else if (voteInputTest(userInput) == false) {
		printf("\t[Input Invalid, Please Try Again]\n");
		goto InputStart;
	}
	printf("\t[Inputed Vote = %s]\n", userInput);
	voteTrack++;
	
}
int matrixPlacement(char input[], int voteTracker) {
	for (int i = 0; i < 5; i++) {
		voteStorage[voteTracker][i] = input[i];
	}
}
int printingMatrix(char input[5][5]) {
	for (int i = 0; i < 5; i++) {
		printf("\n\t");
		for (int x = 0; x < 5; x++) {
			printf("%c ", input[i][x]);
		}
	}
}
int calculatingVotes() {
	int yesTally, noTally, voteOutcome, propCount = 1;
	int riggedYes, riggedNo;

	for (int i = 0; i < 5; i++) {

		yesTally = 0;
		noTally = 0;
		riggedYes = 0;
		riggedNo = 0;

		for (int a = 0; a < 5; a++) {
			if (voteStorage[i][a] == 'y') {
				yesTally++;
			}
			else {
				noTally++;
			}
		}
		if (yesTally > noTally) {
			voteOutcome = 1;
		}
		else {
			voteOutcome = 0;
		}
		
		for (int x = 0; x < 5;) {
			if (voteStorage[i][x] == 'y') {
				riggedYes++;

			}
			else if (voteStorage[i][x] == 'n') {
				riggedNo++;
			}
			x = x + 4;
		}
		if (riggedYes == 2) {
			voteOutcome = 2;
		}
		else if (riggedNo == 2) {
			voteOutcome = 3;
		}
		resultOutcome(voteOutcome, i, propCount);
		propCount++;
	}
}
int resultOutcome(int results, int row, int count) {

	printf("\n\tProposition (%d) =  ", count);

	switch (results) {

	case 1: //pass
		for (int i = 0; i < 5; i++) {
			printf("%c ", voteStorage[row][i]);
		}
		printf("[HAS PASSED]");
		break;

	case 0: //fail
		for (int i = 0; i < 5; i++) {
			printf("%c ", voteStorage[row][i]);
		}
		printf("[HAS FAILED]");
		break;


	case 2: //rigged pass
		for (int i = 0; i < 5; i++) {
			printf("%c ", voteStorage[row][i]);
		}
		printf("[HAS PASSED]");
		break;


	case 3: //rigged fail
		for (int i = 0; i < 5; i++) {
			printf("%c ", voteStorage[row][i]);
		}
		printf("[HAS FAILED]");
		break;
	}
}

int main(void) {
	bool programContinue = true;


	programIntroduction();
	
	do {

		printf("\n\n\tTo vote, please input a random set of 5 (y)'s and (n)'s for each propositions.\n");
		for (int count = 0; count < 5; count++) {
			userInputVote();
			matrixPlacement(userInput, count);
		}
		calculatingVotes();

		voteTrack = 1;

		programContinue = programRestart();

	} while (programContinue);

	systemPause();
	return 0;
}
