//Henry Samala
//Psychic Program
//SID #3522
//12.5.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h> 

#define MAX 100

int guessStorage[500], peacefullOdds = 1, easyOdds = 1, normalOdds = 1, hardOdds = 1, failCount;
float oddsPercentage;

bool admin = false, failedAttempt = false, gameWin = false, luckyUser = false;

int digitCheck(char input[]) { //provided integer checker by me (henry samala)
	bool digitInput = true;
	int stringLength;

	stringLength = strlen(input);

	for (int i = 0; i < stringLength; i++) {
		if (isdigit(input[i])) {
			printf("\t[Input Invalid Digit, Please Try Again]\n");
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
			printf("\t[Input Invalid Character, Please Try Again]\n");
			charInput = false;
			break;
		}
	}
	return charInput;
}
int userInputDIGIT(int switchState, int lowerLimit) { //provided digit input by me (henry)
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

		if (switchState == 0) {
			if (valueOutput < 1 || valueOutput > 4) { //change according to input reqiurements
				printf("\t[Input Invalid, Please Try Again]");
				flagInput = false;
			}
		} else if(switchState == 1) {
			if (valueOutput < lowerLimit || valueOutput > 10) { //change according to input reqiurements
				printf("\n\t[Input Invalid, Please Try Again]");
				flagInput = false;
			}
		}
		else if(switchState == 2) {
			if (valueOutput < lowerLimit || valueOutput > 100) { //change according to input reqiurements
				printf("\n\t[Input Invalid, Please Try Again]");
				flagInput = false;
			}
		}
		else if (switchState == 3) {
			if (valueOutput < lowerLimit || valueOutput > 500) { //change according to input reqiurements
				printf("\n\t[Input Invalid, Please Try Again]");
				flagInput = false;
			}
		}
		else if (switchState == 4) {
			if (valueOutput < lowerLimit || valueOutput > 1000) { //change according to input reqiurements
				printf("\n\t[Input Invalid, Please Try Again]");
				flagInput = false;
			}
		}


	} while (!flagInput);
	printf("\n\t[User Inputed Value = %d]\n", valueOutput);
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
			printf("\n\t--------------------------------");
			printf("\n\n\t[Resuming Program...]\n\n");
			break;


		case 'y':
			printf("\n\t--------------------------------");
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
int inputStringChar(char input[]) { //user input character string provided by me (henry samala)
	char tempInput[MAX];
	bool flagInput;

	do {

		flagInput = true;

		printf("\n\tWhat is your name?");
		printf("\n\tInput: ");
		gets(input, sizeof(input));
		flagInput = digitCheck(input);

	} while (!flagInput);
}
int printingString() {
	int testNumber, newRow = 0;
	bool numberTest;

	printf("\n\t");
	printf("Numbers Guessed: ");
	for (int i = 0; i < 500; i++) {

		if (guessStorage[i] == '\0') {
			break;
		}

		testNumber = guessStorage[i];
		numberTest = true;

		numberTest = error_check(guessStorage, i, testNumber, numberTest);

		if (numberTest == false) {
			continue;
		}
		else {
			newRow++;
			if (newRow > 10) {
				printf("\n\t");
				newRow = 0;
			}
			printf("(%d) ", guessStorage[i]);
		}
	}
}
int error_check(int num[], int i, int newNum, bool test) {
	for (int x = 0; x < i; x++) { //for loops checks if generated number is equal to any number in array
		if (num[x] == newNum) {
			test = false;
		}
	}
	return test;
}

