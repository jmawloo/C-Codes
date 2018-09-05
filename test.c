#pragma warning (once:4385;error:300)

#include <stdio.h>
#include <math.h>


int * twonums(int a, int b); //There aren't any default parameter values in C. :c
int globalvar = 0;
void returnmax(double a, double b, double *c);
int split(double n, double *f, char *s);


int main() {
	long int a,b,diff,*list;
	double max,c,d,n;
	char s;
	puts("Enter your 2 numbers:");
	scanf("%d%d",&a,&b);
	list = twonums(a,b);
	printf("%d\n",globalvar);
	globalvar = 10;
	printf("The sum is %d, the difference is %d, and the global var is now %d\n",list[0],list[1],globalvar);
	
	puts("Enter 2 numbers to find the bigger one:");
	scanf("%lf%lf",&c,&d);
	returnmax(c,d,&max);
	if (c == -2147483648) {
		return (-1);
	}
	printf("The larger number is %.5lf\n",max);
	
	puts("Enter your decimal number to be categorized:");
	scanf("%lf",&n);
	a = split(n,&c,&s);
	printf("The sign is %c, the whole number is %d, and the decimal counterpart is %lf\n",s,a,c);
	return (0);
}

int * twonums(int a, int b) { //Modular Programming.
	static int result[2]; //THE RETURN OF THE STATIC MODIFIER :D
	result[0] = a+b;
	result[1] = a-b;
	globalvar = -1;
	return result;
}

void returnmax(double a, double b, double * c) {
	if (a < b) {
		*c = b;
	}
	else if (a > b) {
		*c = a;
	}
	else {
		puts("You entered numbers of the same value, genius. Run the program again.");
		*c = -2147483647;
	}
}

int split(double n, double *f, char *s) {
	int a;
	if (n < 0) {
		*s = '-';
	}
	else {
		*s = '+';
	}
	n = fabs(n);
	a = (int) floor(n);
	*f = n - a;
	return a;
}