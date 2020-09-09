#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char *napis;
	srand(time(NULL));
	int i;
	napis = malloc(sizeof(char) * 10);

	for(i=0;i<10;i++)
	{
		int r = rand() % (int)('Z'-'A');
		napis[i]= r+'A';
	}
	int plik = open(napis, O_CREAT);
	open(napis, O_CREAT);
	return 0;
}
