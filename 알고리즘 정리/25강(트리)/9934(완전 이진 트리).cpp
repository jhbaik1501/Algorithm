#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <list>

using namespace std;
int K;
int Tree[1030][3];
int arr[1030];

vector<int> V[1030];
void recursive(int depth, int idx){

    if(depth == 1) return;

    int temp = pow(2, depth -2);
    V[K - depth + 1].push_back(arr[idx - temp]);
    V[K - depth + 1].push_back(arr[idx + temp]);
    // cout << arr[idx - temp] << " "<< arr[idx + temp]<< "\n";
    recursive(depth-1, idx - temp);
    recursive(depth-1, idx + temp);
}

int main() {
    cin >> K;
    // cout << "pow : " << pow(2,K) << "\n"; 
    for(int i=1; i< pow(2, K)  ; i++){
        cin >> arr[i]; 
    }
    int temp = pow(2, K) / 2;
    V[0].push_back(arr[temp]);
    recursive(K, pow(2, K) / 2);

    for(int i=0; i< K; i++){
        for(auto k : V[i]){
            cout << k << " ";
        }
        cout << "\n";
    }
}