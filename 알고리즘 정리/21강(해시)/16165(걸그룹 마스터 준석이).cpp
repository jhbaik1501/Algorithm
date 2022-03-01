#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    unordered_map<string, vector<string> > map1;
    unordered_map<string, string> map2;
    while(N--){
        string str;
        int num;
        cin >> str;
        cin >> num;
        while(num--){
            string temp;
            cin >> temp;
            map1[str].push_back(temp);
            map2[temp] = str;
        }

        sort(map1[str].begin(), map1[str].end());
        
    }

    while(M--){
        string str;
        int idx;
        cin >> str;
        cin >> idx;
        if(idx == 0){
            for(auto i : map1[str])
                cout << i << "\n";
        }  
        else{
            cout << map2[str] << "\n";
        }
    }
}

