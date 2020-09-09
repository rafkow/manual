

def map(x, od, do):
    return int(x * od / do)

for i in range(44):
    print('{} to {}'.format(i, map(i,14,44)))

