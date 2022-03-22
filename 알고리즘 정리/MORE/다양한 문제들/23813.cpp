#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;


long long N;

int arr[10];

int pow(int n, int m){
    int ret = 1;
    for(int i=0; i<m;i++){
        ret *= n;
    }
    return ret;
}

int main(){
    string s;
    cin >> s;
    vector<int> v;
    long long answer = 0;
    for(int i=0; i<s.length(); i++){
        v.push_back(s[i] - '0');
    }
    for(int i = s.length(); i>0; i--){
        
        int temp = v.back();
        v.pop_back();
        v.insert(v.begin(), temp);

        for(int j =0; j< v.size(); j++){
            int m = v.size() - j -1;

            answer += v[j] * pow(10,m);
            //cout << "k" << k <<" "<< m<<"\n" ;
            //answer += k;
        }
        //cout << "\n";
    }

    cout << answer;
}