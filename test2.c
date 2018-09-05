#pragma message("SPAAAACE!!!! (im in space)")

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct link {
	int foo;
	char bar;
	struct link * next; /*Stores the address of the next element.*/
} linked;

linked * getLinks() {
	linked * list, * first = calloc(1,sizeof(linked)); 
	int choice = 0;
	list = first; 
	do {
		if (choice) {
			list = list->next = (linked *) calloc(1,sizeof(linked)); /*You can do the assignment operator more than once in a single line.*/
		}
		printf("Enter an integral value: ");
		scanf("%d",&list->foo); 
		printf("Now enter a character: ");
		getchar(); /*Gets rid of the user's return key*/
		scanf("%c",&list->bar); 

		printf("\a*ALERT*: Enter another? [y=1,n=0] ");
		scanf("%d",&choice);
	}while (choice);
	list->next = NULL;
	return(first);
}

int main(int String, char *args[]) {
	linked *start, *ptr, *ptr2;
	int i;
	double quotient;
	start = getLinks();	
	for (ptr = start; ptr != NULL; ptr = ptr->next) {
		printf("%.4d | %c\n",ptr->foo,ptr->bar);
	}
	ptr = start;
	while (ptr !=NULL) {
		ptr2 = ptr;
		ptr = ptr->next;
		free(ptr2);
	}
	if (String == 3) {
		printf("Program %s was passed the arguments %s and %s\n",args[0],args[1],args[2]);
		quotient = atof(args[1])/atoi(args[2]);
		printf("The quotient of the 1st argument and the 2nd integer argument is: %.3lf.",quotient);
	}
	else if (String > 3) {
		puts("ERROR! Too many arguments supplied! \a");
		return(-1);
	}
	else {
		puts("ERROR! Expected 2 arguments! \a");
		return(-1);
	}
	return(0);
}