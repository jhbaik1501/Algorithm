/* 에라토스테네스의 체 이용 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, d, k, c;

int arr[30010];
int check[3010];
int main(){
    
    cin >> N >> d >> k >> c;
    for(int i=0; i< N; i++){
        cin >> arr[i];
    }

    int rotate =0;
    int i=0, j=0;
    int conti = 1;
    check[arr[0]] =1;
    int ans = 1;
    int out = 0;
    int coupon = 0;
    while(rotate <=2){

        if(j >= N) {j=0; rotate++;}
        if(i >= N) {i=0; break;}
        //만약 크면 0으로

        if(conti < k){
            j++;
            if(j >= N) {j=0; rotate++;}

            if(check[arr[j]] == 0){
                ans++;  
            }
            
            // if(arr[j] == c && check[arr[j]] == 0){
            //     k++;
            // }
            // //쿠폰번호 우대 , 만약 쿠폰번호가 아니거나, 쿠폰번호를 사용한 경우는 conti ++:
            check[arr[j]]++;
            conti++;
            
            
            
        } 
        else{

            
            if(check[c] == 0){
                out = max(ans+1, out);
                // cout << "i, j : " << i << ", " << j << " ans : "<< ans+1 << " conti : "<< conti <<"\n";
            }
            else{
                out = max(ans, out);
                // cout << "i, j : " << i << ", " << j << " ans : "<< ans << " conti : "<< conti <<"\n";
            }
            
            check[arr[i]]--;
            conti--;

            if(check[arr[i]] == 0){
                ans--;
            }
            
            i++;
            
        } 
    }

    cout << out;
}