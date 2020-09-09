for _ in range(int(input())):
    v = int(input())
    h = v*v*5
    n = int(input())
    people =[]
    minhold = 500
    for i in range(n):
        a,b,c = [int(x) for x in input().split()]
        if(a<minhold and b>19):
            minhold=a
            continue
        if(minhold<a and b<20):
            continue
        people.append([a,b,c])
    people.append([minhold,22,1])
    ph = min(int(x[0]) for x in people)
    print(str(0)+': '+str(h+ph))

    for i in range(20):
        for some in people:
            some[1]+=1
            if(some[1]<20):
                some[0]+=some[2]
            if(some[1]>19 and some[0]>minhold):
                people.remove(some)
        ph = min(int(x[0]) for x in people)
        print(str(i+1)+': '+str(h+ph))
