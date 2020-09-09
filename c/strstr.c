#include<stdio.h>
#include<string.h>

void main()
{
    char *znalezione = "siku";
    char *napis = "Co sie tutaj wyprawia";
    char *slowo = "siusiak";
    if((strstr(napis,slowo)) != NULL) ;
    {
        printf("%s\n",strstr(napis,slowo));
        printf("%s\n",znalezione);
    }
}
