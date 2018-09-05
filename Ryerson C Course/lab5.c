#include <stdio.h>
#include <math.h>

int main(void) {
	int bnum =0,numsamp,numorgs,num,i,d = 0;
	double avg;
	FILE *f1;

	f1 = fopen("SampleData.txt","r");
	
	while (fscanf(f1, "%d %d", &bnum, &numsamp) != EOF) {
		avg = 0;
		
		for (i = 0; i < numsamp; i++) {
			fscanf(f1, "%d", &numorgs);

			avg += numorgs;
		}
		avg /= numsamp;
		
		if (avg < 3500) {
			printf("Beach #%d is open for business!\n",bnum);
		}
		else {
			printf("Sorry, beach #%d is closed until further notice.\n",bnum);
		}
		
	}
	
	fclose(f1);
	
	puts("Enter your number to be displayed vertically:");
	scanf("%d",&num);
	i = (int) pow(10,7);
	while (num % i == num) {
		if (num == 0) {
			puts("0");
			return(0);
		}
		i/=10;
	}
	do {
		d = num - num % i;
		printf("%d\n",d/i );
		num -= d;
		if (i == 1) {
			break;
		}
		i/=10;
	} while (1);
	return(0);
}
