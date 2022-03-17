#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int N;

int check[30];
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string str;
    cin >> str;

    int i = 0;
    int j = 0;
    int num = 0;

    int idx = str.length();
    int temp = 0;
    int ans = -1;

    check[str[0] - 'a'] = 1;
    num++;
    temp++;

    if(idx == 1){
        cout << 1;
        return 0;
    }

    while(j < idx-1 && i < idx){
        
        j++;

        if ( check[str[j] - 'a'] != 0 ) {
            check[str[j] - 'a']++;
            temp++;        
            
        }
        else if (num < N) {
            check[str[j] - 'a'] = 1;
            temp++;
            
            num++;
        }
        else if (num == N){
            check[str[i] - 'a']--;

            if(check[str[i] - 'a'] == 0 ) num--;
            j--;
            i++;
            temp--;
        }
        // cout << "i , j : " << i << " , " << j << " / temp : " << temp << "\n";
        ans = max(temp, ans);
    }
    
    cout << ans;
}