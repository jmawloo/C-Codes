/*Extra
PGM 1: Cost analysis is an important part of engineering. When you are in practice, you may be asked to write programs to determine the minimum cost for a number of different potential circumstances. Your programs can be used as decision making tools for a project. 

Consider the building of an airport with the runway being built on landfill. The contractor has two dump trucks, one with a capacity of 8 tons and the other with a capacity of 12 tons. The contractor uses the trucks to haul fill from a remote site to the airport location. The operating cost per trip for the 8 and 12 ton trucks is $14.57 and $16.26, respectively. One truck cannot make more than 60 percent of the total trips. 

Write a program that develops the minimum cost for a given number of tons. Prompt the user to enter the total number of tons. Display the number of trips required for each truck and the total cost. Use a modular design for this program.

PGM 2: The strength of an earthquake can be measured by its magnitude. In 1935, Charles F. Richter developed a scale, commonly known as the Richter scale, for determining an earthquake's magnitude. The amount of energy released in an earthquake, the length of an earthquake's fault rupture, and the number of worldwide earthquakes have all been correlated with magnitude. The following approximate equations relating these have been developed:

log10 E = 11.8 + 1.5M

log10 L = 1.02M - 5.77

log10 N = 7.7 - 0.9M

where:

M = Richter magnitude (0<M<8.2)

E = Energy released in ergs

L = Length of the fault rupture in kilometers

N = Number of world-wide earthquakes in a 100 year period 

Variation from the equations can be 20 percent. Write a program that accepts values of E and L and computes the possible ranges of magnitude for this earthquake. Tell the user if the input data is totally incompatible. Determine the most likely numbers of earthquakes of these magnitudes.*/

#pragma once
#pragma message("Cost analysis and magnitude of earthquakes. Version 2.0")

#include <stdio.h>
#include <math.h>

double leastCost (int tons, int * c, int * d) {
	int a = 0, b = 0, trips;
	double cost = 2147483648.0,temp = 0.0;
	
	if (tons % 8 != 0) {
		a = tons / 8 + 1; //Checks how many trips truck a can make on its own.
	}
	else {
		a = tons / 8;
	}

	trips = a + b;
		
	while (b+1 <= ((float) (trips)) * 0.6) { //While statement with condition that neither truck can make more than 60% of trips. The +1 allows for the cost calculations to be performed after the trip calculations. b+1 <= ((float) (trips)) * 0.6
		a--;
		b = (tons - 8*a)/12; //Calculating trips for truck b (Control for B).
		if ((tons - 8*a) % 12 != 0) { // If there are any remainder trips, 
			b++; //Add it to truck b.
		}
		trips = a + b;
		
		/*DEBUG
		if (a > ((float) (trips))*0.6) {
			puts("a was greater than 60% of the total trips at this iteration"); //DEBUG
			continue;
		}
		*/
				
		/*Perform cost calculations here*/
		temp = 14.57*a + 16.26*b;
		if (temp < cost) {
			cost = temp;
			*c = a; *d = b;
		}	
		
		//DEBUG: printf("a = %d | b = %d | Total trips = %d | A is %.4f percent of trips | Max weight =  %d | cost = %lf\n",a,b,trips,(float) a / trips * 100, 8 * a + 12 * b, cost); //DEBUG. Tons should never be less than 100!
		
	}
	
	if (*c < 3 && *d < 3) {
		cost = 14.57*a + 16.26*a; //If there's less than 2 trips to be made, 2 trips must be made.
		*c = a; *d = a;
	}
	return cost;
}

int main() {
	PROGRAM #1
	int tons, c = 0, d = 0;
	double cost;
	do { //User validation input loop.
		puts("Enter the number of tons you want transported(anything above 0!)");
		scanf("%d", &tons);
	} while (tons <= 0);
	cost = leastCost(tons, &c, &d);
	printf("The optimal pairing is %d trips for Truck A, and %d trips for Truck B, at a cost of $%.2lf.\n",c,d,cost);
	
	
	/*PROGRAM #2*/
	double e,l,n,m1,m2,m3,avg,max,min;
	do {
		puts("Enter your e,l,n in that order.\nE = Energy released in ergs.\nL = Length of the fault rupture in kilometers.\nN = Number of world-wide earthquakes in a 100 year period.\n(Ensure values are bigger than 0!)"); //User input.
		scanf("%lf%lf%lf",&e,&l,&n);
	} while ((e <= 0 || l <= 0) || n <= 0);
	
	m1 = (log10(e)-11.8)/1.5;//Calculations.
	m2 = (log10(l))/1.02;
	m3 = (7.7-log10(n))/0.9;
	
	avg = (m1 + m2 + m3)/3;
	
	/*Determine the maximum and the minimum first, then determine if they fall within the range. (Also add in way to find richter scale magnitude.)*/
	if (m1 <= m2 && m1 <= m3) {
		min = m1;
		if (m2 <= m3) {
			max = m3;
		}
		else {
			max = m2;
		}
	}
	else if (m2 <= m1 && m2 <= m3) {
		min = m2;
		if (m1 <= m3) {
			max = m3;
		}
		else {
			max = m1;
		}
	}
	else {
		min = m3;
		if (m1 <= m2) {
			max = m2;
		}
		else {
			max = m1;
		}
	}
	
	printf("The values are %.4lf, %.4lf, %.4lf, and the average is %.4lf.\n",m1,m2,m3,avg);
	
	if (max > 1.2*avg || min < 0.8*avg) {
		puts("The values you've entered are incompatible. Please run the program again.");
		return 0;
	}
	else {
		printf("The range of the Richter Scale magnitude is between %.4lf to %.4lf\n",min,max);
	}
	return 0;
}