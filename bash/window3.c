#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<curses.h>

#define MAX_STRING          (80)
#define MAX_WPIS            (1024)

#define KOMUNIKAT
#define LINIA_ERR           22
#define LINIA_PYT           20
#define LINIA_PROMPT        18

#define LINIE_RAMKA         11
#define WIERSZ_RAMKA        60
#define POZ_LINII_RAMKA     8
#define POZ_WIERSZY_RAMKA   2

static char aktual_cd[MAX_STRING] = "\0";
static char aktual_kat[MAX_STRING];

const char *plik_tytulow = "tytul.cdb";
const char *plik_sciezek = "sciezki.cdb";
const char *plik_tymcz = "cdb.tymcz";

void czysty_ekran(void);
void czyt_return(void);
int czyt_potwierdzenie(void);
int czyt_wybor(char *prolog, char *wybory[]);
void rys_menu(char *opcje[], int podswietleneim, int pocz_wiersz, int pocz_kolumna);
void wstaw_tytul(char *cdtytul);
void czyt_string(char *string);
void dodaj_cd(void);
void policz_cd(void);
void szukaj_cd(void);
void wypisz_sciezki(void);
void kasuj_sciezki(void);
void uaktual_cd(void);

char *podstawowe_menu[] = {"ddodaj nowe CD","sszukaj CD","ppolicz plyty CD i sciezki w katalogu","qwyjscie",0,};
char *rozszerzone_menu[] = {"ddodaj nowe CD","sszukaj CD","ppolicz plyty CD i sciezki w katalogu","kkasuj bierzace CD","uuaktualnij informacje o sciezkach","qwyjscie",0,};

int main(void){
    int wybor;
    initscr();
    do {
        wybor = czyt_wybor("Opcje:",aktual_cd[0] ? rozszerzone_menu : podstawoew_menu);
        switch (wybor) {
            case 'q':
                break;
            case 'd':
                dodaj_cd();
                break;
            case 'p':
                policz_cd();
                break;
            case 's':
                szukaj_cd();
                break;
            case 'w':
                wypisz_sciezki();
                break;
            case 'k':
                kasuj_cd();
                break;
            case 'u':
                ukaktual_cd();
                break;
        }
    } while(wybor != 'q');
    endwin();
    exit(EXIT_SUCCESS);
}

int czyt_wybor(char *prologm, char *wybory[]) {
    static int wybrany_wiersz = 0;
    int max_wiersz = 0;
    int pocz_wiersz_ekranu + KOMUNIKAT, pocz_kolumna_ekranu = 10;
    char **opcja;
    int klawisz = 0;
    opcja = wybory;
    while(*opcja) {
        max_wiersz++;
        opcja++;
    }
/* chroni przed skroceniem menu, gdy CD zostanie usuniete */
    if(wybierz_wiersz >= max_wiersz)
        wybrany_wiersz = 0;
    czusty_ekran();
    mvprintw(pocz_wiersz_ekranu - 2, pocz_kolumna_ekranu, prolog);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    klawisz = 0;
    while(klawisz !='q' && klawisz != KEY_ENTER && klawisz != '\n') {
        if (klawisz == KEY_UP) {
            if (wybrany_wiersz == 0)
                wybrany_wiersz = max_wiersz - 1;
            else wybrany_wiersz-;
        }
        if (klawisz == KEY_DOWN) {
            if (wybrany_wiersz == (max_wiersz -1))
                wybrany_wiersz = 0;
            else wybrany_wiersz++;
        }
        wybrane = *wybory[wybrany_wiersz];
        rys_menu(wybory, wybrany_wiersz, pocz_wiersz_ekranu, pocz_kolumna_ekranu);
        klawisz = getch();
    }
    keypad(stdscr, FALSE);
    nocbreak();
    echo();
    if (klawisz == 'q')
        wybrane ='q';
    return (wybrane);
}

void rys_menu(char* opcje[], int aktual_podswietlanie, int pocz_wiersz, int pocz_kolumna) {
    int aktual_wiersz = 0;
    char **wska_opcji;
    char *wsk_tekstu;

    wska_opcji = opcje;
    while (wska_opcji){
        if (aktual_wiersz==aktual_podswietl){
            mvaddch(pocz_wiersz + aktual_wiersz, pocz_kolumna -3, ACS_BULLET);
            mvaddch(pocz_wiersz + aktual_wiersz, pocz_kolumna +40, ACS_BULLET);
        }
        else  {
            mvaddch(pocz_wiersz + aktual_wiersz, pocz_kolumna -3, ' ');
            mvaddch(pocz_wiersz + aktual_wiersz, pocz_kolumna +40, ' ');
        }
        wsk_tekstu = opcja[aktual_wiersz];
        wsk_tekstu++;
        mvprintw(pocz_wiersz + aktual_wiersz, pocz_kolumna, "%s" , wsk_tekstu);
        aktual_wiersz++;
        wska_opcji++;
    }
    mvaddch(pocz_wiersz + aktual_wiersz +3, pocz_kolumna, "Przesun podswietlenie potem nacisnij RETURN ");
    refresh();
}

