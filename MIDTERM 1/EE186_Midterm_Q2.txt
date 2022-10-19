//Henry Samala
//Midterm Question #2
//SID #3522
//10.6.22

#include <stdio.h>

int main() { //student ID is 029553522, I will use the 2 and 9 avoiding zero. 

	float id;
	int ans, guess, x; 
	
	ans = 29;
	id = (float)2 / 9;

	printf("\n\tGuess the first two numbers of my student ID, you have (5) tries to do it");
	printf("\n\t\tHint, 1st nummber divided by 2nd number = %.2f", id);
	
	x = 0;

	while (x < 5) {

		printf("\n\n\tEnter Guess: ");
		scanf_s("%d", &guess);

		if (guess == 29) {
			printf("\n\tYou are a psychic, you guess my number! It was %d!", ans);
			x = 6;
			break;
		}
		else if (guess < 29) {
			x++;
			printf("\n\tYou guess low, aim higher.");
		}
		else if (guess > 29) {
			x++;
			printf("\n\tYou guess high, aim lower.");
		}

		if (x < 5) {
			printf("\n\tWrong guess, you have %d guesses left, please try again.", 5 - x);
		}
		else {
			printf("\n\tOut of tries, try again later!");
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
