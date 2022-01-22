# 내 차례 것을 넣었을 경우와 넣지 않았을 경우를 비교한다.

N, K = map(int, input().split())
#4 7
arr = []

for i in range(N):
    k = list(map(int, input().split()))
    arr.append(k)

DP = [[0 for i in range(K+1)] for j in range(N)]


for i in range(0, N):
    for j in range(1,K+1):
        if i != 0:
            if j >= arr[i][0] :
                DP[i][j] = max(arr[i][1] + DP[i-1][j-arr[i][0]], DP[i-1][j])
                
            else : 
                DP[i][j] = DP[i-1][j]
        else :
            if j >= arr[i][0] :
                DP[i][j] = arr[0][1]

        

print(DP[N-1][K])