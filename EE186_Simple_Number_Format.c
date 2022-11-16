//Simple Number Format Code
//Henry Samala
//SID # 3522
//Due Date 10.5.22

#include <stdio.h>

int main() {

	int integer1, integer2;

	do {

		printf("\n\n\tInput first integer value: "); //first value 
		scanf_s("%d", &integer1);

		printf("\tInput second integer value:"); //second value
		scanf_s("%d", &integer2);

		if (integer1 == integer2) { //checks if first value = second value
			printf("\n\n\t[First Integer = Second Integer, please try again.]");
		}
		else {
			printf("\n\n\t[Integer Input Good.]\n");
		}

	} while (integer1 == integer2);

	printf("\n\tOutput:");

	printf("\n\n\t%d / %d = %.2f", integer1, integer2, (float)integer1 / integer2); //normal divsion
	printf("\n\t%d / %d = %.2f", integer2, integer1, (float)integer2 / integer1); //reversed integer

	//system pause 

	printf("\n\n\n\t\tEnd of Program");
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	return 0;
}
