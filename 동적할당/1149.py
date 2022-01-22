# RGB거리
# 
# 지금 집이 빨강이 되는 경우는 전 집에서 
'''
3
26 40 83
49 60 57
13 89 99

    1   2         3
빨  26  49+40=98  13+83 = 96
초  40  60+26=86  62+89
파  83  57+26=83
'''

N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, input().split())) )

DP = [[0 for i in range(N)] for j in range(3)]

#첫 부분
for i in range(3):
    DP[i][0] = arr[0][i]

for i in range(1, N):
    DP[0][i] = min(arr[i][0]+DP[1][i-1],arr[i][0]+DP[2][i-1])
    DP[1][i] = min(arr[i][1]+DP[0][i-1],arr[i][1]+DP[2][i-1])
    DP[2][i] = min(arr[i][2]+DP[0][i-1],arr[i][2]+DP[1][i-1])

print(min(DP[0][N-1], DP[1][N-1], DP[2][N-1]))


