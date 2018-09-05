#include <stdio.h>

int main() {
	char string[100];
	puts("Enter your sentence here");
	fgets(string, 100, stdin);
	int i=0;
	
	while (string[i] != '\0') {
		if (string[i] != ' ') {
			printf("%c", string[i]);
		}
		i++;
	}

	return 0;
}