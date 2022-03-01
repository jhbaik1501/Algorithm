#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

int T;
int N, M;

int main() { 
    cin >> T;
    
    while(T--){
        cin >> N >> M;
        deque<pair<int,int>> dq;
        
        for(int i=0; i<N ; i++){
            int temp;
            cin >> temp;
            int k = dq.front().first;
            if(temp >= k){
                dq.push_front({temp, i});
            }
            else{
                dq.push_back({temp, i});
            }

        }

        int ans =0;
        while(true){
            ans++;
            cout << "dq.front().second : " << dq.front().second <<"\n" ;
            if(dq.front().second == M) break;
            dq.pop_front();
        }

        cout << ans << "\n";
    }
}



