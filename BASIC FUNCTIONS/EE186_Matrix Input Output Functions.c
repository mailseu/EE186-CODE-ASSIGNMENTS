int printingMatrix(char input[10][10]) {
	for (int i = 0; i < 10; i++) {
		printf("\n\t");
		for (int a = 0; i < 10; a++) {
			printf("%3c ", input[i][a]); //align right
		}
	}
}

int printingDiagnoal(char input[10][10]) {
	for (int i = 0; i < 10; i++) {
		printf("\t");
		for (int a = 0; a < 10; a++) {
			if (i == a) {
				input[i][a] = 0;
			}
		}
	}
}

int uniqueMatrix(char input[10][10]) {
	int newNum;
	bool testOutput;

	for (int i = 0; i < 10; i++) { //generates number according to i count
		for (int a = 0; a < 10; a++) {

			do {
				newNum = (rand() % 100) + 1; //generates random number from 1 - 100
				testOutput = true;
				testOutput = errorCheckRandomMatrix(input, i, a, newNum, testOutput);
				
			} while (!testOutput);

			input[i][a] = newNum; //places number into array
		}
	}
}
int errorCheckRandomMatrix(char input[10][10], int inputI, int inputA, int newNum, bool numberCheck) {
	for (int i = 0; i < inputI; i++) { //for loops checks if generated number is equal to any number in array
		for (int a = 0; a < inputA; a++) {
			if (input[i][a] == newNum) {
				numberCheck = false;
			}
		}
	}
	return numberCheck;
}

int symbolInput() {
	char userInput[10], valueOutput;
	bool flagInput, validInput;


	do {
		flagInput = true;
		validInput = true;

		printf("Please input a symbol");
		printf("\n\n\tInput: ");
		scanf_s("%s", &userInput, 10);
		sscanf_s(userInput, "%c", &valueOutput);

		for (int i = 0; i < strlen(userInput); i++) {
			if (!ispunct(userInput[i])) {
				flagInput = false;
			}
		}

	} while (!flagInput);
	printf("\n\t[User Inputed Value = %c]\n", valueOutput);
 }
