#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int T;

int dx[8] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[8] = {2, 2, -2, -2, 1, -1, 1, -1};

int BFS(){
    int N;
    cin >> N;
    int chess[301][301] = {0, };
    int check[301][301] = {0, };
    int m, n, a, b;
    cin >> m >> n;
    chess[m][n] = 1;

    cin >> a >> b; // a, b가 target.
    chess[a][b] = 2;

    queue<pair<pair<int, int>, int>> Q;
    Q.push({{m,n}, 0});
    check[m][n] = 1;
    //cout << Q.front().first << Q.front().second;
    int ans = 0;
    if(m == a && n == b) return 0;
    while(true){
        pair<pair<int,int>,int> temp = Q.front();
        Q.pop();
        
        for(int i=0; i<8; i++){
            int x = temp.first.first + dx[i];
            int y = temp.first.second + dy[i];
            if(x >= N || y >= N || x < 0 || y < 0) continue;
            if(check[x][y] == 1) continue;
            if(x == a && y == b) return temp.second+1;
            //cout << temp.second << " = x , y : " << x << ", " << y << "\n";
            check[x][y] = 1;
            Q.push({{x,y}, temp.second +1});
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    while(T--){
        cout << BFS() << "\n";
    }

}
