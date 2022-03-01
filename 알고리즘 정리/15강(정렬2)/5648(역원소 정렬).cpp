#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<long long> arr;

long long reverse(string str){

    string temp;
    for(int i=0; i<str.length(); i++){
        temp[i] = str[str.length() - i -1];
    }
    // cout << "temp : " << stoi(temp) ;
    
    return stoll(temp);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // string s = "1230";
    // cout << "reverse : " << reverse(s);

    cin >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        // auto temp = reverse(str);
        arr.push_back(stoll(str));
    }   

    sort(arr.begin(), arr.end());
    for(int i=0; i<N; i++){
        cout << arr[i] << "\n";
    }
}

