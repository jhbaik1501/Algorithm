#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int inning;
vector<int> player[9];
int ans;
void max_score(){



    ans += ;
}

int main(){
    cin >> inning;
    while(inning--){
        for(int i=0; i<9;i++){
            int temp;
            cin >> temp;
            player[i].push_back(temp);
        }
        max_score();
    }
}