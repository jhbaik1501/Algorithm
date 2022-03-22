#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = 0x7f7f7f7f;

    if(s.length() == 1 ){
        cout << 1;
        return 0;
    }
    for(int i=1; i <= s.length()/2; i++){

        string tmp = "";
        string str = "";
        tmp = s.substr(0,i);
        
        int cnt = 1;
        
        for(int j=i; j< s.length(); j +=i){
            cout << "tmp : " << tmp << "\n";    
            if(tmp == s.substr(j,i)) cnt++;
            else{
                if(cnt < 2) {
                    str += tmp;
                }
                else{
                    str += to_string(cnt);
                    str += tmp;   
                }
                // cout << "j, j+i" << j << ", "<<j+1;
                cnt = 1;
                tmp = s.substr(j,i);
            }
        }

        if(cnt < 2) {
            str += tmp;
        }
        else{
            str += to_string(cnt);
            str += tmp;   
        }
        cout << str <<"\n";
        int a = str.length();
        ans = min(ans, a);

    }
    cout << ans;

}

/*

5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

*/