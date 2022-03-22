min_abil = 200

def DFS(num, depth):
    global min_abil
    
    if depth == num //2 : 
        start = 0
        link = 0
        for i in range(num): 
            for j in range(num):
                if check[i] and check[j]:
                    start += array[i][j] + array[j][i]
                    
                if check[i] == False and check[j] == False:
                    link += array[i][j] + array[j][i]
        
        start =start // 2
        link = link //2
        min_abil = min(min_abil, abs(start - link))
        
        
        
        return min_abil



    else :
        for i in range(num):
            
            
            if check[i] == False:
                if depth != 0 and arr[depth-1] > i :
                    continue
                
                arr[depth] = i
                check[i] = True
                DFS(num, depth+1)
                check[i] = False

        return
                
       
num = int(input())
    
array = [[0 for col in range(num)] for row in range(num)]

for i in range(num):
    array[i] = list(map(int, input().split()))

ability = []
arr = [0] * (num//2)
check = [False] * num

DFS(num, 0)
print(min_abil)
    
    
