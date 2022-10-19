//Henry Samala
//If Else Comparison and Case Statement
//SID #3522
//10.17.22

#include <stdio.h>
#include <ctype.h>

int main(void) {

	char age[4], op, a;
	double value;
	int x, y, z, input;

	printf("\n\tDirections: Please follow the prompts stated. Must be a valid number for age, a listed");
	printf("\n\t            operator, and a listed choice of calculation.");

ProgramStart:

	x = 0;
	z = 0;

	while (z == 0) {
		printf("\n\n\n\tTo start program input 1 or input 2 to exit: ");
		scanf_s("%d", &y);
		if (y == 1) {
			printf("\n\n\t[Starting Program...]");
			z++;
			break;
		}
		else if (y == 2) {
			printf("\n\n\t[Exiting Program...]");
			goto ProjectEnd;
		}
		else {
			printf("\n\t[Invalid Input, Please Review Directions Above]");
		}
	}
	while (x == 0) {

InputStart:
		printf("\n\n\n\tPlease input your age: "); //age input
		scanf_s("%s", &age, 4);
		sscanf_s(age, "%lf", &value);

		printf("\tPlease input choice of operator (+, -, *, or /): "); //operator input
		scanf_s(" %c", &op);

		printf("\n\t[Age Inputed = %s]", age);
		printf("\n\t[Operator Inputed = %c]", op);

ErrorCheck:
		printf("\n\n\tWould you like to continue to Error Checking (Y or N, Case Sensitive): ");
		scanf_s(" %c", &a);

		switch (a) {
		case 'Y': //erorr checking values
			for (int i = 0; age[i] != '\0'; i++) {
				if (!isdigit(age[i])) {
					printf("\n\t[Age Input Invalid, Please Try Again]");
					goto InputStart;
				}
			}
			printf("\n\t[Age Input Valid]");
			if (op == 42 || op == 43 || op == 45 || op == 47) {
				printf("\n\t[Operator Input Valid]");
				x++;
			}
			else {
				printf("\n\t[Operator Input Invalid, Please Try Again]\n\n]");
			}
			break;

		case 'N':
			printf("\n\t[Clearing Values...Please Input New Values]\n\n");
			break;

		default:
			printf("\n\t[Invalid Input, Please Try Again]\n\n");
			goto ErrorCheck;
		}
	}

	printf("\n\n\n\tWhich type of function would you like to examine for your input, calculations [AGE (OP) 3 = VALUE].");
	printf("\n\tDirections: Enter 1 for Case Statement examination, or 2 for viewing If Else statement examination");

	x = 0;

	do {
		printf("\n\n\tInput: ");
		scanf_s("%d", &input);

		if (input == 1 || input == 2) {
			x++;
		}
		else {
			printf("\n\t[Invalid Input, Please Review Directions Above]");
		}

	} while (x == 0);

	if (input == 1) {
		printf("\n\t[Examining Case Statement]");
		switch (op) {
		case '+':
			printf("\n\t%s + 3 = %.1lf", age, value + 3);
			break;
		case '*':
			printf("\n\t%s * 3 = %.1lf", age, value * 3);
			break;
		case '-':
			printf("\n\t%s - 3 = %.1lf", age, value - 3);
			break;
		case '/':
			printf("\n\t%s / 3 = %.1lf", age, value / 3);
			break;
		default:
			printf("\n\t[Invalid Input, Please Try Again]\n\n");
			goto ErrorCheck;
		}
	}
	else if (input == 2) {
		printf("\n\t[Examining Else If Statement]");
		if (op == '+') {
			printf("\n\t%s + 3 = %.1lf", age, value + 3);
		}
		else if (op == '-') {
			printf("\n\t%s - 3 = %.1lf", age, value - 3);
		}
		else if (op == '*') {
			printf("\n\t%s * 3 = %.1lf", age, value * 3);
		}
		else if (op == '/') {
			printf("\n\t%s / 3 = %.1lf", age, value / 3);
		}
		else {
			printf("\n\t[Invalid Input, Please Try Again]\n\n");
			goto ErrorCheck;
		}
	}
	goto ProgramStart;

ProjectEnd:

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	//system pause -- leo

	return 0;
}