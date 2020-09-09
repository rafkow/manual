def nwd(*args):
    result = 1
    m = min(*args)
    print(f'type od args {type(args)}')
    print(f'type od min {type(m)}')
    print(f"zupa z buraka {m}")
    for i in range(1, m):
        for arg in sorted(*args):
            if arg % i != 0:
                break;
            result = i
    return result

x = 45, 24, 31
m = min(x)
print(f'type od args {type(x)}')
print(f'type od min {type(m)}')
print('======================')
print(nwd(x))
