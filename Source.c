//Henry Samala
//C Digital Gates Updated
//SID #3522
//10.19.22

#include <stdio.h>
#include <ctype.h>

int ANDOutput(int inputA, int inputB) {
	int value;
	printf("\n\t[AND GATE Selection]");
	if (inputA && inputB) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tAND Output = %d\n", value);
}
int OROutput(int inputA, int inputB) {
	int value;;
	printf("\n\t[OR GATE Selection]");
	if (inputA || inputB) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tOR Output = %d\n", value);
}
int NANDOutput(int inputA, int inputB) {
	int value;
	printf("\n\t[NAND GATE Selection]");
	if (!(inputA && inputB)) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tNAND Output = %d\n", value);
}
int XOROutput(int inputA, int inputB) {
	int value;
	printf("\n\t[XOR GATE Selection]");
	if (inputA ^ inputB) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tXORO Output = %d\n", value);
}
int NOROuput(int inputA, int inputB) {
	int value;

	printf("\n\t[NOR GATE Selection]");
	if (!(inputA || inputB)) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tNOR Output = %d\n", value);
}
int XNOROuput(int inputA, int inputB) {
	int value;

	printf("\n\t[XNOR GATE Selection]");
	if (!(inputA ^ inputB)) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tXNOR Output = %d\n", value);
}
int NOTOutput(int inputA, int inputB) {
	int value;

	printf("\n\t[NOT GATE Selection]");
	if (!(inputA)) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tINPUT A NOT Output = %d\n", value);

	if (!(inputB)) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tINPUT B NOT Output = %d\n", value);
}
int BUFFEROutput(int inputA, int inputB) {
	int value;

	printf("\n\t[BUFFER GATE Selection]");
	if (inputA) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tINPUT A BUFFER Output = %d\n", value);
	if (inputB) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tINPUT B BUFFER Output = %d\n", value);
}
int BUFFERandNOTOutput(int inputA, int inputB) {
	int value;

	printf("\n\t[NOT GATE Selection]");
	if (!(inputA)) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tINPUT A NOT Output = %d\n", value);
	
	printf("\n\t[BUFFER GATE Selection]");
	if (inputA) {
		value = 1;
	}
	else {
		value = 0;
	}
	printf("\n\tINPUT A BUFFER Output = %d\n", value);
}

int main(void) {

	int value, inputA, inputB, GATE, End;
	int x, y, z;

	char a, b, c, e[10];

	printf("\n\tDirections: Please input a value of 0 or 1 below, and your selction of GATE to test.");

InputStart:

	x = 0;
	y = 0;

	while (x == 0) {
		printf("\n\n\tInput Value of A: ");
		scanf_s(" %c", &a);

		printf("\tInput Value of B: ");
		scanf_s(" %c", &b);

		if ((isalpha(a)) || (isalpha(b))) {
			printf("\n\t[Invalid Input, Please Try Again]\n");
			goto InputStart;
		}
		else {
			inputA = a - '0';
			inputB = b - '0';
		}

		 if ((inputA == 1 || inputA == 0) && (inputB == 1 || inputB == 0)) {
			printf("\n\t[Inputed A = %d]", inputA);
			printf("\t[Inputed B = %d]", inputB);
			x++;
		}
		else {
			printf("\n\t[Invalid Input, Please Try Again]\n");
		}
	}
	printf("\n\n\n\tGATE Options: \n\n\t1 = [AND] \n\t2 = [OR] \n\t3 = [NAND] \n\t4 = [NOR] \n\t5 = [XOR] \n\t6 = [XNOR] \n\t7 = [NOT] \n\t8 = [BUFFER] \n\t9 = [ALL GATES]");

GateInput:

	printf("\n\n\tSelection of GATE: ");
	scanf_s("%s", &e, 10);
	sscanf_s(e, "%d", &GATE);

	for (int i = 0; e[i] != '\0'; i++) {
		if (isalpha(e[i])) {
			printf("\n\t[Invalid Input, Please Try Again]");
			goto GateInput;
		}
	}
	
	if (GATE < 1 || GATE > 9) {
		printf("\n\t[GATE Input Invalid, Please Try Again]");
		goto GateInput;
	}

	printf("\n\t[GATE Selection = %d]\n", GATE);

	printf("\n\n\tDigital Gate Outputs:\n");
	printf("\t-----------------------------------------------------------");

	switch (GATE) {
	case 1: //AND GATE
		ANDOutput(inputA, inputB);
		break;

	case 2: //OR GATE 
		OROutput(inputA, inputB);
		break;

	case 3: //NAND GATE
		NANDOutput(inputA, inputB);
		break;

	case 4: //NOR GATE
		NOROuput(inputA, inputB);
		break;

	case 5: //XOR GATE
		XOROutput(inputA, inputB);
		break;

	case 6: //XNOR GATE
		XNOROuput(inputA, inputB);
		break;

	case 7: //NOT GATE
		NOTOutput(inputA, inputB);
		break;

	case 8: //BUFFER OUTPUT
		BUFFEROutput(inputA, inputB);
		break; 
	case 9:
		ANDOutput(inputA, inputB);
		OROutput(inputA, inputB);
		NANDOutput(inputA, inputB);
		NOROuput(inputA, inputB);
		XOROutput(inputA, inputB);
		XNOROuput(inputA, inputB);
		BUFFERandNOTOutput(inputA, inputB);
		break;
	} 
	
	z = 0;

	while (z == 0) {
		printf("\n\n\tWould you like to conitnue, input Y or y for YES, input N or n for NO: ");
		scanf_s(" %c", &c);

		switch (c) {

		case 'N':
			printf("\n\n\t[Exiting Program...]\n\n");
			z++;
			break;

		case 'n':
			printf("\n\n\t[Exiting Program...]\n\n");
			z++;
			break;

		case 'Y':
			printf("\n\n\t[Resuming Program...]\n\n");
			goto InputStart;

		case 'y':
			printf("\n\n\t[Resuming Program...]\n\n");
			goto InputStart;


		default:
			printf("\n\t[Invalid Input, Please Try Again]\n");
		}
	}

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	//system pause -- leo

	return 0;
}