#pragma once
#pragma message("Hello!")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This is to check if the diagonals of the square matrix are the same in value.*/
int checkDiag(int matrix[], int size) { 
	int temp = matrix[0],i;
	for (i = 1; i < size; ++i) {
		if (matrix[i*(size+1)] != temp) {
			return(0);
		}
	}
	return(1);
}

int checkDiag2(int matrix[], int size) { /*This one checks the anti-diagonals.*/
	int temp = matrix[size-1], i;
	for (i = 1;i < size; i++) {
		if (matrix[i*(size-1)] != temp) {
			return(0);
		}
	}
	return(1);
}


void arrayOut(int * arr_param, int size) {
	int i;
	printf("["); /*FORMAT*/
	for (i = 0; i < size; i++) { /*Print out values*/
		printf("%d",*(arr_param+i));
		if (i!=size-1){ /*FORMAT*/
			printf(", ");
		}
	}
	printf("]\n"); /*FORMAT*/
}

int count_zeros(int * arr, int size) {
	int i,count = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] == 0) count++;
	}
	return count;
}

int count_negs(int * arr, int size) {
	int i,count = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] < 0) count++;
	}
	return count;
}

int countWords(char * arr); /*Part 4: Counts the characters in a string.*/

void reverseWords(char ** arr2, char * original, int words); /*The hard one. Reverses the order of the words.*/

int main() {
	/*Part 1*/
	FILE * Matrix = fopen("matrix1.txt","r");
	int size, * mat1, i, check;
	if (Matrix == NULL) {
		puts("Invalid file path, please try again");
		return(2);
	
	}
	fscanf(Matrix,"%d",&size);
	
	mat1 = (int *) calloc(size*size,sizeof(int));
	
	for (i = 0; i < size*size; i++) { /*Gets the matrix from the file*/
		fscanf(Matrix,"%d",mat1+i);
	}
	
	check = checkDiag(mat1,size);
	
	if (check) { /*Conditional statements to see if the function returned true or not.*/
		printf("The matrix is %dx%d and all the numbers in the main diagonal are the same.\n",size,size);
	}
	else {
		printf("The matrix is %dx%d but not all the numbers in the main diagonal are the same.\n",size,size);
	}
	
	/*Part 3*/
	check = checkDiag2(mat1,size);
	
	if (check) { /*Conditional statements to see if the function returned true or not.*/
		printf("The matrix is %dx%d and all the numbers in the antidiagonal are the same.\n",size,size);
	}
	else {
		printf("The matrix is %dx%d but not all the numbers in the antidiagonal are the same.\n",size,size);
	}
	
	
	fclose(Matrix);
	free(mat1);
	
	/*Part 2*/
	int * ptr_1,* arr; /*These are all normal variables found in the memory stack.*/
	ptr_1 = (int *) malloc(sizeof(int)); /*The typecasting is actually necessary in C++, but not here.*/
	*ptr_1 = 7;
	printf("The value of ptr_1 is %d.\n",*ptr_1); /*Dynamically allocated pointer can be given values*/
	free(ptr_1);
	
	arr = (int *) calloc(40,sizeof(int)); /*The pointer is assigned to the address of the memory creation.*/
	for (i = 4; i > -1; i--) { /*Assigns values to the integer matrix*/
		arr[i] = i*4-1;
	}
	/*Literally print(arr) in Python.*/
	printf("["); /*FORMAT*/
	for (i = 0; i < 5; i++) { /*Print out values*/
		printf("%d",*(arr+i));
		if (i!=4){ /*FORMAT*/
			printf(", ");
		}
	}
	printf("]\n"); /*FORMAT*/
	
	FILE * f = fopen("lab8.txt","r"); 
	int how_many;
	fscanf(f,"%d",&how_many);	
	
	arr = realloc(arr,how_many*sizeof(int)); /*Re-assigns array to new size in bytes.*/
	
	for (i = 0; i < how_many; i++) { /*Now read values from a file*/
		fscanf(f, "%d", &arr[i]);
	}
	
	arrayOut(arr,how_many);
	printf("The number of 0's in the array is %d, and the number of negatives is %d.\n",count_zeros(arr,how_many),count_negs(arr,how_many));
	free(arr);
	fclose(f);
	
	/*PART 4*/
	int countc,countw;
	char string[901], ** words;
	puts("Please enter a grammatically correct sentence here boiii (don't go over 900 characters please).");
	fgets(string,901,stdin);
	for (i = 0; i < 901; ++i) { /*To get rid of that annoying \n*/
		if (string[i] == '\n') string[i] = '\0';
	}
	countc = strlen(string);
	countw = countWords(string);
	
	printf("\"%s\" has %d characters, %d words\n",string,countc,countw); /*Try "This sentence has exactly fourty-nine characters." without the quotation marks*/
	for (i = countc-1; i >= 0; i--) { /*This just reverses the characters printed.*/
		printf("%c",string[i]);
	}
	/*Now for the hardest part:*/
	words = (char **) calloc(countw,sizeof(char *));
	puts("");
	/*Do something with the words variable.*/
	reverseWords(words,string,countw);
	
	for (i = 0; i < countw; i++) {
		printf("%s ",words[i]);
	}
	
	for (i = 0; i < countw; i++) {
		free(words[i]);
	} 
	free(words);
	
	/*HOMEWORK*/
	char string2[] = "Hello";
	int tries = 5;
	while (tries > 0) {
		if (strcmp(string2,"Hello")) {
			puts("Hi");
			break;
		}
		else {
			tries--;
			printf("Incorrect. Try again (%d attempts remaining): \n",tries);
		}
	return(0);
}


int countWords(char * arr) {
	int i = 0, count = 0;
	while (arr[i] != '\0') {
		i++;
		if (arr[i] == ' ') { /*This can't handle cases where multiple spaces are used yet.*/
			count++;
		}
	}
	if (arr[0] != '\0' && arr[0] != ' ') {
		count++;
	}
	return(count); /*In normal english spaces are always one less than number of words.*/
}

void reverseWords(char ** arr2, char * original, int words) {
	int i,j = 0,u,k;
	for (i = words-1; i >= 0; i--) {
		u = j; /*Bookkeeping purposes.*/
		while (original[j] != ' ' && original[j] != '\0') { /*This function just counts the characters in the word.*/
			j++;
		}
		arr2[i] = (char*) calloc(j-u+1,sizeof(char)); /*j-u will always return the size of the characters, the +1 is for the null pointer.*/
		for (k = u;k < j;k++) { /*U is just important for "rewinding" the array so that the function can now read in characters to the array of words.*/
			arr2[i][k-u] = original[k];
		}
		arr2[i][j-u] = '\0'; /*Terminating character.*/
		j++; u++; /*To ensure they both start after the space.*/
	}
}