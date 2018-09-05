#pragma once
#pragma message("This is a program that contains fun matrix functions. Don't get too excited though.") /*Pragmas are just for my VS compiler.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void getMatrix(int i,int j,double someArray[],FILE *file); /*Gets the matrix.*/
double Average(int ab, double someArray[]); /*Finds the average of all the elements of the matrix*/
double Corner(int a, int b, double someArray[]); /*Finds the sum of the 4 corners of the matrix*/
double Row(int rowb, int b, double someArray[]); /*Finds the rowsum of the specified row*/
double Column(int col, int b, int a, double someArray[]); /*Finds the columnsum of the specified column*/
double Diagonals(int a, int b, double someArray[], double *antidiag); /*Calculates the sum of the diagonal and the antidiagonal, only if it's a square matrix*/
double Borders(int a, int b, double someArray[]); /*Adds up only the borderlines of the matrix with no overlaps.*/

int main(void) {
	int i,j,row,column;
	FILE *mat = fopen("matrix.txt","r");
	double *onearray, avg, corner, diag, antidiag = 0, rowsum, columnsum, bordersum;
	
	if (mat == NULL) { /*Prevents the program from further executing if it's an invalid file path.*/
		puts("Invalid file path, please try again");
		return(-1);
	}
	
	fscanf(mat,"%d %d",&i, &j);/*Store number of rows and columns here*/
	
	onearray = (double *) calloc(i*j,sizeof(double)); /*Contiguously initialize the 1-D array*/
	
	getMatrix(i,j,onearray,mat); /*Calls the getmatrix function.*/
	
	fscanf(mat,"%d %d",&row,&column); /*Gets the bookkeeping values*/
	printf("The value of row %d, column %d is %.3lf. \n",row+1,column+1,onearray[row * j + column]); /*DEBUG*/
	
	avg = Average(i*j,onearray);
	printf("The overall average is %.3lf.\n",avg); /*DEBUG*/
	
	corner = Corner(i,j,onearray);
	printf("The sum of the corners is %.3lf\n",corner);
	
	rowsum = Row(row*j,j,onearray);
	columnsum = Column(column,j,i,onearray);
	printf("The rowsum of row %d is %.3lf, and the columnsum of column %d is %.3lf.\n",row+1,rowsum,column+1,columnsum);
	
	diag = Diagonals(i,j,onearray,&antidiag);
	if (diag == INT_MAX) {
		puts("Failed to execute the Diagonals function (matrix is not a square matrix).");
	}
	else {
		printf("The sum of the diagonal is %.3lf and the sum of the antidiagonal is %.3lf\n",diag,antidiag);
	}
	
	bordersum = Borders(i,j,onearray);
	printf("The sum of the borders is %.3lf\n",bordersum);
	
	free(onearray);
	fclose(mat);
	return(0);
}


void getMatrix(int i,int j,double someArray[],FILE *file) { 
	int a,b;
	for (a = 0; a < i; a++) {
		for (b = 0; b < j; b++) {
			fscanf(file,"%lf",someArray+a*j+b); /*"j" is the set amount of columns you have, and "a" is the amount of rows. Thus j*a would be the 1-D equivalent of the first element in the "a"th row, and "b" offsets it by b columns.*/
		}
	} 
	puts("Function getMatrix executed successfully.");/*DEBUG*/
}


double Average(int ab, double someArray[]) { /*This function accepts the product of the row and column as well as the array itself. It returns the average of all elements.*/
	double avg = 0.0;
	int i;
	
	for (i = 0; i < ab; i++) {
		avg += someArray[i];
	}
	puts("Function Average executed successfully.");/*DEBUG*/
	return(avg/ab);
}


double Corner(int a, int b, double someArray[]) {
	puts("Function Corner executed successfully.");/*DEBUG*/
	return (someArray[0]+someArray[b-1]+someArray[b*(a-1)]+someArray[a*b-1]);
}


double Row(int rowb, int b, double someArray[]) {
	double sum = 0.0;
	int i;
	for (i = 0; i < b; i++) {
		sum += *(someArray+rowb+i); /*Basically the index is the given row to find * the number of columns in the matrix + the current column number iteration.*/
	}
	
	puts("Function Row executed successfully.");
	return sum;
}


double Column(int col, int b, int a, double someArray[]) {
	double sum = 0.0;
	int i;
	for (i = 0; i < a; i++) {
		sum += *(someArray+col+i*b); /*Here the index relies on the initial column offset and then iterates through the rows by adding a column multiple of i.*/
	}
	
	puts("Function Column executed successfully.");
	return sum;
}


double Diagonals(int a, int b, double someArray[], double *antidiag) {
	int i;
	double sum = 0.0,sum2 = 0.0;

	if (a != b) {
		return(INT_MAX);
	}

	for (i = 0; i < a; i++) { /*The upper limit should be the row or column number not the number of elements lol*/
		sum += someArray[i*(a+1)];  /*Calculates the sum of the diagonal.*/
		sum2 += someArray[a-1+i*(a-1)]; /*Calculates the sum of the antidiagonal.*/
	}
	
	*antidiag = sum2;/*Use pointer redirection to store antidiagonal sum.*/
	puts("Function Diagonals executed successfully."); /*DEBUG*/
	return sum;/*Return the diagonal sum here*/
}

double Borders(int a, int b, double someArray[]) {
	int i;
	double sum = 0.0;
	
	for (i = 0; i < a*b; i++) {
		if (i < b || i > (a-1)*b-1) { /*Condition tests for 1st and last row so that only those rows will be added normally.*/
			sum += someArray[i];			
		}
		else if (i % b == 0 || i % b == (b-1)) { /*Condition tests for 1st and last element in other rows*/
			sum += someArray[i];
		}
	}
	puts("Function Borders executed successfully.");/*DEBUG*/
	return sum;
}