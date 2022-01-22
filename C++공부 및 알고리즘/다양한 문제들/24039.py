k = int(input())
Max = 100000
check = [False] * Max  
for i in range(2, Max):
    if check[i] == False :
        for j in range(i * 2, Max, i):
          
            check[j] = True
          
List = []
for i in range(2, Max):
    if check[i] == False:
        List.append(i)

for i in range(1000):
    target = List[i] * List[i+1]
    #print(target)
    if k < target <= Max :
        print(target)
        break
    elif target >= Max:
        break

# A = [6,
# 15,
# 35,
# 77,
# 143,
# 221,
# 323,
# 437,
# 667,
# 899,
# 1147,
# 1517,
# 1763,
# 2491,
# 3599,
# 4087,
# 5183,
# 6557,
# 7387,
# 9797]
# k = int(input())
# for i in A:
#     if k < i:
#         print(i)
#         break