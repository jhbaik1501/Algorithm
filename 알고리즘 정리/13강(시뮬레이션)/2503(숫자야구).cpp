#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <string>
using namespace std;

int check[1001];
int arr[101];
int N;


void checking(int num, int strike, int ball){
    for(int i=100; i<1000; i++){
        // 정답이 104라고 햇을때, 104 는 몇볼 몇스트라이크일까?
        // 123 104  103
        if(check[i] == 1) continue;

        int st_idx=0, ba_idx=0;

        string str1 = to_string(num);
        string str2 = to_string(i);

        if(str1[0] == str2[0]) st_idx++;
        if(str1[1] == str2[1]) st_idx++;
        if(str1[2] == str2[2]) st_idx++;

        if( str1[0] == str2[1] || str1[0] == str2[2] ) ba_idx++;
        if( str1[1] == str2[0] || str1[1] == str2[2] ) ba_idx++;
        if( str1[2] == str2[0] || str1[2] == str2[1] ) ba_idx++;

        // for(int m=0; m<3; m++){
        //     for(int n=m; n<3; n++){ 

        //         if( str1[m] == str2[n] ){

        //             if(m == n){
        //                 st_idx++;
        //             }
        //             else{
        //                 ba_idx++;
        //             }

        //         }

        //     }
        // }

        if(st_idx != strike || ba_idx != ball) {
            // cout << "i : " << i << "\n";
            check[i] = 1;
        }
    }
}

int main(){
    cin >> N;
    

    for(int i=100; i<1000; i++){
        int a1 = i / 100;
        int a2 = i / 10 - a1 * 10;
        int a3 = i / 1 - a1 * 100 - a2 * 10;
        if(a1 == a2 || a2 == a3 || a3 == a1){
            // cout << i << " ";
            check[i] = 1;
        }
        if( a1 == 0 || a2 == 0 || a3 == 0){
            check[i] = 1;
        }
    }
    

    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        checking(a,b ,c);
    }
    int ans= 0;
    for(int i=100; i<1000; i++){
        if(check[i] == 0){
            ans++;
            // cout << " HI : " << i << "\n";
        }
    }
    cout << ans;
}