//Henry Samala
//Midterm Question #1
//SID #3522
//10.6.22

#include <stdio.h>

int main() {

	int value, results, check;
	int three, five, seven;
	int x;

	x = 0;

	while (x == 0) {

		printf("\n\tInput an integer 9 - 108, or input 18 to quit program: ");
		scanf_s("%d", &value);

		if (value == 18) {
			printf("\n\tGlad you enjoyed the game, goodbye");
			return 0;

		}
		else if (value >= 9 && value <= 108) {
			printf("\n\tNumber Inputed = %d", value);
		}
		else {
			printf("\n\tNumber is out of range, please re-enter");
		}

		printf("\n\n\tThe reuslts of your number divided by 6 is %.2f", (float)value / 6);

		three = value % 3;
		five = value % 5;
		seven = value % 7;

		check = 0;

		if (three == 0) {
			printf("\n\tNumber is divisible by 3");
			check++;
		}
		
		if (five == 0) {
			printf("\n\tNumber is disibile by 5");
			check++;
		}
		
		if (seven == 0) {
			printf("\n\tNumber is divisible by 7");
			check++;
		}

		if (check == 0) {
			printf("\n\tNumber is NOT divisible by 3, 5, and 7\n\n");
			check = 0;
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
