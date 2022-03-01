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
int arr[30];
int main(){
    // cout.unsetf(ios::fixed);
    
    cin >> N;
    string str;
    cin >> str;
    stack<double> S;
    
    for(int i=0; i<N+1; i++){
        cin >> arr[i];
        // cout << "arr : "<<arr[i];
    }

    

    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            S.push(arr[str[i] - 'A']);
            // cout << "arr2 : " << arr[str[i] - 'A'] << "\n";
        }    
        else{
            double temp1 = S.top();
            S.pop();
            double temp2 = S.top();
            S.pop();
            if(str[i] == '+'){
                
                S.push(temp1 + temp2);
            }
            else if(str[i] == '-'){
                S.push(temp2 - temp1);
            }
            else if(str[i] == '/'){
                //  cout << "tmp : " << temp1 << ", "<< temp2 << "\n";
                S.push(temp2 / temp1);
            }
            else{
                //  cout << "tmp : " << temp1 << ", "<< temp2 << "\n";
                S.push(temp1 * temp2);
            }
            // cout << "S.top = "<<S.top() << "\n";
        }
    }

    printf("%.2f", S.top());
    // cout << S.top();
}