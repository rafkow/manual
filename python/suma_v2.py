def CzyIstniejeRedukcja(tab):
    if(tab.__len__() > 1):
        n = tab.__len__() -1
        #if (tab[n] >= tab[n - 1]):
        if ((tab[n]-1 >= tab[n-1]+1) & (tab[n]-1 > 1)):
                tab[n] -= 1
                tab[n-1] += 1
                return tab
        else:
		#print(tab,' - nie weszles')
                if ((tab[n]-1 < tab[n-1]+1) & (tab[n]-1 > 1)):
                    tab2 = tab
		    tab2[n]-=1
                    tab2[n-1]+=1
		    x = tab2[n]
		    del tab2[-1]
                    if(CzyIstniejeRedukcja(tab2)):
                        tab2.append(x)
			tab = tab2
			#print(tab,' - poszlo')
			return tab
	return False

def UstawTablice(n, dlugosc):
    tab = []
    for i in range(dlugosc - 1):
        tab.append(1)
    tab.append(n-(dlugosc-1))
    return tab

n = 11
tab = UstawTablice(n,n)
print(tab)

while(tab.__len__() > 1):
    if(CzyIstniejeRedukcja(tab)):
        print(tab)
    else:
        tab = UstawTablice(n,tab.__len__() -1)
        print(tab)
