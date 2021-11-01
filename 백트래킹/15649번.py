
def DFS (m, n,depth):
    if depth == n :
        for i in arr:
            print(i, end= " ")
        print("")
        return
    else :
        for i in range(1,m+1) :
            if check[i] == False :
                
                arr[depth] = i
                check[i] = True
                DFS(m, n, depth+1)

                check[i] = False
        return


if __name__ == "__main__":

    m, n = map(int ,input().split())
    check = [False] * (m+1)
    
    arr = [0] * n
    DFS(m, n, 0)