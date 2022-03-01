#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;



int arr[28][3];
int N;

void recursive1(int n){
    
    if(n == 0) return;

    int l = arr[n][0];
    int r = arr[n][1];
    char temp = n +'A' -1;
    cout << temp;
    recursive1(l);
    recursive1(r);
}

void recursive2(int n){
    
    if(n == 0) return;

    int l = arr[n][0];
    int r = arr[n][1];
    char temp = n +'A' -1;
    
    recursive2(l);
    cout << temp;
    recursive2(r);
}

void recursive3(int n){
    
    if(n == 0) return;

    int l = arr[n][0];
    int r = arr[n][1];
    char temp = n +'A' -1;
    
    recursive3(l);
    recursive3(r);
    cout << temp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    while(N--){
        char a1,b1,c1;
        cin >> a1 >> b1 >> c1; 
        

        int a = a1 - 'A' + 1;
        int b, c;
        if(b1!='.') b = b1 - 'A' +1;
        else b=0;
        if(c1!='.') c = c1 - 'A' + 1;
        else c=0;
        arr[a][0] = b;
        arr[a][1] = c;

        // cout << "a : " << a  << arr[a][0] << " "<< arr[a][1] << '\n';
    }

    recursive1(1);
    cout << "\n";
    recursive2(1);
    cout << "\n";
    recursive3(1);
}