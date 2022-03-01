#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;


deque<int> circle[4];

void rotate(int location, int direction){
    if(direction == 1){
        int temp = circle[location].back();
        circle[location].pop_back();
        circle[location].push_front(temp);
    }
    else if(direction == -1){
        int temp = circle[location].front();
        circle[location].pop_front();
        circle[location].push_back(temp);
    }
}

int main() { 

    for(int i=0; i<4; i++){
        string str;
        cin >> str;
        for(int j=0; j<8; j++){
            circle[i].push_back(str[j]-'0');
        }
    }
    
    int T;
    cin >> T; 

    int target, direction;
    while(T--){
        cin >> target >> direction;
        int dir[4] = {0, };
        target--;
        int t = target;
        dir[target] = direction;

        while(t<3){
            if(circle[t+1][6] != circle[t][2]){
                if(dir[t] == 1){
                    dir[t+1] = -1;
                }
                else if(dir[t] == -1){
                    dir[t+1] = 1;
                }
                else{
                    dir[t+1] = 0;
                }
            }
            t++;
        }
        while(target > 0){
            if(circle[target-1][2] != circle[target][6]){
                if(dir[target] == 1){
                    dir[target-1] = -1;
                }
                else if(dir[target] == -1){
                    dir[target-1] = 1;
                }
                else{
                    dir[target-1] = 0;
                }
            }
            target--;
        }

        //cout << " dir : " << dir[0] << " " << dir[1] << " " << dir[2] << " " << dir[3] << "\n";
        for(int i=0; i<4; i++)
            rotate(i, dir[i]);
        
    }

    int ans = 0;
    for(int i=0; i<4; i++){
        if(circle[i][0]){
            if(i==0){
                ans += 1;
            }
            if(i==1){
                ans += 2;
            }
            if(i==2){
                ans += 4;
            }
            if(i==3){
                ans += 8;
            }
        }
        
    }
    cout << ans;
}



