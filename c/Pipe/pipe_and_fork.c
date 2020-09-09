#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int convert_data;
    char bufor[BUFSIZ +1];
    int pipe_descryptors[2];
    int fork_rezultat;
    const char some_data[] = "No chyba sie udalo...";
    memset(bufor,'\0', sizeof(bufor));    
    
    if(pipe(pipe_descryptors)== 0){
        fork_rezultat = fork();

        if(fork_rezultat == -1){
            printf("Bledne wykonanie funkcji fork");
            exit(EXIT_FAILURE);
        }

        if(fork_rezultat == 0) { // jestes w procesie potomnym
            convert_data = read(pipe_descryptors[0], bufor, BUFSIZ);
            printf("\nOdczytano %d bajty: %s ", convert_data, bufor);
        }
        else {
            convert_data = write(pipe_descryptors[1], some_data, strlen(some_data));
            printf("\nZapisano %d bajty", convert_data);
        }
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
