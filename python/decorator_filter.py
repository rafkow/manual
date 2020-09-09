from random import randrange

zoo = list()

def select_animal(func):
    def animal_function(*arg, **kwargs):
        _zoo = zoo
        if kwargs.get('legs', None):
            _zoo = list(filter(lambda a: a.number_legs == kwargs.get('legs'), _zoo))
            kwargs.pop('legs')
        if kwargs.get('sex', None):
            _zoo = list(filter(lambda a: a.sex == kwargs.get('sex'), _zoo))
            kwargs.pop('sex')
        kwargs.update({'_zoo':_zoo})
        return func(**kwargs)
    return animal_function


class Animals:

    def __init__(self, legs: int):
        self.number_legs = legs
        self.sex = 'male' if randrange(2) == 0 else 'female'
        zoo.append(self)

    def __repr__(self):
        return f"i`m {self.sex} animal with {self.number_legs} legs"

    @classmethod
    @select_animal
    def walk(_zoo = None):
        for animal in _zoo:
            print(f"animal walk on {animal.number_legs} legs ")


for i in range(10):
    print(Animals(randrange(2,5)))

Animals.walk(sex='male', legs=2)
