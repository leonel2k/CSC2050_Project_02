#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

		char *buffer = NULL;
		size_t bufsize = 0;
		char *temp = NULL;

		if (argc > 2) {
			return -1;
		}

		if (argc == 2) {
		FILE *fp = fopen(argv[1], "r");
		if (fp == NULL) {
			printf("Could not open file for reading");
			return 0;
		}
		while ((getline(&buffer, &bufsize, fp) != -1)) {
			if (temp == NULL || strcmp(buffer, temp) != 0) {
				printf("%s", buffer);
				free(temp);
				temp = buffer;
					
			} else {
				free(buffer);
			}
			buffer = NULL;
			bufsize = 0;
		}
		free(buffer);
		free(temp);
		fclose(fp);
		return 0;
	} else {
		while ((getline(&buffer, &bufsize, stdin)) != -1) {
			if (temp == NULL || strcmp(buffer, temp) != 0) {
                                printf("%s", buffer);
				free(temp);
				temp = buffer;
                        } else {
				free(buffer);
			}
                        buffer = NULL;
			bufsize = 0;
                }
		free(buffer);
		free(temp);
		return 0;
	}
}
			

		



