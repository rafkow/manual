class A:
    def __init__(self):
        self.__dupeczka = "odbyt"

    def sraj(self):
        print(self.__dupeczka)


a = A()
a.sraj()
b = []
if b.__len__() > 0 and b[-1] == 5:
    print("cos")
b.append(4)
b.append(6)
print (b[0])

print("elo") if b[-1] == 7 else print("zupa")


for i in range(0):
    print("pindol")