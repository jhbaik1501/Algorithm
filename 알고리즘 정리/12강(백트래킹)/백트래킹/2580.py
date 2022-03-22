'''
먼저 0이라고 적힌 칸을 행우선으로 분류
    [0,0] -> 예를 들어 [3,4,5]가 된다?
      -
    [4,3] -> 예를 들어 [3,4]가 된다?
      -
    [5,4] -> 예를 들어 아무것도 안된다? back
      -
    0칸이 없다? return 해주고 
'''
Sdoku = [[0 for _ in range(9)] for _ in range(9)]
Not_in = []

for i in range(0,9):
    Sdoku[i] = list(map(int, input().split()))
    


def check(x, y):
    ret_arr = [1,2,3,4,5,6,7,8,9]
    
    for line in Sdoku[x]:
        if line in ret_arr:
            ret_arr.remove(line)
            #print(line)

    for row in [row[y] for row in Sdoku]:
        if row in ret_arr:
            ret_arr.remove(row)
            #print("row",row)
    x_in = x // 3
    y_in = y // 3

    for i in range(x_in*3,(x_in*3)+3):
        for j in range(y_in*3,(y_in*3)+3):
            if Sdoku[i][j] in ret_arr:
                ret_arr.remove(Sdoku[i][j])
                #print("HI",i,j ,Sdoku[i][j])
    return ret_arr



def DFS(n, depth):
    global a
    if depth == n:
        for i in range(9):
            for j in range(9):
                print(Sdoku[i][j], end=" ")
            print("")
        
        a = 1
        return 
    else :
        Arr = check(Not_in[depth][0], Not_in[depth][1])
        for i in Arr:
            
            Sdoku[Not_in[depth][0]][Not_in[depth][1]] = i
            #print(Sdoku)
            DFS(n, depth+1)
            if (a == 1):
                return
            Sdoku[Not_in[depth][0]][Not_in[depth][1]] = 0
            
        

for i in range(9):
    for j in range(9):
        if Sdoku[i][j] == 0 :
            Not_in.append([i,j])
a = 0
DFS(len(Not_in), 0)


