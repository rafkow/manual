#include<stdlib.h>
#include<stdio.h>

int main(){
    printf("Uruchamianie ps\n");
    system("ps -xa &");
    printf("Gotowe\n");
    exit(0);
}
