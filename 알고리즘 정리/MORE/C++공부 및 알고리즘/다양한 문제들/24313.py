
a1, a2 = map(int, input().split())
c = int(input())
n0 = int(input())

if (c == a1):
    if(a2 != 0):
        print(0)
       
    else:
        print(1)

    exit(0)

   
if c -a1 > 0:
    if ((a2 / (c - a1)) <= n0):
        print(1)
    else : 
        print(0)
else :
    if ((a2 / (c - a1)) <= n0):
        print(0)
    else : 
        print(1)
   
   

