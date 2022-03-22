
def DFS (m, n,depth):
    
    if depth == n+1 :
        for i in range(1, n+1):
            print(arr[i], end=" ")
        print("")
        return
    else :
        for i in range(1,m+1) :
            
            if arr[depth-1] > i and depth != 1:
                continue
                
            else:
                arr[depth] = i
                DFS(m, n, depth+1)

    
        return


if __name__ == "__main__":

    m, n = map(int ,input().split())
    check = [False] * (m+1)
    
    arr = [0] * (n+1)
    DFS(m, n, 1)