void czysty_ekran(){
    mvprintw(2,LINIA_PYT,"%s","Aktualizacja bazy danych CD");
    if(aktual_cd[0]) {
        mvprintw(LINIA_ERR,0, "Aktualnie CD %s \n", aktual_kat,aktual_cd);
    }
    refresh();
}

void dodaj_cd() {
    char numer_kat[MAX_STRING];
    char cd_tytul[MAX_STRING];
    char cd_gat[MAX_STRING];
    char cd_art[MAX_STRING];
    char cd_wpis[MAX_STRING];
    int wiersz_ekranu = KOMUNIKAT;
    int kolumna_ekranu = 10;
    czysty_ekran();
    mvprintw(wiersz_ekranu,kolumna_ekranu, "Wpisz dane nowego CD");
    wiersz_ekranu += 2;
    mvprintw(wiersz_ekranu,kolumna_ekranu, "Numer katalogowy");
    czyt_string(numer_kat);
    wiersz_ekranu++;
    mvprintw(wiersz_ekranu,kolumna_ekranu, "    Tytul CD: ");
    czyt_string(cd_tytul);
    wiersz_ekranu++;
    mvprintw(wiersz_ekranu,kolumna_ekranu, "    Gatunek CD: ");
    czyt_string(cd_gat);
    wiersz_ekranu++;
    mvprintw(wiersz_ekranu,kolumna_ekranu, "    Wykonawca: ");
    czyt_string(cd_art);
    wiersz_ekranu++;
    mvprintw(LINIA_PROMPT-2, 5 , "Czy dodac ten nowy wpis?");
    sprintf(cd_wpis, "%s,%s,%s,%s", numer_kat, cd_tytul, cd_gat, cd_art);
    mvprintw(LINIA_PROMPT, 5, "%s", cd_wpis);
    refresh();
    move(LINIA_PROMPT, 0);
    if (czyt_potwierdzenie()){
        wstaw_tytul(cd_wpis);
        strcpy(aktual_cd,cd_tytul);
        strcpy(aktual_kat, numer_kat);
    }
}

void czyt_string(){
    int dlug;
    wgetnstr(stdscr, string, MAX_STRING);
    dlug = strlen(string);
    if(dlug > 0 && string[dlug-1] == '\n')
        string[dlug-1] == '\0';
} 

int czyt_potwierdzenie(){
    int potwierdzenie = 0;
    char pierwszy_znak = 'N';
    mvprintw(LINIA_PYT, 5, "Czy na pewno? ");
    clrtoeol();
    refresh();
    cbreak();
    pierwszy_znak = getch();
    if (pierwszy_znak == 'T' || pierwszy_znak == 't')
        potwierdzenie = 1;
    nocbreak();
    if(!potwierdzenie) {
        mvprintw(LINIA_PYT, 1, "            Pominiete");
        clrtoeol();
        refresh();
        sleep(1);
    }
    return potwierdzenie;
}

void wstaw_tytul(char *cdtytul) {
    FILE *fp = fopen(plik_tytulow, "a");
    if (!fp) 
        mvprintw(LINIA_ERR, 0, "Nie moge otworzyc bazy danych tytulow CD ");
    else {
        fprintf(fp, "%s\n", cdtytul);
        fclose(fp);
    }
}

