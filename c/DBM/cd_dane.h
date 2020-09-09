#define DLUG_KAT_KAT        30
#define DLUG_TYTUL_KAT      70
#define DLUG_GATUNEK_KAT    30
#define DLUG_WYKONAWCA_KAT  70

typedef struct{
    char katalog[DLUG_KAT_KAT + 1];
    char tytul[DLUG_TYTUL_KAT +1];
    char gatunek[DLUG_GATUNEK_KAT +1];
    char wykonawca[DLUG_WYKONAWCA KAT + 1];
} wpis_cdk;

/* Tablica sciezek jeden wpis dla kzaddej sciezki */
#define DLUG_SCIEZKI_KAT    DLUG_KAT_KAT
#define DLUG_TEKSTU_SCIEZKI 70
typedef struct{
    char katalog[DLUG_SCIEZKI_KAT];
    int numer_schezki;
    char tekst_sciezki[DLUG_TEKSTU_SCIEZKI];
} wpis_cds;

int iniciuj_baze(const int nowa_baza);
void zakoncz_baze(void);

wpis_cdk pobierz_wpis_cdk(const char *wsk_katalog_cd);
wpis_cds pobierz_wpis_cds(const char *wsk_katalog_cd, const int nrumer_sciezki);

int dodaj_wpis_cdk(const wpis_cdk dodany_wpis);
int dodaj_wpis_cds(const wpis_cds dodany_wpis);

int usun_wpis_cdk(const char *wsk_katalog_cd);
int usun_wpis_cds(const char *wsk_katalog_cd, const int numer_sciezki);

wpis_cdk szukaj_wpisu_cdk(const char *wsk_katalog_cd, int *wsk_pierwszy_raz);
