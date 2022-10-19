//Simple Text Output
//Henry Samala
//SID # 3522
//Due Date 10.5.22

#include <stdio.h>

int main() {

	//1 Semicolon
	
	printf("\n\tI am an Engineer\n\n\tI am a complete sentence\n\n\tI\n\tam\n\ta\n\tdisjointed\n\tsentence\n\n");

	//system pause 

	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	return 0;

}