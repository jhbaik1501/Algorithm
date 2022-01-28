/* 숨바꼭질 */
/* 이 문제는 딱 봤을 때, BFS임을 알아차리기는 어려우나, 똑같이 최단거리를 찾고 퍼저나가는 조건이 3가지임을 알아차리면 BFS임을 알 수 있다.*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int board[200001];
int check[200001];
int time = 0;
int N, K;

int main(){
    cin >> N >> K;
    
    queue<int> Q;
    check[N] = 1;
    Q.push(N);

    if(N == K){
        cout << "0";
        return 0;
    }
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        //cout << "temp = "<<temp << "," << board[temp] << " -> ";
        for (int i = 0 ; i< 3; i++){
            int k;
            if(i == 0) k = temp-1;
            else if(i == 1) k = temp+1;
            else if(i == 2) k = temp*2;
            
            if (k < 0 || k > 200000) continue;
            if (check[k] == 1) continue;
            if (k == K) {
                cout << board[temp]+1;
                return 0;
            }
            check[k] =1;
            board[k] = board[temp]+1;
            Q.push(k);
        }
    }
}
