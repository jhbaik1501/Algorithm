#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[26] = {0,};
int main(){
    string S;
    cin >> S;
    int k = 0;
    for(int i =0; i< S.length(); i++){
        
        k = S[i] - 'a';
        arr[k]++;
    }
    
    for(int i=0; i< 26; i++)
        cout << arr[i] << " ";
}
