#include <stdio.h>
#include <stdlib.h>

int factorial(int x) {
	/*Efficient factorial calculator that can be reused*/
	int i,prod=1;
	for (i = x; i > 0; i--) {
		prod *= i;
	}
	return prod;
}


void permutate(char* str, char** perm_, int depth, int index, int ch) {
	/*Recursion function. The terminating statement is determined by ch.*/
	int i,j,count,temp,index2 = index; //count used to index next char in string, assigning index2 to passed parameter index for bookkeeping, temp is index for ltemp array
	char *ltemp;
	ltemp = (char*) calloc(ch-1,sizeof(char));
	
	count = 0;
	
	
	if (ch < 1) { //DEBUG
		puts("Error! Minimum number of letters must be 1! Please run the code again. (This should also never execute)");
		exit(-1);
	}
	
	if (ch < 2) {
		perm_[index][depth] = str[count];
		perm_[index][depth+1] = '\0'; //**Neglecting the null character leads to unexpected problems.
		return; //void function returns nothing but this will end the function execution early.
	}
	
	for (i = index; i < factorial(ch)+index; i++) {//Run this loop #char! times and add the upper bound by index for bookkeeping.
		perm_[i][depth] = str[count];
		if ((i+1) % factorial(ch-1) == 0) { //The leftmost character always appears in each permutation exactly (#char-1)! times (and the one next to it appears (#char-2)! times. 
			temp = 0;
			for (j = 0;j < ch;j++) { //For loop needs to be run ch* times for ch-1 variables to be stored in temp list.
				if (j!=count) {
					ltemp[temp] = str[j]; //Used to store remainder letters in ltemp, sequentially.  
					temp++;
				}
			}
			permutate(ltemp,perm_,depth+1,index2,ch-1);
			count++;
			index2 = i+1; //Will execute after the mini-permuations are performed. Assigns index to i(**+1) for bookkeeping purposes.
		}
	}
	free(ltemp);
}


void joinchars(char** perm_, int ch, int fact, FILE *out) {
	/*This function combines all the results obtained in the multiarray and outputs them.*/
	int i,j;
	
	for (i=0;i<fact;i++) {
		printf("%s\n",perm_[i]); //String placeholder for arrays of characters.
		fprintf(out,"%s\n",perm_[i]);
	}
	puts("");
}


int main() {
	int ch,i,depth = 0,index = 0,fact;
	/*Will also be writing code to file.*/
	FILE *out = fopen("stringpermuteoutput.txt","w");
	/*ch to store letters of word, depth for array index in multiarray itself, ,index for array accessing in perm multiarray storage,*/
	
	printf("How many letters does your word contain? (safe range is 1 to 5, the code breaks at 8): ");
	scanf("%d",&ch);
	
	char * str, **perm_; //Need to add double asterisks for multidimensional arrays.
	fact = factorial(ch); //Returns # of all possible permutations. Storing it reduces power consumption in code.
	
	perm_ = (char**) calloc(fact,sizeof(char*));
	for (i=0;i<fact;i++) {//How to allocate arrays to multiarray.
		perm_[i] = (char*) calloc(ch+1,sizeof(char)); //This has to include the null character too.
	}
	str = (char*) calloc(ch+1,sizeof(char)); //allocates array of word length size.
	
	printf("Array pointer size: %d. Array pointer element size: %d. Number of elements in array: %d\n",sizeof(perm_),sizeof(char*),fact);//DEBUG
	
	printf("Enter your %d-letter word: ",ch);
	
	/*scanf_s is for Microsoft VS only. May not work in other compilers. Replace code chunk with scanf("%s",str)nk if you have a different compiler.*/
	if (scanf_s("%s",str,ch+1) == 0) { 
		printf("You've entered too many characters, please try again.");
		return(-1);
	} //Ch + 1 takes care of the null-character. Also ensures that the user does not input too many characters.
	
	//Calls upon the function to permutate the word
	permutate(str,perm_,depth,index,ch);
	
	//Once storage is complete, this function outputs everything stored
	joinchars(perm_, ch, fact,out);

	for (i=0;i<fact;i++) { //How to free multiarrays.
		free(perm_[i]);
	}
	free(str); //Don't forget code cleanup.
	free(perm_);
	fclose(out);
	
	return 0;
}



