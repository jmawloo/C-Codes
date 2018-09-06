#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*Morse code representations of numbers, letters and symbols retrieved from https://en.wikipedia.org/wiki/Morse_code#Timing*/

int countChars(char *sentence) {//includes spaces and punctuation.
	int count = 0;
	while (sentence[count] != '\n') ++count; //EOL is actually \n for stdin user input.
	return count;
}

void morseEncode(char *sentence, char **encoded) {
    char morseletters[26][7] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; //[A-Z] || [a-z]
	char morsenumbers[10][7] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."}; //[0-9]
	char morsespecial[16][9] = {"|", "-.-.--", ".-..-.", "#", "...-..-", "%", ".-...", ".----.", "-.--.", "-.--.-", "*", ".-.-.", "--..--", "-....-", ".-.-.-", "-..-."}; //These only contain special characters in [' '-'/']
	//TODO: add support for other custom characters.
    int i = 0;
	while (*(sentence + i) != '\n') { //Another way of writing sentence[i]
		if (sentence[i] >= 'A' && sentence[i] <= 'Z') { //Lowercase
			strcpy(encoded[i], morseletters[sentence[i]-65]);
		}	
		else if (sentence[i] >= 'a' && sentence[i] <= 'z') { //lowercase
			strcpy(encoded[i], morseletters[sentence[i]-97]);
		}
		else if (sentence[i] >= '0' && sentence[i] <= '9') {
			strcpy(encoded[i], morsenumbers[sentence[i]-48]);
		}
		else if (sentence[i] >= ' ' && sentence[i] <= '/') {//for punctuation + spaces
			strcpy(encoded[i], morsespecial[sentence[i]-32]);
		}
		i++;
	}
}

void morseBeep(char **encoded, int count) {
	int i, j;
	for (i = 0; i < count; i++) {
		j = 0;
		printf("%s ", encoded[i]); //DEBUG
		while (encoded[i][j] != '\0') {
			if (encoded[i][j] == '.') {
				Beep(777, 150);
				Sleep(100);
			}
			else if (encoded[i][j] == '-') {
				Beep(777, 450);
				Sleep(100);
			}
			else {
				Sleep(600);
			}
			j++;
		}
		Sleep(300);
	}
}

int main(void) {
	//TODO: main(int String, char *args[]) 
	char sentence[500]; //Assume longest sentence ever is 500 characters long (__future__: change this?)
	puts("Enter your sentence to be translated into morse code:");
	fgets(sentence, 500, stdin);
	
	int count = countChars(sentence);
	
	char **encoded = (char**) calloc(count, sizeof(char*));
	int i;
	for (i = 0; i < count; i++) {
		encoded[i] = (char*) calloc(9, sizeof(char)); 
	}

	morseEncode(sentence, encoded);
	morseBeep(encoded, count);
	
	//Free dynamically allocated array
	for (i = 0; i < count; i++) {
		free(encoded[i]);
	}
	free(encoded);
	
	return 0;
	
}