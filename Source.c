//Multiplication Table Code
//Henry Samala
//SID # 3522
//Due Date 10.3.22

#include <stdio.h>

int main() {
	
	int lower_limit, upper_limit, test_range, num;
	int x, y, z;

	x = 0;
	y = 0;
	z = 0;

	printf("\n\n\tDirections: Please input an integer range 1-100 which consist of a total of 3 different\n");
	printf("\titerations i.e 4 & 7 = 4, 5, 6, 7. The lower limit must be < than upper limits.");
	printf("\n\t_________________________________________________________");

	//range testing

	while (x == 0) { //while loop until test range is true

		printf("\n\n\tPlease enter lower range limit number: "); //lower range limit
		scanf_s("%d", &lower_limit);

		printf("\tPlease enter upper range limit number: "); //upper range limit
		scanf_s("%d", &upper_limit);

		printf("\n\tTesting Numbers...\n");
		
		if ((lower_limit > 0 && upper_limit > 0) && (lower_limit <= 100 && upper_limit <= 100)) { //checks if negative or above 100 value
			printf("\n\t[lower limit and upper limit values good]");
			z = 1;
		}
		else {
			printf("\n\t[limit range values are either less than 1 or greater than 100, please try again: Inputed (%d or %d)]", lower_limit, upper_limit);
			z = 0;
		}

		if (z == 1) { //if values 1-100, test if lower range < upper range

			if (lower_limit < upper_limit) { //lower range < upper limit test
				printf("\n\t[lower limit < upper limit good]");
				y = 1;
			}
			else { //lower range > upper limit
				printf("\n\t[lower limit is greater or equal to than upper limit, please try again: Inputed (%d < %d)]\n", lower_limit, upper_limit);
				y = 0;
			}
		}

		if (y == 1) { //if lower limit < upper liit, test range iterations

			test_range = upper_limit - lower_limit; //testing range

			if (test_range >= 3) { //test range true
				printf("\n\t[more than 3 iterations good]");
				x = 1; //exits while loop
			}
			else { //test range false
				printf("\n\t[Range has less than 3 iterations, please try again: Inputed %d - %d = %d]\n", upper_limit, lower_limit, test_range);
				z = 0;
				y = 0;
			}

		}
	}

	x = 0; //reset variable
	y = 0; //reset varaible

	printf("\n\t_________________________________________________________");
	printf("\n\n\tEntered range: [%d, %d]\n", lower_limit, upper_limit); //displays inputed range

	num = lower_limit; //for displaying values
	x = lower_limit; //x is equal to lower limit, for while loop and multiplication
	
	printf("\tMultiplication Table Output 1-9:\n\n\t");

	//two loops embedded 

	while (x <= upper_limit) { //loops until all values in range is calculated
		
		y = 2; //resets value for loop

		for (y = 2; y <= 10; ++y) { //multiplication sequence 10x

			printf("%d ", num); //displays current value * y
			num = x * y; //calculates value 
		}
		printf("\n\t"); //skips a line

		x++; //increase count of range +1
		num = x; //new value according to count
	}

	//system pause 

	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	return 0;
}