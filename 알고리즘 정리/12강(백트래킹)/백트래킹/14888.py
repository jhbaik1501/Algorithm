

cal = [] #배열된 수식들
inputVal = [] #input값들
inputCal = [] #ipput수식
result = [] #결과값 저장

N = int(input()) - 1
inputVal = list(map(int,input().split()))
inputCal = list(map(int,input().split()))

check = [False] * N # 중복 제거를 위한 체크


def Q(z,x):
    re=0
    if z<0:
        re=abs(z)//x
        return re*(-1)
    else:
        re=z//x
        return re


def DFS(N, depth):

    if depth == N :
        res = inputVal[0]
        
        for i in range(N) :
            if cal[i] == '+':
                res += inputVal[i+1]
            if cal[i] == '-':
                res -= inputVal[i+1]
            if cal[i] == '*':
                res *= inputVal[i+1]
            if cal[i] == '//':
                res = Q(res, inputVal[i+1])
                
        #print(cal)
        result.append(res)
        
    else :
        for j in range(4):
            if inputCal[j] != 0 :
                inputCal[j] -= 1                    
                if j == 0 : 
                    cal.append("+")
                elif j == 1 : 
                    cal.append("-")
                elif j == 2 :
                    cal.append("*")
                elif j == 3 : 
                    cal.append("//")
                DFS(N, depth+1)
                inputCal[j] += 1
                cal.pop()

DFS(N, 0)
print(max(result))
print(min(result))
            