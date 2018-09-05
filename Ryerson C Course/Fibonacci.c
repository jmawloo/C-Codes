#include <stdio.h>
#include <math.h> /* This is for the sqrt() function*/


int fibonacci(int r,int * l){
	/* This function yields all the fibonacci terms first, then returns the total number count. */
	int i,a = 0, b = 1, count = 0;
	while (a <= r) {
		printf("%d ", a);
		l[count] = a; 
		a = b;
		b += l[count];
		count++;
	}
	puts(""); /*Put string. Automatically introduces new line*/
	
	return(count); /*returns all the fibonacci numbers including 0*/
}


int root2(int c, int * l) {
	/* This function checks to see if the square root of any number in the 
	fibonacci sequence is an integer number. */
	int i,count2=0;

	for (i = 0; i < c; ++i) {
		if ((double) sqrt(l[i]) == (int) sqrt(l[i])) { /* Only integer square roots will not be truncated when casted to type int*/
			printf("%d ",l[i]);
			count2++;
		}
	}
	puts("");
	return count2;
}


double golden(int c, int * l) {
	/*This function computes the golden ratio starting from the third fibonacci number.*/
	int i;
	double ratio;
	for (i = 2; i < c; i++) {
		ratio = (double) l[i]/l[i-1];
		printf("%1.4lf ",ratio);
	}
	puts("");
	return ratio; /*Returns the last computed value of the golden ratio.*/
}

int element(int c, int * l) {
	/*This function displays the requested element to the user.*/
	int i;
	
	scanf("%d", &i);
	while (i < 1 || i > c) {
		puts("Error! Index out of range! Please try again. ");
		scanf("%d", &i);
	}
	return l[i-1];
}

int main(void) {
	int n, list[50],count,count2,elem; 
	double gold;
	puts("Enter the upper range for the fibonacci sequence: ");
	scanf("%d",&n);
	
	puts("\nYour fibonacci numbers are: ");
	count = fibonacci(n,list);
	printf("There are %d numbers in total\n",count);
	
	puts("The perfect square root numbers are: ");
	count2 = root2(count, list);
	printf("There are %d square root numbers in total\n",count2);
	
	puts("\nThe golden ratio computations are progressively: ");
	gold = golden(count,list);
	printf("The most accurate value of the golden ratio is %1.3lf \n",gold);
	
	puts("\nPlease enter the nth number in the sequence you want to see (starting from 1):" );
	elem = element(count,list);
	printf("The number you requested is: %d \n",elem);
	
	return(0);
}