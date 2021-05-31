#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <lib-keyboard-ninja/text.h>

void read_text (char text[512], char identifier[], char filename[]){
	FILE *base;
	long long unsigned int i;
	char string[512+16];
	char path[256] = "../texts/";
	strcat(path,filename);
	base = fopen(path,"r");
	
	while(fgets(string,528,base)){
		if(!strncmp(identifier,string,strlen(identifier))){
			for(i = strlen(identifier); i < strlen(string); i++){
				text[i - strlen(identifier)] = string[i];
			}
		}
	}
	
	fclose (base);
}
