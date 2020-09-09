class A:
    def suma(self,a,b):
        return a+b

class B(A):
    def suma(self,a,b,c):
        b += c
        d = super().suma(a,b)
        return d * 2

a = A()
print (a.suma(1,2))
b = B()
print (b.suma(1,2,5))
