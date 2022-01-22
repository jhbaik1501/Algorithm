//두 개의 합

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int check[100] = {0,};

int func2 (int arr[], int N){
    for(int i=0; i< N; i++){
        if(check[100 - arr[i]] == 1){
            cout << "1";
        }
        check[arr[i]] =1;
    }

    cout << "0";
}
int main(){


    int arr[5] = {1,23,53,76,60};
    func2(arr, 5);
}
