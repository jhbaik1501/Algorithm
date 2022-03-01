#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

long long K, N;
long long LAN[10010];

long long solve(long long length){
    long long ret = 0;
    for(long long i=0; i<K; i++){
        ret += LAN[i] / length;
    }

    return ret;
}


long long main(){
    cin >> K >> N;
    for(long long i=0; i<K; i++){
        cin >> LAN[i];
    }    

    long long st =0;
    long long en = *max_element(LAN, LAN+K) ;
    long long mid;
    en *= 3;
    

    while(st < en){
        
        mid = (st+en+1) /2;
        //  cout << "mid : " <<mid << "\n";
        if(solve(mid) < N){
            en = mid-1;
        }
        else{
            st = mid;
        }
    }
    
    cout << st;
}