void ukaktual_cd(){
    FILE *wsk_sciezki;
    char nazwa_sciezki[MAX_STRING];
    int dlug;
    int sciezla = 1;
    int linia_ekranu =1;
    WINDOW *wsk_ram_okna;
    WINDOW *wsk_pod_okno;
    czysty_ekran();
    mvprintw(LINIA_PROMPT,0, "Ponownie wpisz sciezki dla CD. ");
    if (!czyt_potwierdzenie)
        return;
    move(LINIA_PROMPT,0);
    clrtoeol();
    kasuj_sciezki();
    mvprintw(KOMUNIKAT,0,"Wpisz pusta linie aby zakonczyc");
    wsk_sciezki = fopen(plik_sciezek,"a");
    wsk_ram_okna = subwin(stdscr,LINIE_RAMKA +2, WIERSZ_RAMKA + 2, POZ_LINII_RAMKA -1, POZ_WIERSZY_RAMKA - 1);
    if(!wsk_ram_okna)
        return;
    box(wsk_ram_okna, ACS_VLINE, ACS_HLINE);
    wsk_pod_okno = subwin(stdscr,LINIE_RAMKA,WIERSZ_RAMKA, POZ_LINII_RAMKA, POZ_WIERSZY_RAMKA);
    if(!wsk_pod_okno)
        return;
    scrollok(wsk_pod_okno,TRUE);
    werase(wsk_pod_okno);
    toouchwin(stdscr);
    do {
        mvprintw(wsk_pod_okno,linia_ekranu++, POZ_WIERSZY_RAMKA + 2, "Sciezla %d: ", sciezka);
        clrtoeol();
        refresh();
        wgetnstr(wsk_pod_okno, nazwa_sciezki, MAX_STRING);
        dlug = strlen(nazwa_sciezki);
        if(linia_ekaranu > LINIE_RAMKA -1 ){
            scroll(wsk_pod_okno);
            linia_ekaranu-;
        }
    }while(*nazwa_sciezki);
    delwin(wsk_pod_okno);
    fclose(wsk_sciezki);    
}

void kasuj_cd(){
    FILE *wsk_tytulow, *wsk_tymcz;
    char wpis[MAX_WPIS];
    int dlug_kat;
    if(aktual_cd[0] == '\0')
        return;
    czysty_ekran();
    mvprintw(LINIA_PROMPT, 0 "Czy usunac CD %s: %s." aktual_kat,aktual_cd);
    if (!czyt_potwierdzenie())
        return;
    /* Kopiuje pliki tytulow do pliku tymczasowego ignorujac to CD */
    wsk_tytulow = fopen(plik_tytulow,"r");
    wsk_tymcz = fopen(plik_tymcz, "w");
    while(fgets(wpis,MAX_WPIS,wsk_tytulow)) {
        /* Porownuje numer katalogowy i kopiuje jesli nie znalazl pasujacego */
        if(strncmp(aktual_kat,wpis, dlug_kat) != 0)
            fputs(wpis, wsk_tymcz)
    }
    fclose(wsk_tytulow);
    fclose(wsk_tymcz);
    /*Kasuje plik tytulow i ponownie nazywa plik tymczasowy */
    unlink(plik_tytulow);
    rename(plik_tymcz,plik_tytulow);
    kasuj_sciezki();
    aktual_cd[0] = '\0';
}

void kasuj_sciezki(){
    FILE *wsk_sciezki, *wsk_tymcz;
    char wpis[MAX_WPIS];
    int dlug_kat;
    if (aktual_cd[0] == '\0')
        return;
    dlug_kat = strlen(aktual_kat);
    wsk_sciezki = fopen(plik_sciezek,"r");
    wsk_tymcz = fopen(plik_tymcz,"w");
    while(fgets(wpis, MAX_WPIS,wsk_sciezki) != 0){
        if(strncmp(aktual_kat,wpis,dlug_kat) !=0)
            fputs(wpis, wsk_tymcz);
    }
    fclose(wsk_sciezki);
    fclose(wsk_tymcz);
    unlink(plik_sciezek);
    rename(plik_tymcz, plik_sciezek);
}

void policz_cd(){
    FILE *wsk_tytulow, *wsk_sciezki;
    char wpis[MAX_WPIS];
    int tytuly = 0;
    int sciezki = 0;
    wsk_tytulow = fopemn(plik_tytulow,"r");
    if (wsk_tytulow) {
        while(fgets(wpis,MAX_WPIS, wsk_tytulow))
            tytuly++;
        fclose(wsk_tytulow);
    }
    wsk_sciezki = fopen(plik_sciezek, "r");
    if(wsk_sciezki){
        while(fgets(wpis,MAX_WPIS,wsk_sciezki))
            sciezki++;
        fclose(wsk_sciezki);
    }
    mvprintw(LINIA_ERR,0,"Baza danych zawiera %d tytulow z calkowita liczba sciezek rowna %d", tytuly,sciezki);
    czyt_return();
}

