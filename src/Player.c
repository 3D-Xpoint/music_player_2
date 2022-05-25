#include <stdio.h>
#include <string.h>
/*
#include "linkedlist.h"
#include "textfilewriter.h"
*/

void read_command();

int main() {
    int number_of_song = 0;
    int number_of_command = 0;

    char* list[100] = {};

    scanf("%d", number_of_song);
    for(int i=0; i<number_of_song; i++) {
	char music_name[100];
	scanf("%s", music_name);
	list[i] = music_name;
    }

    scanf("%d", number_of_command);
    for(int i=0; i<number_of_command; i++) {
        read_command();
    }
    return 0;
}

void read_command() {
    char command[100];
    scanf("%s", command);
    if(!strcmp(command, "add"))        { add(); } //string argument x1
    else if(!strcmp(command, "del"))   { del(); } //string argument x1
    else if(!strcmp(command, "list"))  { list(); }
    else if(!strcmp(command, "next"))  { next(); }
    else if(!strcmp(command, "prev"))  { prev(); }
    else if(!strcmp(command, "move"))  { move(); } //int argument x1
    else if(!strcmp(command, "play"))  { play(); }
    else if(!strcmp(command, "clear")) { clear(); }
    else if(!strcmp(command, "quit"))  { quit(); }
    else if(!strcmp(command, "load"))  { load(); } //string argument x1
    else if(!strcmp(command, "save"))  { save(); } //string argument x1
    else { ; }
}

