//Henry Samala
//Extra Credit Drive Thru
//SID #3522
//12.5.22

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

float burger = 3.45, milkshake = 2.15, fries = 1.60;

int digitCheck(char input[]) { //provided integer checker by me (henry samala)
	bool digitInput = true;
	int stringLength;

	stringLength = strlen(input);

	for (int i = 0; i < stringLength; i++) {
		if (isdigit(input[i])) {
			printf("\n\t[Input Invalid, Please Try Again]\n");
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

			printf("\n\tInput: ");
			scanf_s("%s", &userInput, 10);
			sscanf_s(userInput, "%d", &valueOutput);

			validInput = characterCheck(userInput);

		} while (!validInput);

		if (valueOutput < 0 || valueOutput > 100) { //change according to input reqiurements
			printf("\n\t[Input Invalid, Please Try Again]");
			flagInput = false;
		}

	} while (!flagInput);
	printf("\n\t[User Inputed Value = %d]\n", valueOutput);
	return valueOutput;
}
int programRestart() { //provided by me (henry samala)
	char valueOutput;
	char userChoice[10];
	bool validInput, validEnding;

	do {
		validInput = true;

		do {

			printf("\n\n\tDo you want to place more orders, input Y for YES, input N for NO: ");
			scanf_s("%s", &userChoice, 10);
			sscanf_s(userChoice, "%c", &valueOutput);

			validInput = digitCheck(userChoice);

		} while (!validInput);

		validEnding = true;

		switch (valueOutput) {

		case 'N':
			printf("\n\n\t[Exiting Orders...]\n\n");
			printf("\n\t----------------------------------------------");
			validEnding = false;
			break;

		case 'n':
			printf("\n\n\t[Exiting Orders...]\n\n");
			printf("\n\t----------------------------------------------");
			validEnding = false;
			break;

		case 'Y':
			printf("\n\n\t[Resuming Orders...]\n\n");
			printf("\n\t----------------------------------------------");
			break;


		case 'y':
			printf("\n\n\t[Resuming Orders...]\n\n");
			printf("\n\t----------------------------------------------");
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
	printf("\n\tDirections: Please follow the prompts on the screen and input accordingly.");

	printf("\n\n\t[Thank you for visiting the Electrical Cafe, our current menu is shown below]");
	printf("\n\t\t- Double Burger = $3.45");
	printf("\n\t\t- Milkshake = $2.15");
	printf("\n\t\t- Fries = $1.60");
}
int userInputs() {
	int burgerCount, milkshakeCount, friesCount, orderCount = 1;
	float subTotal, grandTotal = 0;
	bool programContinue = true;

	do {
		printf("\n\n\t(Starting Order #%d)", orderCount);


		printf("\n\n\tHow many Double Burgers do you want for order #%d", orderCount);
		burgerCount = userInputDIGIT();

		printf("\n\n\tHow many Vanilla Milkshake do you want for order #%d", orderCount);
		milkshakeCount = userInputDIGIT();

		printf("\n\n\tHow many Fries do you want for order #%d", orderCount);
		friesCount = userInputDIGIT();

		subTotal = (((float)burgerCount * burger) + ((float)milkshakeCount * milkshake) + ((float)friesCount * fries));
		printf("\n\t[Your Subtotal for Order #%d = $%.2f]", orderCount, subTotal);

		grandTotal = subTotal + grandTotal;
		programContinue = programRestart();

		if (programContinue) {
			orderCount++;
		}

	} while (programContinue);

	printf("\n\n\t[Your Grand Total for %d Order(s) is $%.2f, please pay at the next window]", orderCount, grandTotal);
}

int main() {

	programIntroduction();
	userInputs();
	systemPause();

	return 0;
}
