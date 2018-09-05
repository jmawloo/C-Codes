#include <stdio.h>
#include <stdlib.h> //Gotta include this too so the program works.
#include <math.h>
#define YA 1.094
#define MI 6.215e-4
#define M_PI 3.14159265358979323846

int
main(void) {
	int n1,n2,n3,n4,sum, sqsum;
	printf("Please input 4 numbers, separated by the enter key:\n");
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4); //getting user input
	sum = n1 + n2 + n3 + n4;
	printf("The sum of the 4 numbers entered is: %d.\n", sum); //Finding the sum.
	
	printf("The difference of the sum of the 1st 2 numbers and the sum of the last 2 numbers is: %d.\n", (n1 + n2)- (n3 + n4));

	sqsum = n1*n1 + n2*n2 + n3*n3 + n4*n4;
	printf("The sum of the squares of these numbers is: %d.\n", sqsum);
	
	printf("The inaccurate quotient of the square root of the sum of the squares of the numbers divided by the sum of all the numbers is: %1.10f\n", (float) sqrt(sqsum)/ (float) sum);
	printf("The quotient of the square root of the sum of the squares of the numbers divided by the sum of all the numbers is: %1.10lf\n", sqrt(sqsum)/(double) sum);
	
	//#6:
	
	//Setting program parameters
	int len,i;
	double *ptr;
	
	printf("Enter how many distances you want to calculate here:\n"); 
	scanf("%d",&len);
	
	ptr = (double*) calloc(len,sizeof(double)); //How C dynamically allocates memory to multiple elements.
	
	//Getting user input.
	printf("Enter your distances (in metres):\n"); 
	
	for (i = 0; i < len; i++) { //Lumping user input with computation and output.
		scanf("%lf",ptr + (int) i);
	}
	
	printf("Metres(m) | Yards(Y) | Miles(mi)\n");
	
	for (i = 0; i < len; i++) {
		printf("%10.2lf|%10.2lf|%10.2lf\n",ptr[i],ptr[i]*YA,ptr[i]*MI);
	}
	
	free(ptr); //Don't forget this!
	
	//HOMEWORK:
	double n,result;
	printf("Enter your number to be !'d.:  ");
	scanf("%lf",&n);
	
	result = exp(n*-1)*pow(n,n)*sqrt((2*n+1/3)*M_PI);
	printf("Your answer is %1.3lf\n",result);
	
	
	/*This repeats the entire code*/
	system("PAUSE");
	system("CLS");
	system("lab3");
	
	return (0);
}