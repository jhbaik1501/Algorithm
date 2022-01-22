# DP는 점화식을 만들어서 풀자!
# DP[i] = DP[i/3] + 1
# DP[i] = DP[i/2] + 1
# DP[i] = DP[i-1] + 1

X = int(input())
DP = [0] * 1000001

for i in range(2, X+1):
    DP[i] = DP[i-1] +1
    if i % 3 == 0:
        DP[i] = min(DP[i], DP[i//3] + 1)
    if i % 2 == 0:
        DP[i] = min(DP[i], DP[i//2] + 1)


print(DP[X])