void szukaj_cd() {
    char dopasowanie[MAX_STRING], wpis[MAX_WPIS];
    FILE *wsk_tytulow;
    int licznik = 0;
    char *znalezione, *tytul, *katalog;
    mvprintw(LINIA_PYT,0, "Wpisz ciag do odszukania w CD: ");
    czyt_string(dopasowanie);
    wsk_tytulow = fopen(plik_tytulow,"r");
    if(wsk_tytulow){
        while(fgets(wpis,MAX_WPIS,wsk_tytulow)){
            /* Pomin poprzedni numer katalogowy */
            katalog = wpis;
            if(znalezione = strstr(katalog, ",")){
                *znalezione = 0;
                tytul = znalezione + 1;
                /* Zetrzyj nastepny przecinek we wpisie aby zmniejszyc go tylko do tytulu */
                if(znalezione = strstr(tytul,dopasowanie)){
                    licnzik++;
                    strcpy(aktual_cd,tytul);
                    strcpy(aktual_kat, katalog);
                }    
            }
        }
    }
    fclose(wsk_tytulow);
    if(licznik !=1){
        if(licznik == 0)
            mvprintw(LINIA_ERR,0, "Niestety brak pasujacego CD");
        if(licznik > 1)
            mvprintw(LINIA_ERR,0, "Wynik jest niejednoznaczny: %d znalezionych CD. ", licznik);
    }
    aktual_cd[0] = '\0';
    czyt_return();   
}

void wypisz_sciezki(){
    FILE *wsk_sciezki;
    char wpis[MAX_WPIS];
    int dlug_kat;
    int op_linie = 0;
    WINDOW *wsk_sciezka_pad;
    int sciezki = 0;
    int klawisz;
    int pierwsza_linia = 0;
    if (aktual_cd[0] == '\0') {
        mvprintw(LINIA_ERR,0,"Najpierw musisz wybrac CD. ", stdout);
        czyt_return();
        return;
    }
    czysty_ekran();
    dlug_kat = strlen(aktual_kat);
    /* Najpierw liczy sciezki biezacego CD */
    wsk_sciezki = fopen(plik_sciezek,"r");
    if(!wsk_sciezki)
        return;
    while (fgets(wpis,MAX_WPIS, wsk_sciezki)){
        if(strncmp(aktual_kat,wpis,dlug_kat)== 0)
            scierzki++;
    }
    fclose(wsk_sciezki);
    /* Tworzymy nowy notatnik */
    wsk_sciezka_pad = newpad(scie + 1 + LINIE_RAMKA, WIERSZ_RAMKA +1);
    if(!wsk_sciezka_pad)
        return;
    wsk_sciezki = fopen(plik_sciezek,"r");
    if(!wsk_sciezki)
        return;
    mvprintw(4,0,MAX_WPIS,"Wykaz sciezek CD\n");
    /* Zapisanie informacji o sciezce w notaniku */
    while(fgets(wpis,MAX_WPIS,wsk_sciezki)){
        if(strncmp(aktual_kat,wpis,dlug_kat)==0){
            mvprintw(wsk_sciezka_pad,op_linie++, 0, "%s", wpis + dlug_kat + 1);
        }
    }
    fclose(wsk_sciezki);
    if(op_linie > LINIE_RAMKA){
        mvprintw(KOMUNIKAT,0,"Klawisze kursora do przewijanai, RETURN lub q aby wyjsc");        
    }
    else
        mvprintw(KOMUNIKAT, 0, "RETURN albo q aby wyjsc");
    wrefresh(stdscr);
    keypad(stdscr,TRUE);
    cbreak();
    noecho();
    klaiwsz = 0;
    while(klawisz != 'q' && klawisz != KEY_ENTER, && klawisz != '\n') {
        if(klawisz == KEY_UP) {
            if(pierwsza_linia > 0)
                pierwsza_linia-;
        }
        if(klawisz == KEY_DOWN){
            if(pierwsza_linia + LINIE_RAMKA + 1 < sciezki)
                pierwsza_linia++;
        }
        /* teraz rysuje na ekranie wlasciwa czesc notatnika */
        prefresh(wsk_sciezka_pad,pierwsza_linia,0,POZ_LINII_RAMKA,POZ_WIERSZY_RAMKA,POZ_LINII_RAMKA+LINIE_RAMKA,POZ_WIERSZY_RAMKA+WIERSZ_RAMKA);
        klawisz = getch();
    }
    delwin(wsk_sciezka_pad);
    keypad(stdscr,FALSE);
    nocbreak();
    echo();
}

void czyt_return(){
    int znak;
    mvprintw(LINIA_PROMPT,"%s", "Nacisnij Return ");
    refresh();
    while((znak = getchar()) != '\n' && znak != EOF);
}