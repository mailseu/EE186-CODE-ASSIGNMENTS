//Henry Samala
//C Digital Gates Updated 2.0
//SID #3522
//10.25.22

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int gateInput() {
	char gateSelection[10];
	int userGate;

	printf("\n\n\n\tGATE Options: \n\n\t1 = [AND] \n\t2 = [OR] \n\t3 = [NAND] \n\t4 = [NOR] \n\t5 = [XOR] \n\t6 = [XNOR] \n\t7 = [NOT] \n\t8 = [BUFFER] \n\t9 = [ALL GATES]");

InputStart: 

	printf("\n\n\tSelection of GATE: ");
	scanf_s("%s", &gateSelection, 10);
	sscanf_s(gateSelection, "%d", &userGate);

	for (int i = 0; gateSelection[i] != '\0'; i++) {
		if (isalpha(gateSelection[i])) {
			printf("\n\t[Invalid Input, Please Try Again]");
			goto InputStart;
		}
	}

	if (userGate < 1 || userGate > 9) {
		printf("\n\t[GATE Input Invalid, Please Try Again]");
		goto InputStart;
	}
	printf("\t-----------------------------------------------------");
	return userGate;
}
int userInputA() {
	bool flag;
	char inputA;

	printf("\n\tDirections: Please input a value of 0 or 1 below for each input, and your selction of GATE to test.");
	
	do {
		flag = true;
		printf("\n\n\tInput Value of A: ");
		scanf_s(" %c", &inputA);

		if (isalpha(inputA)) {
			printf("\t[Invalid Input, Please Try Again]\n");
			flag = false; 
		}
		inputA = inputA - '0';

		if (inputA == 1 || inputA == 0) {
			printf("\t[Inputed A = %d]", inputA);
		}
		else {
			printf("\t[Invalid Input, Please Try Again]\n");
			flag = false;
		}

	} while (!flag);

	return inputA;
}
int userInputB() {
	bool flag;
	char inputB;

	do {
		flag = true;
		printf("\n\n\tInput Value of B: ");
		scanf_s(" %c", &inputB);

		if (isalpha(inputB)) {
			printf("\t[Invalid Input, Please Try Again]\n");
			flag = false;
		}
		inputB = inputB - '0';

		if (inputB == 1 || inputB == 0) {
			printf("\t[Inputed B = %d]", inputB);
		}
		else {
			printf("\t[Invalid Input, Please Try Again]\n");
			flag = false;
		}

	} while (!flag);

	return inputB;
}
int programRestart() {
	int z;
	char choice;
	bool flag;

InputStart:

	z = 0;

	while (z == 0) {

		printf("\n\n\tWould you like to conitnue program, input Y or y for YES, input N or n for NO: ");
		scanf_s(" %c", &choice);

		if (isalpha(choice)) {
			z++;
			continue;
		}
		else {
			printf("\n\t[Invalid Input, Please Try Again]\n");
		}
	}

	switch (choice) {

		case 'N':
			printf("\n\n\t[Exiting Program...]\n\n");
			flag = false;
			break;

		case 'n':
			printf("\n\n\t[Exiting Program...]\n\n");
			flag = false;
			break;

		case 'Y':
			printf("\n\n\t[Resuming Program...]\n\n");
			flag = true;
			break;


		case 'y':
			printf("\n\n\t[Resuming Program...]\n\n");
			flag = true;
			break;
	

		default:
			printf("\n\t[Invalid Input, Please Try Again]\n");
			goto InputStart;
	}
	return flag;
}

int andGate(int numA, int numB) {
	int output;
	printf("\n\t[AND GATE Selection]");
	if (numA && numB) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tAND Output = %d\n", output);
}
int orGate(int numA, int numB) {
	int output;
	printf("\n\t[OR GATE Selection]");
	if (numA || numB) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tOR Output = %d\n", output);
}
int nandGate(int numA, int numB) {
	int output;
	printf("\n\t[NAND GATE Selection]");
	if (!(numA && numB)) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tNAND Output = %d\n", output);
}
int norGate(int numA, int numB) {
	int output;
	printf("\n\t[NOR GATE Selection]");
	if (!(numA || numB)) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tNOR Output = %d\n", output);
}
int xorGate(int numA, int numB) {
	int output;
	printf("\n\t[XOR GATE Selection]");
	if (numA ^ numB) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tXOR Output = %d\n", output);
}
int xnorGate(int numA, int numB) {
	int output;
	printf("\n\t[XNOR GATE Selection]");
	if (!(numA ^ numB)) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tXNOR Output = %d\n", output);
}
int notGate(int numA, int numB, int gate) {
	int output;
	printf("\n\t[NOT GATE Selection]");
	if (!numA) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tNOT A Output = %d\n", output);
	if (gate == 7) {
		if (!numB) {
			output = 1;
		}
		else {
			output = 0;
		}
		printf("\n\tNOT B Output = %d\n", output);
	}
}
int bufferGate(int numA, int numB, int gate) {
	int output;
	printf("\n\t[BUFFER GATE Selection]");
	if (numA) {
		output = 1;
	}
	else {
		output = 0;
	}
	printf("\n\tBUFFER A Output = %d\n", output);
	if (gate == 8) {
		if (numB) {
			output = 1;
		}
		else {
			output = 0;
		}
		printf("\n\tBUFFER B Output = %d\n", output);
	}
}

int main(void) {
	int numA, numB, gate;
	bool flag;

	do {

		numA = userInputA();
		numB = userInputB();
		gate = gateInput();

		switch (gate) {
		case 1: //AND GATE
			andGate(numA, numB);
			break;

		case 2: //OR GATE 
			orGate(numA, numB);
			break;

		case 3: //NAND GATE
			nandGate(numA, numB);
			break;

		case 4: //NOR GATE
			norGate(numA, numB);
			break;

		case 5: //XOR GATE
			xorGate(numA, numB);
			break;

		case 6: //XNOR GATE
			xnorGate(numA, numB);
			break;

		case 7: //NOT GATE
			notGate(numA, numB, gate);
			break;

		case 8: //BUFFER OUTPUT
			bufferGate(numA, numB, gate);
			break;

		case 9: //ALL GATES
			andGate(numA, numB);
			orGate(numA, numB);
			nandGate(numA, numB);
			norGate(numA, numB);
			xorGate(numA, numB);
			xnorGate(numA, numB);
			notGate(numA, numB, gate);
			bufferGate(numA, numB, gate);
			break;
		}

		flag = programRestart();

	} while (flag);

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	//system pause -- leo

	return 0;
}
