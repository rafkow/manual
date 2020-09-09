class Nowa:
    def __init__(self):
        self.suma = 0

    def dodawanie(self,a,b):
        self.suma = a +b
        print(self.suma)

    def mnozenie(self,a,b):
        self.__iloczyn = a *b
        print(self.__iloczyn)

    def wyniki(self):
        if '__iloczyn' in locals():
            print("w pamieci {0}".format(self.iloczyn))

n = Nowa()
n.dodawanie(5,6)
n.wyniki()
n.mnozenie(3,6)
n.wyniki()

