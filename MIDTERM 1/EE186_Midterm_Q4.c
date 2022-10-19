//Henry Samala
//Midterm Question #4
//SID #3522
//10.6.22

#include <stdio.h>

int main() {

	int num, count, value;
	int x;

	count = 1;

	printf("\n\tSelect any number expect a multiple of 13 to continue playing.");

	for (x = 0; x <= 4; x++) {
		printf("\n\n\tPlease enter your selction #%d", count);

		printf("\n\tSelection: ");
		scanf_s("%d", &num);
		printf("\n\tSelection #%d was %d", count, num);

		value = num % 13;

		if (value == 0) {
			printf("\n\n\tYour selection is a multiple of 13!");

			value = num / 13;
			printf("\n\t\%d divided by 13 = %d", num, value);
			printf("\n\n\tThank you for playing, game has ended!");
			x = 5;
		}
		else {
			count++;
			x = 0;
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
