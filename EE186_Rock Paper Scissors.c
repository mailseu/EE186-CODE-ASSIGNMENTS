//Henry Samala
//Rock Paper Scissors
//SID #3522
//10.31.22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

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
int userInput() {
	char userChoice[10];
	int value;
	bool flag;

	do {
	
	InputStart:

		flag = true;

		printf("\n\n\tInput: ");
		scanf_s("%s", &userChoice, 10);
		sscanf_s(userChoice, "%d", &value);
		
		flag = characterCheck(userChoice, flag); 
		if (!flag) {
			goto InputStart;
		} else if (value < 1 || value > 3) {
			printf("\t[Input Invalid, Please Try Again]");
			flag = false;
		}
	} while (!flag);

	printf("\t(Inputed Value = %d)\n", value);
	return value;
}
int computerSelection() {
	int num = rand() % 3 + 1;
	//printf("\n\tDEBUGGING: (Computer Choice = %d)", num); //uncomment beggining to see computer random input
	return num;
}
int winnerCalculation(int userChoice, int computerChoice) {
	int winOutcome = 0;

	switch(userChoice) {

	case 1: //ROCK SELECTION
		if (computerChoice == 1) { //COMP  = ROCK
			printf("\n\t[TIE GAME, REDO ROUND...]\n");
		}
		if (computerChoice == 2) { //COMP = PAPER
			printf("\n\t[COMPUTER WINS]");
			winOutcome = 1;
		}
		if (computerChoice == 3) { //COMP = SCISSORS
			printf("\n\t[USER WINS]");
			winOutcome = 2;
		}
		break;

	case 2: //PAPER SELECTION
		if (computerChoice == 1) { //COMP  = ROCK
			printf("\n\t[USER WINS]");
			winOutcome = 2;
		}
		if (computerChoice == 2) { //COMP = PAPER
			printf("\n\t[TIE GAME, REDO ROUND...]\n");
		}
		if (computerChoice == 3) { //COMP = SCISSORS
			printf("\n\t[COMPUTER WINS]");
			winOutcome = 1; 
		}
		break;

	case 3: //SCISSORS SELCTION
		if (computerChoice == 1) { //COMP  = ROCK
			printf("\n\t[USER WINS]");
			winOutcome = 2;
		}
		if (computerChoice == 2) { //COMP = PAPER
			printf("\n\t[COMPUTER WINS]");
			winOutcome = 1;
		}
		if (computerChoice == 3) { //COMP = SCISSORS
			printf("\n\t[TIE GAME, REDO ROUND...]\n");
		}
		break;
	}
	return winOutcome;;
}
int programStart() {
	int userInput;
	bool userChoice;

	printf("\n\tDo you want to play the Rock Paper Scissors Game? (Y for Yes, N for NO) ");
	printf("\n\tInput: ");
}
int programRestart() { //provided by me (henry)
	char value;
	char userChoice[10];
	bool test, ending = true;

InputStart:

	do {
		test = true;

		printf("\n\tInput Y or y for YES, input N or n for NO: ");
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
int gameDescription() {
	printf("\n\n\t******** Welcome to the Rock Paper Scissors Game ********");
	printf("\n\tGame Rules: Basic game of Rock Paper Scissors, follow the prompt and first to three wins the game.");

	printf("\n\n\tComputer VS. User Begin!\n");
	printf("\n\t-------------------------------------------------------\n");
}

int main(void) {
	int userValue, computerValue, winValue, roundTally = 1, userTally = 0, computerTally = 0;
	bool initalStart = true, programContinue = true, gameOver;

	srand(time(NULL));

	printf("\n\tWould you like to play a game of Rock Paper Scissors?");
	programContinue = programRestart();
	if (programContinue == false) {
		goto InputEnd;
	}
	gameDescription();
	do {
		gameOver = false;
		while (!gameOver) {
			do {
				printf("\n\tRound #%d", roundTally);
				printf("\n\tEnter your slection:");
				printf("\n\t[1 = ROCK] [2 = PAPER] [3 = SCISSORS]");

				userValue = userInput();
				computerValue = computerSelection();
				winValue = winnerCalculation(userValue, computerValue);
				roundTally++;

				if (winValue == 1) {
					computerTally++;
				}
				else if (winValue == 2) {
					userTally++;
				}
			} while (winValue == 0);
			printf("\n\tCurrent Standings: [User Wins = %d] [Computer Wins = %d]\n", userTally, computerTally);
			printf("\n\t-------------------------------------------------------");

			if (userTally == 3 || computerTally == 3) {
				if (userTally == 3) {
					printf("\n\t[User Wins Rock Paper Scissors]");
				}
				else if (computerTally == 3) {
					printf("\n\t[Computer Wins Rock Paper Scissors]");
				}
				gameOver = true;
			}
		}
		printf("\n\n\tWould you like to continue the program?"); 
		programContinue = programRestart();
		roundTally = 1;
	} while (programContinue == true);

InputEnd:

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();
	//system pause -- leo

	return 0;
}
