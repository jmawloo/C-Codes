#include <stdio.h>

int Floyd(int r) { //Will return the largest number in the triangle for the function reverseFloyd.
	int count = 1, i, j;
	for (i = 1; i <= r; i++) { //Get "i" amount of elements in one row, starting with one element.
		for (j = 0; j < i; j++) {
			printf("%3d",count++); //Postfix works in a printf statement.			
		}
		puts("");
	}
	count--;
	return count; //This will actually be one more than it should be without the count--
}

void reverseFloyd(int r, int count) {
	int i, j;
	for (i = r; i > 0; i--) { //Now we start with "r" (rows) elements.
		for (j = 0; j < i; j++) { 
			printf("%3d",count--);
		}
		puts("");
	}
}

int main() {	
	int rows, count;	
	puts("How many rows do you want in your Floyd Triangle?");
	scanf("%d",&rows);
	count = Floyd(rows); //So we can use it in the next function.
	puts("");
	reverseFloyd(rows, count);
	return(0);
}
