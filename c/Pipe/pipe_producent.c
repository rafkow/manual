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
            sprintf(bufor, "%d", pipe_descryptors[0]);
            (void)execl("pipe_konsument", "pipe_konsument", bufor, (char*)0);
            exit(EXIT_FAILURE);
        }
        else {
            convert_data = write(pipe_descryptors[1], some_data, strlen(some_data));
            printf("%d - zapisano %d bajty\n", getpid(), convert_data);
        }
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
