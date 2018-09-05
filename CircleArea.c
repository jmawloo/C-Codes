#include <stdio.h>
#include <math.h> //For the pow function.
#include <windows.h>
#define PI 3.141592653 //Define PI to be the value of pi for the entire program.


int main(void) {
	double rad, area; //Pointer variable. Also declaration of variable.
	int i;
	printf("Enter radius: ");
	scanf("%lf", &rad); //Scanning input to memory address of rad in format %lf. A long float is a double.
	area = pow(rad,2)*PI; //Area calculation.
	printf("Your area is %lf", area);
	for (int i=0;i<100000;i++) {
		if (i%10000 == 0) {
			printf("\a\n");
		}
	}
	Sleep(1000);
	Beep(777,100);
	Beep(777,100);
	Beep(777,100);
	Beep(777,500);
	Beep(777,500);
	Beep(777,500);
	Beep(777,77);// On windows 10 doesn't work properly D:
	Beep(777,77);
	Beep(777,77); 
	Sleep(2000);
	
	for (i = 0; i < 5; i++) {
		Beep(1000,100);
		printf("11:59:5%d",5+i);
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b");
	}
	printf("12:00:00");
	Beep(1000,500);	
	

	return 0;
}