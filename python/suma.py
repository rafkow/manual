def CzyIstniejeRedukcja(tab):
    if(tab.__len__() > 1):
        n = tab.__len__()
        for i in range(1,n):
            for j in range(i-1,-1,-1):
                if((tab[j]<tab[i]) & (tab[j]+1<=tab[i]-1)):
                    tab[i] -= 1
                    tab[j] += 1
                    return tab
        return False

def UstawTablice(n, dlugosc):
    tab = []
    for i in range(dlugosc - 1):
        tab.append(1)
    tab.append(n-(dlugosc-1))
    return tab

def wyswietl(dane):
	for liczba in dane:
		print(liczba, sep=' ', end=' ')
	print();


tab = []
ile = int(input())
for i in range(ile):
	n= int(input())
	tab = UstawTablice(n,n)
	wyswietl(tab)
 
	while(tab.__len__() > 1):
    		if(CzyIstniejeRedukcja(tab)):
        		wyswietl(tab)
    		else:
        		tab = UstawTablice(n,tab.__len__() -1)
       			wyswietl(tab)
	print()
