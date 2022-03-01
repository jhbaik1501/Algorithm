#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
using namespace std;


int T, N;
int arr[1000010];
int main() {
    string str;
    cin >> str;
    int zero = 0;
    int one = 0;
    for(int i=0; i<str.length(); i++){
        
        
        if(str[i] == '1'){
            one++;
            i++;
            while(str[i] =='1'){
                i++;
            }
            i--;
            continue;
        }
        else{
            zero++;
            while(str[i] =='0'){
                i++;
            }
            i--;
            continue;
        }

        
    }
    // cout << zero << "," << one <<"\n";
    cout << min(zero, one);
}