#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[502];
int value[502];

int N;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int idx;
    int max_value=0;
    for (int i =0; i<N;i++){
        cin >> idx;
        cin >> value[idx];
        DP[idx] =1;
        max_value = max({max_value, idx});
    }

    // for (int i =0; i<N;i++){
    //     cout << value[i];
    // }
    int answer = 0;
    for (int i =2; i< max_value+1; i++){
        
        if(value[i] != 0){
            for(int j =i; j >0; j--){
                if(value[j] != 0){
                    if(value[j] < value[i]){
                        DP[i] = max({DP[i], DP[j] +1});
                    }
                }
            }
        }
        
        //cout << i << " value";
        //cout << DP[i] << "\n";
        answer = max(DP[i], answer);
    }

    

    cout << N - answer;
}

/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
*/