#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char *menu[] = {"d - dodaj nowa plyte","k - kasuj","q - wyjscie",NULL};
int czyt_wybor(char *prolog, char *wybory[], FILE *wejscie, FILE *wyjscie);

int main() {
	int wybor = 0;
	FILE *input, *output;

	//sprawdzenie czy standardowe wyjscie jest polaczone z terminalem
	if(!isatty(fileno(stdout))) {
		fprintf(stderr,"Nie jestes na terminalu\n");
	}

	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");
		if(!input || !output) {
			fprintf(stderr, "Nie moge otwirzyc /dev/tty \n");
			exit(1);
		}

	do {
	wybor = czyt_wybor("wybierz dzialanie", menu, input ,output);
	printf("Wybrales: %c\n",wybor);
	} while(wybor != 'q');
	exit(0);
}

int czyt_wybor(char *prolog, char *wybory[], FILE *wejscie, FILE *wyjscie){
	int wybierz = 0;
	int wybrane;
	char **opcja;
	
	do {
	fprintf(wyjscie,"Wybor :%s\n",prolog);
	opcja = wybory;
		while(*opcja) {
		fprintf(wyjscie,"%s\n",*opcja);
		opcja++;
		}
	do {
		wybrane = fgetc(wejscie);
	} while (wybrane == '\n');
	wybrane = getchar();
	opcja = wybory;
		while(*opcja) {
			if(wybrane == *opcja[0]){
			wybierz = 1;
			break; 
			}
		opcja++;
		}
	if(!wybierz)
		fprintf(wyjscie,"Niewlascywy wybor wybierz ponownie\n");
	} while(!wybierz);
	return wybrane;
}	
