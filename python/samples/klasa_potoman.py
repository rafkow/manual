class Parent:
    def __init__(self):
        self.__var1 = "Dupsko"
    
    def get_variable(self):
        return self.__var1

class Child(Parent):
    def __init__(self):
        Parent.__init__(self)
        self.__var2= "Siusiak"
        pass

    def get_variable(self):
        return self.__var1

p1 = Parent()
c1 = Child()

print(p1.get_variable())
print(c1.get_variable())
