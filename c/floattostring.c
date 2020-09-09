#include<stdio.h>
#include<stdlib.h>

void ftos(float value, char * wynik)
{
  int liczba = (int)(value*1000);
  int dlugosc = 100;
  int i=3;
  for(;;i++){
    dlugosc *= 10;
    if (liczba > dlugosc)
      continue;
    wynik = (char*)malloc(sizeof(char)*i+1);
    printf("valuer %d", i);
    break;
  }
  for(dlugosc=0,i<)
}

int main()
{
  char * wynik;
  ftos(12345.678,wynik);
  return 0;
}
