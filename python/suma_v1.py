def CzyIstniejeRedukcja(tab):
    if(tab.__len__() > 1):
        n = tab.__len__() -1
        if (tab[n] > tab[n - 1]):
            if ((tab[n]-1 >= tab[n-1]+1) & (tab[n]-1 > 1)):
                tab[n] -= 1
                tab[n - 1] += 1
                return tab
            else:
                if ((tab[n]-1 < tab[n-1]+1) & (tab[n]-1 > 1)):
                    tab[n]-=1
                    x = tab[n]
                    tab[n-1]+=1
                    tab = CzyIstniejeRedukcja(tab[:n])
                    if(tab == False):
                        return False
                    return tab.append(x)
                else:
                    CzyIstniejeRedukcja(tab[:n])
    return False

def UstawTablice(n, dlugosc):
    tab = []
    for i in range(dlugosc - 1):
        tab.append(1)
    tab.append(n-(dlugosc-1))
    return tab

n = 12
tab = UstawTablice(n,n)
print(tab)

while(tab.__len__() > 1):
    if(CzyIstniejeRedukcja(tab)):
        print(tab)
    else:
        tab = UstawTablice(n,tab.__len__() -1)
        print(tab)
