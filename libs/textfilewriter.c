//
// Created by edward on 22. 5. 13..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "textfilewriter.h"

void create_music_titles(FILE* stream){
	
}

void read_file(char* file_name){
        FILE *f = fopen(file_name, "r");
        create_music_titles(f);
	fclose(f);
}
void write_file(char* file_name){
        FILE *stream = fopen(file_name, "w");
	print_file(f);
        fclose(f);
}
