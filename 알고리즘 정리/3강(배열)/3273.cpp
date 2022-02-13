#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

int n;
int arr[2000001];
int x;

int main(){
    cin >> n;

    int temp;
    for(int i=0; i < n; i++){
        cin >> temp;
        arr[temp] =1 ;
    }
    cin >> x;

    int ans = 0;
    if(x % 2 == 0){
        for(int i=0; i< x/2; i++){
            if(arr[i] == 1){
                
                if(arr[x-i] == 1)
                    ans++;
            }
        }
    }
    else{
        for(int i=0; i<= x/2; i++){
            if(arr[i] == 1){
                
                if(arr[x-i] == 1)
                    ans++;
            }
        }
    }

    cout << ans;
}