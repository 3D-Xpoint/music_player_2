#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "textfilewriter.h"
#define MAX_TITLE_SIZE 50

void create_music_titles(FILE* stream){
	char *name;
	clear();
	stream = fopen((const char *) stream, "r");
	Node* now = first();
	
	while(strcmp(name,"\0") != 0){
        	name = (char *)malloc(sizeof(char) * MAX_NAME_SIZE);
        	fgets(name,MAX_NAME_SIZE,stream);
        	append_left(1,(char *)name);
        	now = now -> next;
	}
	free(name);
	fclose(stream);
}

void read_file(char* file_name){
        FILE *f = fopen(file_name, "r");
        create_music_titles(f);
	fclose(f);
}

void write_file(char* file_name){
        FILE *f = fopen(file_name, "w");
	print_file(f);
        fclose(f);
}
