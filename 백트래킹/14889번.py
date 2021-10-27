min_abil = 200
x = 0
def DFS(num, depth):
    global min_abil
    global x
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
        x+=1
        print(abs(start - link), check, "몇번?", x)
        
        return min_abil



    else :
        for i in range(num):
            
            # if check[i] == False and depth != 0 and arr[depth-1] > i :
            #     continue
            if check[i] == False:
                if depth != 0 and arr[depth-1] > i :
                    continue
                #print(depth, i, "depth, i")
                arr[depth] = i
                #print(arr)
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
    
    
