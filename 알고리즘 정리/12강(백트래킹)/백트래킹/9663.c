/*
힌트를 보았음.
"중요한 부분!" -> 총 N개가 들어가야 하므로 각 행마다 1개씩 들어가야한다!

col : 각 행마다 들어간 퀸의 index저장.
시간을 줄이기 위해 하는 행동 -> col이라는 배열을 만들고, col의 다음 index로 갔을 때 
그 자리가 올바른 자리인지 확인을 위해 check라는 함수를 생성.
check함수는 depth와 그 전에 퀸의 index가 같은 경우 세로에 같이 서있으므로 불가. depth와 퀸의 index차이와 depth - j의 차이 비교해서 대각선도 해결.
*/
// python으로하면 시간초과로 인하여..
#include <stdlib.h>
#include <stdio.h>
#define MAX 15
int col[15];
int k = 0;
int N = 0;

int check(int);
void dfs(int);



int check(int depth)
{
    for (int i = 0; i< depth; i++){
        if (col[i] == col[depth] || abs(col[i] - col[depth]) == depth - i){
            return 0;
        }
    }
    return 1;
}
void dfs(int depth){
    
    if (depth == N){
        k++;
    }
    else
    {
        for (int i =0; i < N; i++)
        {
            col[depth] = i;
            if (check(depth))
                dfs(depth+1);
        }
    }
}

int main(){

    scanf("%d", &N);
    dfs(0);
    printf("%d", k);
}

    