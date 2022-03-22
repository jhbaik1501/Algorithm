# 12 23 34 45 56 67 78 89       90불가
# 98 87 76 65 54 43 32 21 10

#0   1       2       3      4       5       6       7       8       9
#1  0 2     1 3     2 4    3 5     4 6     5 7     6 8     7 9     8 

import copy

Depth = int(input())
Depth -= 1
DP0 = [0,1,1,1,1,1,1,1,1,1]
DP1 = [0] * 10

for i in range(Depth):
    DP1 = [0] * 10
    for j in range(10):
        if j == 0:
            DP1[1] += DP0[0]
        elif j == 9:
            DP1[8] += DP0[9]
        else :
            DP1[j-1] += DP0[j]
            DP1[j+1] += DP0[j]
    
    DP0 = copy.deepcopy(DP1)

print(sum(DP0) % 1000000000)


