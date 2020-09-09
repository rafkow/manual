#define _XOPEN_SOURCE

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "cd_dane.h"

#define DLUG_TMCZ_STRING 125

typedef enum {
    om_niedpouszcz,
    om_dodaj_kat,
    om_dodaj_sciezki,
    om_szukaj_kat,
    om_wypisz_sciezki_kat,
    om_usin_sciezki,
    om_policz_wpisy,
    om_wyjscie
} opcje_menu;

static int tryb_polecen(int argc, char *argv[]);
static void powitanie(void);
static opcje_menu pokaz_menu(const wpis_cdk *aktualnya_cdk);
static int czyt_potwierdzenie(const char *pytanie);
static int wpisz_nowy_kat(wpis_cdk *wpis_do_aktualizacji);
static void wpisz_nowe_sciezki(const wpis_cdk *wpis_do_dodania);
static void usun_wpis_kat(const wpis_cdk *wpis_do_usuniecia);
static void usun_wpis_sciezek(const wpis_cdk *wpis_do_usuniecia);
static wpisc_cdk szukaj_kat(void);
static void wypisz_sciezki(const wpis_cdk *stosowany_wpis);
static void policz_wpisy(void);
static void pokaz_cdk(const wpis_cdk *wpis_do_pokazania);
static void pokaz_cds(const wpis_cdk *wpis_do_pokazania);
static void obetnij_return(char *string_do_obciecia);

void main(int argc, char *argv[]){

}
