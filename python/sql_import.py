values = """
Gorące powierzchnie
Materiały łatwopalne/pożar
Źródło zapłonu
Spadające przedmioty
Słabe oświetlenie
Czynniki biologiczne
Czynniki chemiczne
Zagrożenia dla środowiska
Praca na wysokości
Wysoka/niska temperatura
Elektronarzedzia/ Narzędzia ręczne
Transport ręczny
Poślizgnięcie się
Zmiażdżenie
Hałas
Pył
złe warunki pogodowe
Promieniowanie
Opary
Rozlewy/rozsypy
Wirujące elementy
Praca samodzielna
Zakleszczenie
Skaleczenie
Urządzenia dźwigowe z napędem
Ograniczona przestrzeń
Wejście do zbiornika
Duży ruch komunikacyjny
Ładunki elektrostatyczne
Uszkodzenie lini (wyrzut/wypływ subt.)
"""

tablename = 'wapp_dangers'

for i in values.split('\n'):
    if(len(i)> 0):
        print(f"insert into {tablename}(name) values ('{i}');")
