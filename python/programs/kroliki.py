def kroliki(n,a,b):
    if(n==1): return a%10
    if(n==2): return b%10
    if(n==3): return (a+b)%10
    if(n==4): return (2*b+a)%10
    if(n>4):
        n1=kroliki(3,a,b)
        n2=kroliki(4,a,b)
        for i in range(5,n+1):
            x = (n1 + n2) % 10
            n1 = n2
            n2 = x
        return x

for _ in range(int(input())):
    n,a,b = input().split()
    print(str(kroliki(int(n),int(a),int(b))))
