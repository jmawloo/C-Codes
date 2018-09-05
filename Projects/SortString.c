#include <stdio.h>
#include <stdlib.h>

/*
Write program that sorts strings. Symbols first, then numbers, then letters (case sensitive).
*/
void sortchars(char *list) { // Using selectionsort.
	int a=0, b, index;
	char min;
	
	while (list[1 + a] != '\0') { //list[a+1] b/c want comparisons to be within list index range.
		min = list[a];
		index = a; //Bookkeeping value to be moved/replaced.
		b = a + 1;
		
		while (list[b] != '\0') {
			if (list[b] < min) {
				min = list[b];
				index = b;
			}
			b++;
		}
		
		list[index] = list[a]; // Swap values in list.
		list[a] = min;		
		a++;
	}
}

void splitchars(char * str, char *list[]) { // char *list[] is also the parameter structure for a dynamic multi-array.
	int i = 0, index[3] = {0,0,0}; 
	
	while (str[i] != '\0') { // Each character has its own integer value.
		if (str[i] >= '0' && str[i] <= '9') { // Numbers in middle bin
			list[1][index[1]++] = str[i];		
		}
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) { //Uppercase and lowercase letters in last bin
			list[2][index[2]++] = str[i];
		} 
		else if (str[i] != ' ' && str[i] != '\n'){// Store the symbols in the first bin, ignoring whitespace and newline.
			list[0][index[0]++] = str[i];
		}
		i++; // Don't forget to increment.
	}
	
	for (i = 0; i < 3; i++) { // Add terminating characters to the end of each bin, and pass them to another function to be sorted.
		list[i][index[i]] = '\0';
		sortchars(list[i]);
	}
}


int main() {
    char string[101];
	fgets(string, 101, stdin); // Ask for user input here.
	
	char ** list = (char**) calloc(3, sizeof(char*)); //Dynamic allocation to prevent C from complaining about levels of indirection.
	int i = 0;
	for (i; i < 3; i++) {
		list[i] = (char*) calloc(100, sizeof(char));//1st element contains symbols, 2nd contains numbers, 3rd contains letters.
	}
	
	splitchars(string, list);
    printf("%s%s%s", list[0],list[1],list[2]); //Output
	
	for (i = 0; i < 3; i++) { // Cleanup.
		free(list[i]);
	}
	free(list);
	
    return 0;
}