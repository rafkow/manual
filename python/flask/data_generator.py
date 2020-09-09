from threading import Thread
import time
import random

class Generator:
    def number_generator(self):
        while(True):
            print(random.randrange(500))
            time.sleep(1)

gen = Generator()
gen.number_generator()
