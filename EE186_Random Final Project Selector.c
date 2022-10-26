//Henry Samala
//Random Final Project Selector
//SID #3522
//10.26.22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int projectSelect(webpg, proj) { // skeleton project & site selector moved to maim, provided by leo
	switch (webpg)
	{
	case 1:
		printf("\n\thttps://www.electronicshub.org/diy-projects/");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	case 2:
		printf("\n\thttps://miliohm.com/category/arduino/");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	case 3:
		printf("\n\thttps://simple-circuit.com/arduino-projects/");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	case 4:
		printf("\n\thttps://nevonprojects.com/arduino-projects/");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	case 5:
		printf("\n\thttps://www.seeedstudio.com/blog/2020/01/16/20-awesome-arduino-projects-that-you-must-try-2020/");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	case 6:
		printf("\n\thttps://www.makeuseof.com/tag/10-great-arduino-projects-for-beginners/");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	case 7:
		printf("\n\thttps://itsfoss.com/cool-arduino-projects/");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	case 8:
		printf("\n\thttps://www.dunebook.com/top-opensource-arduino-projects/");
		printf("\n\tproj # is %i\n\n", proj);
		break;

	case 9:
		printf("\n\thttps://www.projectsof8051.com/arduino-projects/");
		printf("\n\tproj # is %i\n\n", proj);
		break;

	case 10:
		printf("\n\thttps://www.electroschematics.com/category/arduino/");
		printf("\n\tproj # is %i\n\n", proj);
		break;

	case 11:
		printf("\n\thttps://medium.com/whats-making/10-arduino-projects-for-beginners-anyone-can-make-64462ada2eb1");
		printf("\n\tproj # is %i\n\n", proj);
		break;

	case 12:
		printf("\n\thttps://medium.com/whats-making/10-arduino-projects-for-beginners-anyone-can-make-64462ada2eb1");
		printf("\n\tproj # is %i\n\n", proj);
		break;
	}
}

int errorCheck(int num[], int i, int newNum, bool test) { //provided by henry (me)
	for (int x = 0; x < i; x++) { 
		if (num[x] == newNum) {
			test = false;
		}
	}
	return test;
}

int uniqueNumbers(int num[]) { //provided by henry (me)
	int newNum;
	bool test;

	for (int i = 0; i < 12; i++) { 
		do {
			newNum = (rand() % 12) + 1; 
			test = true;
			test = errorCheck(num, i, newNum, test);

		} while (!test);
		num[i] = newNum; 
	}
}

int randomNumbers() {
	int num;
	num = rand() % 15 + 1; //15 max because a website on list only has 15 projects.

	return num;
}

int projectDescription() {

	printf("\n\n\tPrograms to assign project to those students who did NOT select a final project, and the");
	printf("\n\tproject will not be allowed to be changed if ASSIGNED by instructor. However, the project");
	printf("\n\tcan be changed if the student SELECTED project is beyond the student's ability.");
	printf("\n\n\t\t ************ Project Selector due by 2 PM October 25 *************\n\n");

	printf("\n\tGenerating Random Websites and Projects:");
	printf("\n\t------------------------------------------------------------------------\n");
}

int main(void) {
	int outputSelection[12];
	int outputProject;

	projectDescription();

	srand(time(NULL));
	uniqueNumbers(outputSelection);

	for (int i = 0; i < 12; i++) {
		outputProject = randomNumbers();
		projectSelect(outputSelection[i], outputProject);
	}

	// system pause -- leo
	char xyz;
	while ((xyz = getchar()) != '\n' && xyz != EOF)
		xyz = getchar();
	getchar();

	//system pause -- leo

	return 0;
}
