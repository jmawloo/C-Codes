#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*HOMEWORK*/

int compare(char words[10][7], char band[]) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		if(!strcmp(band,words[i])) {
			return i;
		}
	}
	return -1; /*This happens if the inputs didn't work.*/
}

int main() {
	char COLOR_CODES[10][7] = {"black","brown","red","orange","yellow","green","blue","violet","gray","white"};
	char bands[3][7]; //7 includes the '\0'	
	long int resist;
	int b[3],i;
	char choice = 'y';
	
	while (choice == 'y') {
		puts("Enter the colors of the resistor's three bands, beginning with the band nearest the end. Type the colors in lowercase letters only, NO CAPS.");
		for (i = 0; i < 3; i++) {
			printf("Band %d => ",i+1);
			scanf("%s",bands[i]);
		}
		for (i = 0; i < 3; i++) {
			b[i] = compare(COLOR_CODES,bands[i]);
			if (b[i] == -1) {
				printf("Invalid color: %s\n",bands[i]);
				break;
			}
			else if (i == 2) {
				resist = (b[0]*10 + b[1])*((int) pow(10,b[2]));
				if (resist / 1000 >= 1) {
					printf("Resistance value: %d kilo-ohms\n",resist/1000);
				}
				else {
					printf("Resistance value: %d ohms\n",resist);
				}
			}
		}
		puts("Decode another resistor? [y,n]");
		printf("=> ");
		choice = getchar(); //Do this twice since C is stupid.
		choice = getchar(); //Do this twice since C is stupid.
	}
	return(0);
}