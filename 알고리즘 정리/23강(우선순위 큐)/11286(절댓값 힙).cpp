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

int N;

struct compare2{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        else return abs(a) > abs(b) ;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, compare2> PQ;
    
    cin >> N;
    // cout << "answer \n";
    while(N--){
        int temp;
        cin >> temp;
        if(temp != 0 ){
            PQ.push(temp);
        }
        else{
            if(!PQ.empty()){
                cout << PQ.top() << "\n";
                PQ.pop();
            }
            else{
                cout << 0 << "\n";
            }
        }
    }
    
    

}
