//Henry Samala
//C Code Minesweeper
//SID #3522
//10.19.22

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
	char input[10], ending;
	int x, i, a, test, value, program, end, output, count;

	program = 0;
	count = 0;

	while (program == 0) {

		printf("\n\tDirections: Please input an integer 1- 100 when prompted. It will be incremented 3 times by (1) and");
		printf("\n\t	    if no prime number is found, then you win.");

		do {	

		InputStart:

			x = 0;

			printf("\n\n\tCurrent Game Wins = %d", count);

			printf("\n\n\tInput 1 - 100: ");
			scanf_s("%s", &input, 10);
			sscanf_s(input, "%d", &value);

			for (i = 0; input[i] != '\0'; i++) {
				if (!isdigit(input[i])) {
					printf("\n\t[Input Invalid, Please Try Again]");
					goto InputStart;
				}
			}

			if (value < 1 || value > 100) {
				printf("\n\t[Invalid Input, Please try again...]");
			}
			else {
				printf("\n\t[Integer Inputed = %d]", value);
				x++;
			}

		} while (x == 0);
		
		printf("\n\n\n\t[Starting Game... Running Calculations]\n");
		printf("\t------------------------------------------------");

		output = 0;

		for (a = 0; a < 3; a++) {
			test = 0;
			printf("\n\t(Testing Entry %d for Prime...)", value);
			for (i = 2; i <= sqrt(value); i++) {
				if (value % i == 0) {
					test++;
				}
				// printf("\n\t%d / %d  = %d, test = %d", value, i, value % i, test); //testing program 
			}
			if (test == 0) {
				printf("\tPrime Number Detected!");
				output++;
				goto Results;
			}
			else {
				printf("\tNot A Prime!");
			}
			value++;
		}
		
	Results:

		if (output == 0) {
			printf("\n\n\t[Congratulations You Win!]");
			count++;
		}
		else {
			printf("\n\n\t[%d is a Prime Number, You Lost!]", value);
		}

		end = 0;

		while (end == 0) {

		InputEnd:

			printf("\n\n\tWould you like to play again? (Y or y for YES, N or n for NO): ");
			scanf_s("%s", &input, 10);
			sscanf_s(input, " %c", &ending);

			for (i = 0; input[i] != '\0'; i++) {
				if (isdigit(input[i])) {
					printf("\n\t[Input Invalid, Please Try Again]");
					goto InputEnd;
				}
			}

			if (ending == 'Y') {
				printf("\n\t[Resuming Game...]");
				goto InputStart;
			}
			else if (ending == 'y') {
				printf("\n\t[Resuming Game...]");
				goto InputStart;
			}
			else if (ending == 'N') {
				printf("\n\t[Exiting Game...]");
				end++;
				program++;
			}
			else if (ending == 'n') {
				printf("\n\t[Exiting Game...]");
				end++;
				program++;
			}
			else {
				printf("\n\t[Input Invalid, Please Try Again]");
				goto InputEnd;
			}

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