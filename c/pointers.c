#include<stdio.h>

void pointer_mixing(int *liczba, char *str, int *array){
    *liczba = 24;
    char *krystyna = "psia kosc kto to tu napisal";
    str = krystyna;
    array[2] = 11;
}


int main(int argc, char **argv){

int a = 50;
char *napis = "tu nie ma zadnego napisu";
napis = "kaszanka jest dzisiaj na obiad";
int tabliczka[] = {2,4,6,8,0};
pointer_mixing(&a, napis, tabliczka);

printf("new value of a is %d \n", a);
puts(napis);

for(int i =0 ; i <5 ; i++)
    printf("tablica[%d] = %d\n", i, tabliczka[i]); 

return 0;
}
