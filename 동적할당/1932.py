#정수 삼각형
#양쪽 층 샥샥 비교
#7
#10 15
#18 max(11 16) 15

n = int(input())



DP = []
for i in range(n):
    DP.append(list(map(int, input().split())))

for i in range(1, n):
    for j in range(i+1):
        #끝자리나 첫자리는 무조건 한곳에서 가져옴.
        if j == 0:
            DP[i][j] += DP[i-1][0] 
        elif j == i:
            DP[i][j] += DP[i-1][j-1]
        else:
            DP[i][j] += max(DP[i-1][j-1], DP[i-1][j])

print(max(DP[n-1]))
        


    
    