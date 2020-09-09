#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE* write_pp;
    char bufor[BUFSIZ +1];
    int num_of_char;
    sprintf(bufor, "Pewnego razu bylo sobie jedno \n");
    write_pp = popen("od -c", "w");
    if(write_pp !=NULL){
        fwrite(bufor, sizeof(char), strlen(bufor), write_pp);
        pclose(write_pp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
