

# 내것을 더하는 경우와 더하지 않는 경우
#     10 -4 3 1 5 6 -35 12 21 -1
# + 10 6  9  10 15 21 -14 12 33 32 
# X 0  10 10 10 10 15 21  21 21 33

num = int(input())
arr = list(map(int, input().split()))

DP = [[0 for i in range(num)] for j in range(2)]


    
for i in range(num):
    if i == 0:
        DP[0][0] = arr[0]
    else:
        if DP[0][i-1] >= 0: 
            
            DP[0][i] = DP[0][i-1] + arr[i]
        else :
            DP[0][i] = arr[i]

        DP[1][i] = max(DP[0][i-1], DP[1][i-1])


All_minus = True

for i in arr:
    if i >= 0 :
        All_minus = False
        break

if All_minus == False:
    print(max(DP[0][-1], DP[1][-1]))
else :
    print(max(arr))