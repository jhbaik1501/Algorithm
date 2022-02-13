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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    stack<int> st;
    int temp;
    for(int i=0; i < N;i++){
        cin >> temp;
        if(temp != 0){
            st.push(temp);
        }
        else{
            st.pop();
        }


        
        
    }

    int ans =0;
    int t = st.size();
    for(int i=0; i<t; i++){
        ans += st.top();
        st.pop();
    }

    cout << ans;
}