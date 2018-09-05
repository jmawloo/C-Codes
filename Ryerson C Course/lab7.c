#pragma message("This is the 7th lab.")

#include <stdio.h>
#include <limits.h>

void tenfold(int *a1, int *a2,int size); /*HOMEWORK*/

int main(void) {
	/*Part 1*/
	double x_arr[10],xhigh = LONG_MIN, temp, xlow = LONG_MAX,x_second_arr[10],max,min,norm_x_arr[10] ; /*Smallest 32-bit number.*/
	FILE * i = fopen("TestData.txt","r");
	unsigned int count = 0;
	if (i == NULL) {
		fprintf(stderr,"Could not find file\n");
		return(1);
	}
	
	while ( !feof(i) ) { //This is another way of testing end of file.
		fscanf(i,"%lf",&x_arr[count]);
		count++;
	}
	
	puts("number | 3*number"); //Formatting columns.
	for (count = 0; count < 10; ++count) {
		temp = *(x_arr+count); //Another way to get the element from the array.
		if (xhigh < temp) {
			xhigh = temp;
		}
		if (xlow > temp) {
			xlow = temp;
		}
		x_second_arr[count] = *(x_arr + count) * 3;
		printf("%6.5lf %6.5lf\n",temp, x_second_arr[count]);
	}
	printf("The highest number in the array is %.3lf. The lowest is %.4lf\n",xhigh,xlow);
	
	puts("Now enter the new max and min you want your dataset to be normalized to: ");
	scanf("%lf %lf",&max,&min);
	
	puts("Your normal numbers are: ");
	for (count = 0; count < 10; count++) {
		*(norm_x_arr + count) = min + ((x_arr[count] - xlow) * (max-min))/(xhigh-xlow);
		printf("%.4lf\n",norm_x_arr[count]);
	}
	puts("\n");
	fclose(i);
	
	/*Part 2*/
	int monthly_water_arr[50],num_months = 0,c,temp2, small = 61;
	static int count_arr[7];
	
	FILE *j = fopen("water.dat","r"); 
	if (j == NULL) {
		fprintf(stderr,"Could not find file\n");
		return(1);
	}
	while (!feof(j)) {
		fscanf(j,"%d",&monthly_water_arr[num_months]);
		num_months++;
	}
	//puts("\"__\" indicates values between 71 and 80, inclusive.");
	for (c = 0; c < num_months; c++) {
		temp2 = monthly_water_arr[c];
		printf("%d\n",temp2);
		
		if (temp2 >= 71 && temp2 <= 80) {
			count_arr[0]++;
			//printf("__\n");
		}
		else if (temp2 <= 90) {
			count_arr[1]++;
		}
		else if (temp2 <= 100) {
			count_arr[2]++;
		}
		else if (temp2 <= 110) {
			count_arr[3]++;
		}
		else if (temp2 <= 120) {
			count_arr[4]++;
		}
		else if (temp2 <= 130) {
			count_arr[5]++;
		}
		else if (temp2 <= 140) {
			count_arr[6]++;
		}
		/*
		else {
			puts("");
		}*/
	}
	puts("\n10 M gals water per day: ");
	for (c = 0; c < 7; c++) {
		small += 10;
		if (count_arr[c] == 0) {
			continue;
		}
		printf("%d-%d: ",small,small+9);
		printf("%d\n", count_arr[c]);
	}
	fclose(j);
	puts("\n");
	
	/*HOMEWORK*/
	int array1[9] = {3,4,5,6,7,-8,-9,1,2}, array2[9];
	int size = 9;
	
	tenfold(array1,array2,size);
	
	return(0);
}

void tenfold(int *a1, int *a2,int size) {/*HOMEWORK*/
	int i,temp;
	for (i = 0; i < size; i++) {
		if (a1[i] > 0) {
			temp = *(a1+i) * 10;
		}
		else {
			temp = *(a1+i);
		}
		a2[i] = temp;
		printf("%d ",a2[i]);
	}
}