#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(){
    char bufor[128];
    int rezultat, odczytano;
    fd_set wejscia, testzdp;
    struct timeval limit_czasu;
    FD_ZERO(&wejscia);
    FD_SET(0, &wejscia);

    while(1){
    testzdp = wejscia;
    limit_czasu.tv_sec = 2;
    limit_czasu.tv_usec = 500000;
    rezultat = select(FD_SETSIZE, &testzdp, (fd_set *)0, (fd_set *)0, &limit_czasu);

    switch(rezultat){
    case 0: 
        printf("uplynol limit czasu \n");
        break;
    case -1: 
        perror("select");
        return 1;
    default: 
        if(FD_ISSET(0, &testzdp)){
            ioctl(0,FIONREAD,&odczytano);
            if(odczytano == 0) {
                printf("koniec danych z klawiatury \n");
                return 0;
            }
            odczytano = read(0,bufor,odczytano);
            bufor[odczytano] = 0;
            printf("odczytano %d znakow z klawiatury: %s", odczytano, bufor);
        }
        break;
    }
}
} 
