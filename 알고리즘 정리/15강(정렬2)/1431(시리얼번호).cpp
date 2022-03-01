#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;


bool compareObject(string a, string b){
    
    if(a.size() == b.size()){
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<a.size(); i++){

            if('0' <= a[i] && a[i] <= '9'){
                sum1 += a[i] - '0';
            }
            if('0' <= b[i] && b[i] <= '9'){
                sum2 += b[i] - '0';
            }
        }
        
        // cout << sum1 << ", "<< sum2 << "\n";
        if(sum1 == sum2){
            return a < b;
        }
        return sum1 < sum2;
    }

    return a.size() < b.size();
}
int N;
string S[51];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    string str;
    for(int i=0; i<N; i++){
        cin >> S[i];
    }

    sort(S, S+N, compareObject);

    
    //  cout << "\n";
    for(int i=0; i<N; i++){
        cout << S[i] << "\n";
    }
}

/*
3 0
1 2 3
*/