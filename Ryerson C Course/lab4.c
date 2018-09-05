#include <stdio.h>
#include <stdlib.h>

char gradecheck(float *m, double a) {
	/*Function for gradechecking the efficient way.*/
	char g;
	if (m[0] < 50 || m[1] < 50) {
		a = 49;
	}
	
	else if (m[2] < 50 || m[3] < 50) {
		a -= 10;
	}	
	
	if (a < 50) {
		g = 'F';
	}
	
	else if (a < 60) {
		g = 'D';
	}
	
	else if (a < 70) {
		g = 'C';
	}
	
	else if (a < 80) {
		g = 'B';
	}
	else {
		g = 'A';
	}
	
	
	return g;
}


int maxNum(int c,int * l) {
	/*Compares the numbers and outputs the max num. Takes in count and list as parameters.*/
	int max = l[0],i,a=0;
	for (i = 0; i < c; i++) {
		if (l[a] < l[i+1] && i + 1 < c) {
			max = l[i+1];
			a = i + 1;
			printf("%d ",max); //#DEBUG
		}
	}
	puts("");
	return max;
}

int main(void) {
	float marks[] = {0,0,0,0};
	double avg = 0;
	char grade;
	puts("Please enter the 2 test marks, then the 2 assignment marks (out of 100): ");
	
	for (int i = 0; i<4; i++) { 
		scanf("%f",&marks[i]);
		avg += marks[i];
	}
	avg = avg /4.0;
	printf("Average is: %lf\n",avg); //DEBUG
	
	grade = gradecheck(marks,avg);

	printf("Your final grade is: %c\n", grade);
	switch (grade) {
		case  'A': {
			puts("That's quite average.");
			break;
		}
		case  'B': {
			puts("Taking too many FortNite breaks?");
			break;
		}
		case  'C': {
			puts("Can't you try just a little harder?");
			break;
		}
		case  'D': {
			puts("Detention for you. 15 seconds. When will you learn?");
			break;
		}
		case  'F': {
			puts("Mission Failed! We'll get 'em next time!");
			break;
		}
	    default {
			puts("Contact the dev if you see this message. Because he sucks more than you do :)");
		}
	}
	
	/*Part 2: Find the errors (assuming all variables were declared earlier)
	if (x = 1) printf ("x is 1"); <- = is an assignment operator, not a comparison operator. Still compiles
	if (x = 1); <-Same reason as above. Also compiles
	if (x == 1) printf ("x is 1); <-missing a quotation mark. Doesn't compile, unexpected EOF while scanning string literal.
	if (x == 1) if (x>100) printf ("OK"); <-Works, but the nested if statement will never execute.
	if (x == 1) j=i; <- Valid code.
	if (x == 1) {j=j+x;k=100/j;} <- Also valid code as long as j + x != 0.
	*/
	
	/*Maximum of 3 given numbers*/
	
	int num,j,max, *list;
	puts("Enter how many numbers you want compared: ");
	scanf("%d",&num);
	
	list = (int*) calloc(num,sizeof(int));
	for (j=0;j<num;j++) {
		printf("Enter your #%d number: ",j+1);
		scanf("%d",&list[j]);
	}
	
	max = maxNum(num,list);
	printf("Your biggest number is: %d",max);
	
	free(list); //DO NOT FORGET TO DO THIS.
	
	/*PART 3: RESEARCH
	if (x=1) {} will ALWAYS execute because the condition it evaluates is x, which has a value of 1 corresponding to Boolean "True". 
	if (x=0) {} will NEVER execute b/c x == 0, corresponding to "False".
	*/
	
	/* Inefficient comparison code.
	puts("Enter your 3 numbers to be compared: ");
	scanf("%d%d%d",&n1,&n2,&n3);
	
	if (n1 > n2 && n1 > n3) {
		printf("%d is your max number",n1);
	}
	else if (n1 > n2) {
		printf("%d is your max number",n3);
	}
	else if (n1 > n3) {
		printf("%d is your max number",n2);
	}
	else {
		if (n2 > n3) {
			printf("%d is your max number",n2);
		}
		else {
			printf("%d is your max number",n3);
		}
	}
	*/
	
	/*Part 4: Homework - Pollution meter*/
	//int num;
	float miles,ratio;
	int result;
	
	puts("(1) Carbon monoxide");
	puts("(2) Hydrocarbons");
	puts("(3) Nitrogen oxides");
	puts("(4) Nonmethane hydrocarbons");
	
	printf("Enter pollutant number>> ");
	scanf("%d",&num);
	
	printf("Enter number of grams emitted per mile>> ");
	scanf("%f",&ratio);
	
	printf("Enter odometer rating>> ");
	scanf("%f",&miles);
	
	switch (num) {
		case 1: {
			if (miles <= 50000) {
				result = ratio <= 3.4;
				ratio = 3.4;
			}
			else {
				result = ratio <= 4.2;
				ratio = 4.2;
			}
			break;
		}
		case 2: {
			if (miles <= 50000) {
				result = ratio <= 0.31;
				ratio = 0.31;
			}
			else {
				result = ratio <= 0.39;
				ratio = 0.39;
			}
			break;
		}
		case 3: {
			if (miles <= 50000) {
				result = ratio <= 0.4;
				ratio = 0.4;
			}
			else {
				result = ratio <= 0.5;
				ratio = 0.5;
			}
			break;
		}
		case 4: {
			if (miles <= 50000) {
				result = ratio <= 0.25;
				ratio = 0.25;
			}
			else {
				result = ratio <= 0.31;
				ratio = 0.31;
			}
			break;
		}
		default: {
			puts("Congrats on breaking the code. You win nothing.");
		}
	}
	if (result) {
		printf("Emissions within the permitted level of %.2f",ratio);
	}
	else {
		printf("Emissions exceed permitted level of %.2f",ratio);
	}
	return(0);
}