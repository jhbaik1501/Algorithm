#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

char arr[12][6];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;

int erase(){
    
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(arr[i][j] != '.'){

                int check[12][6] = {0, };
                char tar = arr[i][j];
                
                queue<pair<int, int>> Q;
                vector<pair<int, int>> v;
                Q.push({i,j});
                check[i][j] = 1;
                while(!Q.empty()){
                    auto temp =Q.front();
                    v.push_back({temp.first, temp.second});
                    Q.pop();
                    for(int i=0; i<4; i++){
                        int x = temp.first + dx[i];
                        int y = temp.second + dy[i];
                        if(x >= 12 || y >= 6 || x < 0 || y < 0) continue;
                        if(check[x][y] == 1) continue;
                        if(arr[x][y] != tar) continue;
                        check[x][y] = 1;
                        Q.push({x,y});
                        
                    }
                }

                if(v.size() >= 4){
                    
                    // ans++;
                    while(!v.empty()){
                        auto temp = v.back();
                        v.pop_back();
                        arr[temp.first][temp.second] = '.';
                    }
                    return 1;
                }


            }
        }
    }

    return 0;
}

void relocate(){

    int check[6] = {0, };

    for(int i=0; i< 12; i++){
        for(int j=0; j<6; j++){
            if(arr[i][j] != '.')
                check[j]++;
        }
    }

    for(int j=0; j< 6; j++){
        int idx = 11;
        for(int i=11; i>=0; i--){
            if(i == idx && arr[i][j] != '.'){
                idx--;
            }
            else if(i != idx && arr[i][j] != '.'){
                arr[idx][j] = arr[i][j];
                idx--;
                arr[i][j] = '.';
            }
        }
    }
    
}

int main() { 

    for(int i=0; i<12; i++){
        string str;
        cin >> str;
        for(int j=0; j<6; j++){
            arr[i][j] = str[j];
        }
    }

    // erase();
    // relocate();

    // erase();
    // relocate();

    while(true){
        relocate();
        if(!erase()) break;
        ans++;
        while(true){
            if(!erase()) break;
        }
    }
    // while(erase()){
    //     relocate();

    //     cout << "\n";
    //     for(int i=0; i<12; i++){
    //         for(int j=0; j<6; j++){
    //             cout << arr[i][j];
    //         }
    //         cout << "\n";
    //     }

    // }
    
    cout << ans;


}



