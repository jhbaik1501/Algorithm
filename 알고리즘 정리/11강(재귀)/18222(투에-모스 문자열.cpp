#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

long long k;

int idx;
void recursive(long long k){

    if(k == 1) { return;}
    if(k == 2) {idx++; return;}

    long long two = 1;
    while(two < k){
        two = two * 2;
    }
    two/=2;
    k-= two;
    idx++;
    recursive(k);
}
int main(){
    ios::sync_with_stdio(0);
    
    cin >> k;
    
    recursive(k);
    
    if(idx % 2 == 0){ cout << 0;}
    else {cout << 1;}
}
