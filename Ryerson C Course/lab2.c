#include <stdio.h>
#include <math.h>
#define PI 3.141592653

int 
main (void) 
{	//Part 1: Errors
	int a = 3, b = 4,e = 4; //Strangely enough, only if you subtract nums of same value, both of type int will you get a runtime error when dividing another number by it.
	double f = 4, c, d, num ;
	
	//Truncate 0 ->0.0 Or usually truncate towards 0 (e.g. 0.867 -> 0.8)
	d = a + b;
	c = a / (f - b); //Subtracting numbers of these different types does not give an exact value of 0. (Gets truncated).
	printf("The value of d is %-6f and the value of c is %1f\n\n", d, c); //%-6f left-justifies number and reserves 6 places. All numbers displayed even if space allocated too narrow.
	
	//Part 2: Rounded numbers
	printf("What\'s your number? ;)");
	scanf("%lf", &num);
	printf("Alright, so I get ur number is to the nearest thousandth, %10.3lf?\n", num); //reserves 10 character places & rounds to 3 decimal places.
	printf("Or is it to the nearest hundredth, %-8.2lf?\n", num); //.n where n is a non-negative integer by default rounds the last number. 
	
	
	//Part 3: Circumference of ellipse
	printf("Please enter your long and short radii, in no particular order: "); //Don't enter invalid inputs XD.
	scanf("%lf%lf",&f,&c); //Don't forget the ampersand! scanf takes parameters of the address of the variables!
	printf("Your circumference is: %1.4lf\n", sqrt((f*f+c*c)/2) * 2*PI); //Rounded to 4 decimal places.
	
	printf("%c %c \n",'255',255);
	
	num = 5%3;
	printf("%5.3lf", num); //How low a level C is. You can't even directly print out variables.
	
	/* Part 4: Short-answer questions.
	1. char is a reserved keyword that represents a data type in C, Char can be declared and used as a variable, although it's not recommended.
	2. printf("%d",3/4); outputs '0', since %d represents an integer placeholder.
	3. printf("%f", 50); is not valid, because a low-level language can't auto-convert values to different types.
	4. If you omit the ; at the end of any statement, the program will not compile correctly. 
	5. %f is for floating-point numbers, %lf is for the double type numbers (long float).
	6. If it's an int 0, runtime error. If it's a float or double 0.0, then it returns "inf" (infinity).
	7. 35%15.3 is invalid. The number on the right of operator token is of type double when it should be of type int. (However typing printf("35%15.3"); displays 35 without any spaces. 
	8. Declaring int before main(void) requires a return of type int. Just declaring main() however is normally insufficient because the return type is not specified, however in certain compilers the required parameters are automatically filled in. 
	9. The %c placeholder works with only characters. So only the numbers '0' through '9' will be displayed in their entirety if the numbers are surrounded in single quotes. Applying the single quotes to 255 will only keep the last digit 5.
	10. Nope. 5/3 returns a 1.66666..., 5%3 returns 2, and 5.0/3 returns the same value as 5/3.
	*/
	
	/*Part 5: Discovery:
	Integer variables are variables with values that belong to the set of integer numbers. Double variables are variables with (an approximation of) values that belong to the set of real numbers.
	*/
}