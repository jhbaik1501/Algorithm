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
    cout.tie(0);
    
    stack<pair<int,int>> s;
    cin >> N;

    int temp;
    
    long long int num = 0;
    long long int sum = 0;
    for(int i=0;i<N;i++){
        cin >> temp;
        num = 0;
        while(!s.empty() && s.top().first <= temp){
            num += s.top().second;
            sum += num;
            cout << temp << "s.t.s "<<s.top().second << "\n";
            s.pop();
            
        }
        if(s.empty()){       
            s.push({temp, 0});
        }
        else{
            pair<int,int> p = s.top();
            s.pop();
            if(num != 0)
                p.second += num;
            else
                p.second++;
            s.push(p);
            s.push({temp, 0});
        }
    }

    num = 0;
    while (!s.empty())
    {
        num += s.top().second;   
        sum += num;
        s.pop();
    }
    

    cout << sum;
}