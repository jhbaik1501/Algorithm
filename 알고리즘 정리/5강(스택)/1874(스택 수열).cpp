#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

int N;
int arr[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    string str;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    stack <int> S;
    S.push(1);
    str.append("+");
    int index=0;
    int i =2;
    while(i <= N+1){ //비지 않았거나 i의 값이 N보다 작거나 같은경우.

        // cout << S.top() << ", "<< arr[index] << "\n";
        if(!S.empty() && S.top() == arr[index]){
            S.pop();
            str.append("-");
            index++;
        }
        else {
            S.push(i);
            i++;
            if(i > N+1) break;
            str.append("+");
        }
        // else{
        //     S.pop();
        //     str.append("-\n");
        //     i--
        // }
    }
    //  cout << "index : "<<index; 
    if(index != N){
        cout << "NO";
    }
    else{
        for(int i=0; i< str.size(); i++)
            cout << str[i] << "\n";
    }
}