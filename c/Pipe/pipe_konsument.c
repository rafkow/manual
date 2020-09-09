#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int przetworzone_dane;
    char bufor[BUFSIZ +1];
    int deskryptor_pliku;
    memset(bufor, '\0', sizeof(bufor));
    sscanf(argv[1], "%d", &deskryptor_pliku);
    przetworzone_dane = read(deskryptor_pliku, bufor, BUFSIZ);
    printf("%d - odczytano %d bajty: %s\n", getpid(), przetworzone_dane, bufor);
    exit(EXIT_SUCCESS);
}
