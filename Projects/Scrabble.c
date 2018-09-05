#pragma once
#pragma message("LOOOOL")

#include <stdio.h>
#include <stdlib.h>

int get_points(char *word) { // Parameter is every word in the sentence.
	char points[][11] = {"aeilnorstu", "dg", "bcmp", "fhvwy", "k", "", "", "jx", "", "qz", ""}; // Use positioning of each set of characters to assign points. As well, need to specify inner dimensions (use max string length).
	int i = 0, j = 0, k = 0, score = 0, assigned = 0;
	
	while (word[i] != '\0') { // Iterate thru letters of word inputted.	
    /*The stop condition of j is interesting. If the for loop was set to iterate a max of exactly 10 times, then it skips some iterations of the outer while loop.*/
    	for (j=0; j < 11; j++) { // Iterate thru points list.
			if(assigned) {// Checks if point was already assigned in letter iteration of word.
				assigned = 0; // Prepare variable for next letter iteration of word.
				break;
			}
			while (points[j][k] != '\0') { // Iterate thru an element in points list.
				if(word[i] == points[j][k] || ((int) word[i]) + 32 == (int) points[j][k]) { // This also checks for upper case characters.
					score += (j + 1); // Variable j determines the points we get.
					assigned = 1;
					break; // Once points are given break from while loop.
				}				
				k++;
			}
			k = 0; // Reset k.
	    }
		i++;
	}
	
	return score;
}

int main() {
	
	int points, points2=0, count, i, index;
	char ** sentence, word[27];
	puts("How many words to compare? (Assuming each word is <= 26 characters long):");
	scanf("%d", &count);
	
	sentence = (char**) calloc(count, sizeof(char*)); // Dynamically store all entered words for future comparison.
	
	
	// TODO: Print out all words that have the same max score.
	for (i=0; i<count; i++) {
		sentence[i] = (char*) calloc(27, sizeof(char));
		
		printf("Word #%d: ", i+1); //User input
		scanf("%s", sentence[i]);
		
		points = get_points(sentence[i]);
		if (points > points2) { //Check for max points.
			points2 = points;
			index = i; // Acts as bookkeeper
		}
	}
	
	
	printf("%s has the highest score in your list. [%d points]", sentence[index], points2);
	
	for (i=0; i < count; i++) { //Garbage cleanup.
		free(sentence[i]);
	}
	free(sentence);
	
	return 0;
}