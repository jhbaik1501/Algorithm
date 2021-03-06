#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

int A, B;
int N, M;
int arr[101][101];
int arr_[101][101];
struct vector3{
    int x;
    int y;
    int dir;
};

// pair<int,int> dir[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
pair<int,int> dir[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
vector3 robot[101]; // 위치

int flag = 0;
void move(int num, int rep){
    
    arr[robot[num].x][robot[num].y] = 0;
    cout << num << ",  x, y : "<< robot[num].x << ", " << robot[num].x << "\n";

    for(int i=0; i< rep; i++){
        robot[num].y += dir[robot[num].dir].first ;
        robot[num].x += dir[robot[num].dir].second ;

        if(arr[robot[num].x][robot[num].y] == 1){
            cout << "Robot " << num << " crashes into robot " << arr_[robot[num].x][robot[num].y];
            flag = 1;
            return;
            // exit(0);
        }
        else if(robot[num].x >= A || robot[num].x < 1 || robot[num].y >= B || robot[num].y < 1){
            cout << "Robot " << num << " crashes into the wall";
            flag = 1;
            return;
            // exit(0);
        }
    }
    arr[robot[num].x][robot[num].y] = 1;
    arr_[robot[num].x][robot[num].y] = num;
    
}

void rotate_right(int num, int rep){

    int rotate = rep % 4;
    robot[num].dir += rotate;
    robot[num].dir %= 4;

}

void rotate_left(int num, int rep){

    int rotate = rep % 4;
    if(rotate == 1){
        robot[num].dir += 3;    
    }
    else if(rotate == 2){
        robot[num].dir += 2;    
    }
    else if(rotate == 3){
        robot[num].dir += 1;  
    }
    robot[num].dir %= 4;
}


int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> B >> A;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        int a, b;
        char d;
        cin >> a >> b >> d;
        a--;
        b--;
        robot[i].x = a;
        robot[i].y = b;

        arr[a][b] = 1;
        arr_[a][b] = i;
        if(d == 'W'){
            robot[i].dir = 0;
        }
        else if(d == 'W'){
            robot[i].dir = 2;
        }
        else if(d == 'N'){
            robot[i].dir = 3;
        }
        else{
            robot[i].dir = 1;
        }
    }

    for(int i=0; i<M; i++){
        int rob, rep;
        char com;
        cin >> rob >> com >> rep;

        if(flag == 1) continue ;
        if(com == 'L'){
            rotate_left(rob, rep);
        }
        else if(com == 'R'){
            rotate_right(rob, rep);
        }
        else if(com == 'F'){
            move(rob, rep);
        }
        
    }
    
    if(flag == 1) return 0 ;
    cout << "OK";
}



