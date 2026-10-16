#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
	int newLine = 0;
	int words = 0;
	int numChar = 0;
	int ch; 					//for fgetc
	//no arguments provide use the standard output
	if (argc <= 1) {
		while ((ch = fgetc(stdin)) != EOF) {
			if (ch == ' ') { 		//words are broken up by a space
                        words++;
               		 } else if (ch == '\n') { 	//lines are broken up by \n
                        	words++; 		//takes care of the word before \n
                        	newLine++;
                	}
                	numChar++;			//update number of characters scanned
        		}
	
        	printf( "      %d      %d      %d\n", newLine, words, numChar);
		return 0;
	} 
	
	FILE *fp = fopen(argv[1],"r");			//use argument string to open file
	if (fp == NULL) {				//if file could not be open end program
		printf("Could not open file for reading\n");
		return 0;
	}
	while((ch = fgetc(fp)) != EOF) {		//get every character in text file
		if (ch == ' ') {
			words++;
		} else if (ch == '\n') {
			words++;
			newLine++;
		}
		numChar++;
	}
	fclose(fp);					//must close file after finished using it
	printf( " %d  %d %d %s\n", newLine, words, numChar, argv[1]);
	return 0;
       	
}
