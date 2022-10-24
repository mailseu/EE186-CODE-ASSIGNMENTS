//Henry Samala
//Random Number Array
//SID #3522
//10.24.22

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <stdbool.h>

int error_check(int num[], int i, int newNum, bool test) {
	for (int x = 0; x < i; x++) { //for loops checks if generated number is equal to any number in array
		if (num[x] == newNum){
			test = false;
		}
	}
	return test;
}

int unique_numbers(int num[]) {
	int newNum;
	bool test;

	for (int i = 0; i < 50; i++) { //generates number according to i count
		do {
			newNum = (rand() % 60) + 1; //generates random number from 1- 60
			test = true;
			test = error_check(num, i, newNum, test);

		} while (!test);
		num[i] = newNum; //places number into array
	}	
}

int output_numbers(int num[]) {

	printf("\n\n\tNumber Output:\n\t");

	for (int count = 0; count < 50; count++) {

		if (count % 10 == 0) { //checks for new line
			printf("\n\t");
		}
		printf("%d\t", num[count]); //displays number in array according to count
	}
}


int main(void) {
	int output[50];

	printf("\n\tDirections: 50 random numbers will be generated and output will be diplayed into a matrix of 10");
	printf("\n		    elements each checking for repeated number checker");

	srand(time(NULL));

	unique_numbers(output); //array is set to 50 and generates 50 random numbers from 1 - 60
	output_numbers(output); //outputs array in propepr format

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	//system pause -- leo


	return 0;
}
