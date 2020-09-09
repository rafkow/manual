#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE* read_pp;
    char bufor[BUFSIZ +1];
    int num_of_char;
    memset(bufor,'\0', sizeof(bufor));    
    read_pp = popen("uname -a", "r");
    if(read_pp !=NULL){
        num_of_char = fread(bufor, sizeof(char), BUFSIZ, read_pp);
        if(num_of_char >0){
            printf("Rezultat: \n%s\n",bufor);
        }
        pclose(read_pp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
