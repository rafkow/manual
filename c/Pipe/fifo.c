#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
    int res;
    int tryb_otwarcia = 0;
    if (argc < 2) {
        fprintf(stderr, "Uzycie: %s < kombinacja O_RDONLY O_WRONLY O_NOBLOCK\n", *argv);
        exit(EXIT_FAILURE);
    }

    argv++;
    if (strncmp(*argv, "O_RDONLY", 8) == 0) tryb_otwarcia |=O_RDONLY;
    if (strncmp(*argv, "O_WRONLY", 8) == 0) tryb_otwarcia |=O_WRONLY;    
    if (strncmp(*argv, "O_NONBLOKC", 10) == 0) tryb_otwarcia |=O_NONBLOCK;    
    argv++;
    if(*argv){
        if (strncmp(*argv, "O_RDONLY", 8) == 0) tryb_otwarcia |=O_RDONLY;
        if (strncmp(*argv, "O_WRONLY", 8) == 0) tryb_otwarcia |=O_WRONLY;
        if (strncmp(*argv, "O_NONBLOCK", 10) == 0) tryb_otwarcia |=O_NONBLOCK;
    }

    if(access("fifka", F_OK) == -1) {
        res = mkfifo("fifka", 0777);
        if(res!=0) {
            fprintf(stderr, "Nie bylo utworzonego kolejki %s\n", "fifka");
            exit(EXIT_FAILURE);
        }
    }

    printf("Proces %d otworzyl FIFO\n", getpid());
    res = open("fifka", tryb_otwarcia);
    printf("PRoces %d rezultat %d\n", getpid(), res);
    sleep(5);
    if (res != -1) (void)close(res);
    printf("Proces %d zakonczyl prace", getpid());    

    exit(EXIT_SUCCESS);
}