int projectIntroduction(char name[]) {
	printf("\n\n\t[Welcome %s to the Psychic Program]", name);
	printf("\n\tDirections: Please follow the prompts on the screen and input accordingly.");
}
int programDifficultySwitch(int userInput, int roundCount) {
	int programStart = 0, userChoice, switchState = 1;

	//printf("\n\tOdd Percentage = %f", oddsPercentage);

	if (failCount > 0) {
		peacefullOdds = 100 * oddsPercentage;
		easyOdds = 100 * oddsPercentage;
		normalOdds = 500 * oddsPercentage;
		hardOdds = 1000 * oddsPercentage;
	}
	else {
		peacefullOdds = 1, easyOdds = 1, normalOdds = 1, hardOdds = 1;
	}

	printf("\n\n\t(Please input an INTEGER to select game difficulty for Round #%d)", roundCount);
	printf("\n\t1 = PEACEFULL %d-10", peacefullOdds);
	printf("\n\t2 = EASY %d-100", easyOdds);
	printf("\n\t3 = NORMAL %d-500", normalOdds);
	printf("\n\t4 = HARD %d-1000\n", hardOdds);

	userChoice = userInputDIGIT(switchState, 0);

	switch (userChoice) {

	case 1:
		printf("\n\t[PEACEFULL Difficulty Selected]"); //3 total tries
		programStart = 1;
		break;

	case 2:
		printf("\n\t[EASY Difficulty Selected]"); //25 total tries
		programStart = 2;
		break;

	case 3:
		printf("\n\t[NORMAL Difficulty Selected]"); //125 total tries 
		programStart = 3;
		break;

	case 4:
		printf("\n\t[HARD Difficulty Selected]"); //250 total tries
		programStart = 4;
		break;

	}

	printf("\n\t----------------------------------------");

	return programStart;
}
int randomNumberGen(int maxTotal, int lowerLimit) {
	int randomNumber;

	randomNumber = (rand() % maxTotal) + lowerLimit; //generates random number from 1 - depending on mode
	if (randomNumber == 0) {
		randomNumber = randomNumber + lowerLimit;
	}

	if (admin) {
		printf("\n\t(Random Generated Number = %d)", randomNumber);
	}

	return randomNumber;
}
int numberGuessing(int maxNumber, int switchCase, int maxGuess, int oddsLimit, int roundTrack) {
	int correctNumber, userInput;
	bool flagInput;

	//printf("\n\t***Testing: maxNumber = %d, SwithcCheck = %d, maxString = %d, maxGuesses = %d, oddsCalculation = %d***", maxNumber, switchCase, maxString, maxGuess, oddsLimit);

	correctNumber = randomNumberGen(maxNumber, oddsLimit);
	//printf("\n\t\t\tTesting Generated Number: %d", correctNumber);

	for (int i = 0; i < 500; i++) {
		guessStorage[i] = '\0';
	}

	printf("\n\t[Choose a number in range, %d - %d]", oddsLimit, maxNumber);

	printf("\n\n\t(Input an INTEGER within displayed RANGE for guess)");
	for (int guessCount = 0; guessCount < maxGuess; guessCount++) {
		printf("\n\t[You have %d total guess left...]", maxGuess - guessCount);

		do {

			userInput = userInputDIGIT(switchCase, oddsLimit);
			guessStorage[guessCount] = userInput;

			flagInput = false;

			for (int guessCheck = 0; guessCheck < guessCount; guessCheck++) {
				if (userInput == guessStorage[guessCheck]) {
					printf("\n\t[You already guessed that number, please try again]");
					flagInput = true;
					break;
				}
			}

		} while (flagInput);

		if (luckyUser == true && roundTrack % 2 == 0) { //only even rounds, the lucky user will win be default anytime
			printf("\n\t[You are Psychic! You Guess the Correct Number (%d)]", userInput);
			failCount = 0;
			gameWin = true;
			break;
		}

		if (guessCount == maxGuess - 1) {
			printf("\n\t[You ran out of Tries! You are not Psychic...]", correctNumber);
			failCount++;
			failedAttempt = true;
			break;
		}

		if (correctNumber == userInput) {
			printf("\n\t[You are Psychic! You Guess the Correct Number (%d)]", correctNumber);
			failCount = 0;
			gameWin = true;
			break;
		}
		else {
			printf("\n\t[Incorrect Guess, Please try Again...]");
		}
		printf("\n\t--------------------------------");

	}
	printingString();
}
int oddsCalculation(int totalFails, bool winnerInput) {

	oddsPercentage = (float)totalFails / 100;
	if (winnerInput == true) {
		printf("\n\t(Difficulty has been reset due to Win)");
	}
	else {
		printf("\n\t(Difficulty has been Decreased by = %.0f%% for all Levels)", oddsPercentage * 100);
	}

}
int testUser(bool input) {
	if (input) {
		printf("\n\t[Lucky User Found!]");
	}
	else {
		printf("\n\t[Not a lucky user...]");
	}
}
int nameCondition(char input[]) {
	int spaceCount = 0, vowelCount = 0, upperCase = 0;
	bool output = false;

	
	//printf("\n\tTesting String Length = %d, User input = %s", strlen(input), input);

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == ' ') {
			spaceCount++;
		}
		else if (input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
			vowelCount++;
		}
		else if (isupper(input[i])) {
			upperCase++;
		}
	}

	if (spaceCount = 1 && vowelCount > 3 && upperCase > 5) {
		output = true;
	}

	//uncomment for testing
	//printf("\n\tTesting: SpaceCount = %d, VowelCount = %d, UpperCase = %d", spaceCount, vowelCount, upperCase);

	return output;
}

int main(void) {
	char userName[MAX];
	bool programContinue;
	int levelOutput, roundsCount = 1, switchCheck;

	srand(time(NULL));

	inputStringChar(userName);

	//Lucky User must input (EXACTLY 1 SPACE, MORE THAN 5 UPPERCASE LETTERS, AND MORE THAN 3 UPPERCASE VOWELS)
	//Lucky user will ALWAYS win on the EVENTH round number.

	luckyUser = nameCondition(userName);
	//testUser(luckyUser); //for testing lucky user

	projectIntroduction(userName);

	admin = true; //comment THIS LINE to NOT view randomly generated numbers
	failCount = 0;

	do {
		programContinue = true;

		//printf("\n\n\t***Testing: FailCount = %d, RoundCount = %d***", failCount, roundsCount);

		if (failedAttempt == true || gameWin == true) {
			oddsCalculation(failCount, gameWin);
		}

		failedAttempt = false, gameWin = false;

		switchCheck = 0;
		levelOutput = programDifficultySwitch(switchCheck, roundsCount);

		switch (levelOutput) {

			//parameters = (MAX LIMIT GUESS, SWTICH STATE, MAX GUESSES, MODE ODDS, ROUND TRACKER)

		case 1: //peacefull mode
			numberGuessing(10, 1, 3, peacefullOdds, roundsCount);
			break;

		case 2: //easy mode
			numberGuessing(100, 2, 25, easyOdds, roundsCount);
			break;

		case 3: //normal mode
			numberGuessing(500, 3, 125, normalOdds, roundsCount);
			break;

		case 4: //hard mode
			numberGuessing(1000, 4, 250, hardOdds, roundsCount);
			break;
		}

		programContinue = programRestart();
		roundsCount++;

	} while (programContinue);

	systemPause();
}
