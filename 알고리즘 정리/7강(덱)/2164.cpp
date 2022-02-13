#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
using namespace std;


int N, M;


int main(){
    cin >> N >> M;
    
    int tar;
    deque<int> DQ;
    for(int i=1; i<N+1;i++){
        DQ.push_back(i);
    }
    int ans = 0;
    while(M--){
        cin >> tar;
        int j;
        for(j=0; j< DQ.size(); j++){
            if(DQ[j] == tar) break;
        }
        
        if(j <= DQ.size()/2 ){
            while(DQ.front() != tar){
                DQ.push_back(DQ.front());
                DQ.pop_front();
                ans++;
            }
            DQ.pop_front();
        }
        else{
            while(DQ.front() != tar){
                DQ.push_front(DQ.back());
                DQ.pop_back();
                ans++;
            }
            DQ.pop_front();
        }

        //cout << "tar , ans : "<< tar << ", "<<ans << "\n";
    }

    cout << ans;
}