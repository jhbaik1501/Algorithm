//두 개의 합

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int check[10] = {};

int min(int a1, int a2){
    if (a1 > a2)
        return 9;
    else 
        return 6;
}

int max(int a1[]){
    int k =0;
    for (int i=0; i< 10; i++){
        if (k < a1[i]){
            k = a1[i];
        }
    }
    return k;
}

int main(){

    string s;
    cin >> s;
    for (int i =0; i< s.length(); i++){
        int k = s[i] -'0';
        if(k == 6 || k == 9){
            if (min(check[6], check[9]) == 6){
                check[6]++;
            }
            else{
                check[9]++;
            }
        }
        else{
            check[k]++;
        }
    }
    cout << max(check);
}
