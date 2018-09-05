#pragma once //REDUCES BUILD TIMES AND PROGRAM WILL NOT OPEN AND READ FILE AFTER 1st INCLUDE.
#include <stdio.h>
#include <math.h>

/*Part 1*/
int large(int a,int b,int c) { //This function includes numbers of same value 
	int largenum;
	if (a >= b && a >= c) {
		largenum = a;
	}
	else if (b >= a && b >= c) {
		largenum = b;
	}
	else {
		largenum = c;
	}
	return largenum;
}


/*Part 1*/
int small(int a, int b, int c) { //This function includes numbers of same value
	int smallnum;
	if (a <= b && a <= c) {
		smallnum = a;
	}
	else if (b <= a && b <= c) {
		smallnum = b;
	}
	else {
		smallnum = c;
	}
	return smallnum;
}


/*Part 2*/
int find10(int y, int * z);	

/*Homework*/
double speed_ratio(double x, double y) {
	return sqrt(x/y);
}

int main(void) {
	/*Part 1*/
	int a,b,c,largenum,smallnum;
	puts("\aEnter your three integers here (Make sure they're not all the same)");
	
	scanf("%d%d%d",&a,&b,&c);
	
	if (a == b && b == c) {
		puts("Your numbers are all equal in value, genius. Run the program again and follow the instructions smh.");
		return -1;
	}
	
	largenum = large(a,b,c);
	smallnum = small(a,b,c);
	printf("The largest number of the three is %d, and the smallest is %d\n",largenum,smallnum); //DEBUG
	
	/*Part 2*/
	int num, tens, left;
	puts("What's ur number? ;););)");
	do {
		scanf("%d",&num);
	} while (num < 10 || num > 999);
	tens = find10(num,&left);
	printf("The number of 10's is %d, and the remainder is %d\n",tens,left);
	printf("\a");
	
	/*Homework*/
	double max,min,speedratio;
	puts("Enter your max and min reading: ");
	scanf("%lf%lf",&max,&min);
	speedratio = speed_ratio(max,min);
	printf("The ratio between successive speeds of a 6-speed gearbox with max speed %.3lf rpm and min speed %.3lf rpm is %.3lf.\n",max,min,speedratio);
	return(0);
	}

	


/*Part 2*/
int find10(int y, int * z) {
	int tens,left;
	tens = y / 10;
	left = y % 10;
	*z = left;
	return tens;
}