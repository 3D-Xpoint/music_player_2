#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "textfilewriter.h"
#define MAX_TITLE_SIZE 50

void create_music_titles(FILE* stream){
	char* music_titles;
	char buffer[1000];

	while (!feof(stream)) {
		music_titles = fgets(buffer, sizeof(buffer), stream);
		printf("%s", music_titles);
	}
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
