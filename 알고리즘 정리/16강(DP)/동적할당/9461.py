# 1, 1, 1, 2, 2, 3, 4, 5, 7(5+[4]), 9(7+[5]), 12(9+[6]) , 16(12+[7]), 17(16+[8])
#  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12 ,13

T = int(input())
P_N = []
for i in range(T):
    P_N.append(int(input()))

k = max(P_N) + 1

if k >= 7 :
    DP = [0 for i in range(k)]
else :
    DP = [0 for i in range(7)]

index = 0
for i in [0,1,1,1,2,2,3]:
    DP[index] = i
    index +=1


for i in range(7,k):
    DP[i] = DP[i-1] + DP[i-5]

#print(DP)
for i in range(T):
    print(DP[P_N[i]])