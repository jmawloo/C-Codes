#pragma message("NOTICE ME SENPAI")

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.141592653
#define E 30e6

typedef struct{
	float line, radius, areacircle, areacylinder, volumecylinder;
} shape; //Do not forget semicolon

typedef struct{
	float p,d,stress,strain;
} strength;

typedef struct cars{
	char make[20],model[20],color[10];
	int year;
	struct cars *next;
} car;

car * getCars() { /*This function obtains all the values for the car elements in the linked list.*/
	car * first = (car*) calloc(1,sizeof(car)), * current; /*The first element, which will be the function's return value.*/
	int choice = 0;
	current = first; 
	
	do { /*First execution is special.*/
		if (choice) { /*Don't want this to run the first time.*/
			current = current->next = (car*) calloc(1,sizeof(car)); /*This assigns all subsequent node addresses to the previous node's "next" attribute.*/
		}
		/*Prompt user for information.*/
		
		getchar(); /*Because of the nature of C to hold in excess inputs in stdin, this needs to be here to get rid of the garbage input.*/
		printf("Enter make: [max 19 characters]"); 
		gets(current->make);
		printf("Enter model: [max 19 characters]");
		gets(current->model);
		printf("Enter color: [max 9 characters, lowercase]");
		gets(current->color);
		printf("Now enter the year: ");
		scanf("%d",&current->year);
		
		puts("");
		printf("More? [y=1,n=0] "); /*User input validation loop.*/ 
		scanf("%d",&choice); 
	} while(choice);
	
	current->next = NULL; /*Sets the "next" attribute of the last node to the NULL pointer.*/
	puts("");
	return(first);
}

void showCars(car * first) { /*Prints out all information for yellow cars exclusively newer than 2010.*/
	car * ptr = first;
	for (ptr; ptr != NULL; ptr = ptr->next) {
		if ( !strcmp(ptr->color,"yellow") && ptr->year > 2010) { /*strcmp() oddly returns 0 if the strings are the same.*/
			printf("SWIPELOCK! :D The %s %s %s was made in %d.\n",ptr->color,ptr->make,ptr->model,ptr->year);
			/*Bonus points if you know what "Swipelock" means.*/
		}		
	}
}

int main(void) {
	/*Part 1*/
	shape c1;
	puts("Enter the length of your cylinder and its radius, separated by spaces: ");
	scanf("%f%f",&c1.line,&c1.radius);	/*Gets the required inputs from the user*/
	
	c1.areacircle = PI*pow(c1.radius,2);
	c1.areacylinder = 2*(c1.areacircle+PI*c1.radius*c1.line);
	c1.volumecylinder = c1.areacircle*c1.line;

	printf("For a cylinder %.3f m long and %.4f m in diameter, the surface area is %.4f m^2 and the volume is %.4f m^3\n",c1.line,2*c1.radius,c1.areacylinder,c1.volumecylinder);
	
	puts("");
	float area;
	strength col;
	puts("Now enter the compression load and diameter of a column, separated by spaces: ");
	scanf("%f%f",&col.p,&col.d);
	
	area = (PI*pow(col.d,2))/4;
	col.stress = col.p/area;
	col.strain = col.stress/E;

	printf("For a compression of %.3f and a diameter of %.3f, the strain experienced is %.4f and the stress is %.4f\n.",col.p,col.d,col.strain,col.stress);

	car * start = getCars(), *ptr; /*Initialize the start of the linked list. Use *ptr as a bookkeeper.*/
	
	/*DEBUG*/
	for(ptr = start; ptr != NULL; ptr = ptr->next) { /*Prints everything out.*/
		printf("The %s %s %s's year is %d.\n",ptr->color,ptr->make,ptr->model,ptr->year);
	}
	
	showCars(start);
	
	/*Cleanup*/
	ptr = start;
	while(ptr != NULL) { /*Another way to iterate through a linked list.*/
		start = ptr;
		ptr = ptr -> next;
		free(start); /*This will free the car element being referenced by back into the heap.*/
	}
	/*Part 3 (Not actual code, just an answer to the output of one.
	
	Reply from jeff.ma@cps125.scs.ryerson.ca/labs/pics/9d.png: 
	1004 1008 1058
	*/
	
	return(0);
}