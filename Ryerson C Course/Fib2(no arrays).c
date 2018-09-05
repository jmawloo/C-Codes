#include <stdio.h>
#include <math.h>

int main(void) {
	int a=0,b=1,c,n1 = 0,n2 = 0,range,index,ele = -1;
	double g1;
	
	/*User inputs*/
	puts("Enter the maximum number you want the Fibonacci sequence to go up to.");
	scanf("%d",&range); 
	puts("Enter the i'th number you want to see (starting from 1): ");
	scanf("%d",&index);
	
	puts("Your fibonacci numbers are (# in square brackets are perfect squares): \n");
	puts("Fib number | Golden Ratio Approximation");
	while (a <= range) {
		if ((int) sqrt(a) == sqrt(a)) { /*Perfect square tester*/
			printf("[%-8d] |",a);
			n2++;
			n1++;
		}
		else {
			printf("%10d |",a);
			n1++;	
		}
		
		if (n1 >= 3) { /*Golden Ratio code*/
			g1 = (double) b/a;
			printf("%5.4lf\n",g1);
		}
		else{ /*Just for formatting purposes*/
			puts(""); /*prints a new line*/
		}
		
		if (n1 == index) { /*Assigns the current number user requested*/
			ele = a;
		}
		
		c = a; /*Fibonacci generator */
		a = b;
		b += c;		
	}
	if (ele != -1){
		printf("Element #%d in the sequence is %d.\n", index, ele);
	}
	else {
		puts("Sorry, the number you requested is out of range of this sequence.");
	}
	
	printf("The sequence has %d numbers in total, and %d perfect square root numbers, with the golden ratio being %.3lf.\n",n1,n2,g1);
}