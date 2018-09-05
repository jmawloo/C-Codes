#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*Dial math for fabs, and lib for abs*/

static int globe; /*By default any global or static values are set to 0*/

int main() {
	int decnum = 11, hexnum = 0xB, octnum = 013, i;
	__int64 unlongnum = 3000000000LLU;
	char a = 'A', anum = '65', anumhex = '\x41', anumoct = '\101';//anum doesn't work as intended.
	printf("%c %c %c %c %lld ",a,anum,anumhex,anumoct,unlongnum);
	
	for (i = 0; i <=31; i++) {
		printf("%d\n",rand());
	}
	for (;;)
	printf("Now printing some more random values\n");
	srand(34); //Sets the seed for the random function. 
	for (i = 0; i <=30; i++) {
		printf("%d\n",rand());
	}
	int *ptr = &i,*deg2ptr = &ptr;
	double *nullptr = NULL; //Null pointer.
	printf("Value of i before: %d\n",i);
	*ptr = 343;
	printf("Value of i after ptr change: %d (calling from ptr %d also works)\nPointer address is %d\n",i,*ptr,&ptr); //Ignore the warning.
	*deg2ptr = 666;	
	printf("The value of the variable i is now: %d\n",i);
	printf("The nullpointer points to address %lf, and only address %1.9lf.\n", nullptr, nullptr);
	
	puts("Woah dude \nraw text?");  //Useless redundant function (jk Ily puts).
	
	int num1 = 100,num2 = 250;
	double avg = (double) (num1+num2)/2;
	printf("Here's an average: %20.3lf",avg);
	
	decnum = (decnum < 12 ? 3: 4); /*Ternary conditional. If statement is true, assign variable to 3, else assign it to 1.*/
 	
	/* *(pointer + i) actually adds the pointer by 2 bytes, not 1, since integer types take 2 bytes in memory (8-bit).*/
	
	char name2[] = "Bernie Sanders."; /*16 characters, including \0*/
	printf("%s %c %d",name,name2[15],sizeof(name2)); 
	
	
	
	char yourname[4];
	gets(yourname); /*You'll fuck up another area of your memory if you use this like that.*/
	fgets(yourname,sizeof(yourname),stdin); //Stdin is keyboard input. 
	
	printf("The length of your string is %d\n",strlen(name)); //Strlen does not include null character.
	printf("\"%s\" is now ",name);
	strcpy(name,"Tiny Hands.");
	printf("\"%s\"\n",name);
	return 0;
}


/*#pragma message("STRINGS!")

#include <stdio.h>
#include <string.h>

typedef int foo; //U can use foo, but u can also still use int.

struct Fuccbois{ //1 way of declaring struct
	char name[21];
	foo age;
	double height;
	char character[21];
	foo IQ;
}; //DO NUT FORGET SEMICOLAL

struct{ //Another way.
	foo health;
	int mana;
	char name[30];
} Player1,Player2 = {200,100,"John Smith"};

typedef struct{
	char name[20];
	int strength;
	double health;
} entity;

entity GetEntity(void){
	entity ent;
	printf("Enter name: "); gets(ent.name); //Weird. Make sure this is not directly before the return statement and it'll work.
	printf("Enter health: "); scanf("%lf",&ent.health);
	printf("Enter strength: "); scanf("%d",&ent.strength);
	return ent;
}

void ShowEntity(entity ent) {
	printf("%s has %lf health and %d strength. ",ent.name,ent.health,ent.strength);
}

int main(void) {
	
	struct Fuccbois P1;
	puts("Enter your character's name: [max 20 characters] ");
	//fgets(P1.name,21,stdin); This also reads in a new line, so be careful.
	gets(P1.name); //The good thing about this is it doesn't read in a new line.
	puts("Now enter their character: [max 20 characters] ");
	//fgets(P1.character,21,stdin);
	gets(P1.character);
	printf("%s's character is %s\n",P1.name,P1.character);
	
	puts("Enter player 1's name: ");
	Player1.health = 100; Player1.mana = 300; gets(Player1.name);
	puts("Enter player 2's name: ");
	printf("%s has %d health and %d mana\n",Player1.name,Player1.health,Player1.mana);
	printf("Default character %s has %d health and %d mana\n",Player2.name,Player2.health,Player2.mana);
	
	entity Creeper = GetEntity();
	ShowEntity(Creeper);
	
	
	return 0;*/
	int main(int argc, char * argv[]){
	int i;
	/*argument 0 identifies the program*/
	//printf("%s\n",argv[0]);
	/*the other arguments*/
	/*for (i=1;i<argc;++i)
		printf("%s ",argv[i]);
	*/
	printf("No, %c.\a",argv[1][0]);
	return(0);
	
}

