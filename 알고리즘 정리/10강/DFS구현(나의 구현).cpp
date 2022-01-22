#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };
int check[502][502];
int m = 7; // 행
int n = 10; // 열

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; //{dx, dy} 상하좌우 4칸을 의미.

int main(){
    
    stack<pair<int, int>> S;
    S.push({0, 0});
    check[0][0] = 1;

    while(!S.empty()){
        pair<int,int> p = S.top();
        cout << "(" <<p.first << "," << p.second << ") -> ";
        S.pop();
        for(int i = 0; i < 4; i++){
            int first = p.first + dx[i];
            int second = p.second + dy[i];
            if(first >= m || second >= n || first < 0 || second < 0) continue; //범위를 벗어난 경우 그냥 넘김
            if(board[first][second] != 1 || check[first][second]) continue; //1이 아닌 경우나 이미 지나온 경우도 그냥 넘김
            check[first][second] = 1;
            S.push({first, second});
        }
    }
}
