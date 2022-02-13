/*2 4 8 16 32 64 */


#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N;
int arr[65][65];


void recursive(int x, int y, int size){

    //cout << "size : " << size << "\n";

    if(size == 1) {
        
        cout << arr[x][y]; 
        return;
    }

    cout << "(";
    int plus = size/2;
    for(int i = x; i < (x + size); i += plus){
        for(int j = y; j < (y + size); j += plus){
            int tar = arr[i][j];
            int check = 0;

            for(int m =0; m < plus; m++){
                for(int n=0; n <plus; n++){
                    if(tar == arr[i+m][j+n]) continue;
                    check = 1; //만약 다른 경우라면 체크를 1 
                }
            }
            
            if(check == 1){
                recursive(i,j, plus);
            }
            else{
                cout << tar;
            }


        }
    }

    cout << ")";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i =0; i< N; i++){
        string str;
        cin >> str;
        for(int j=0; j<N; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    int tar = arr[0][0];
    int same = 1;
    for(int i =0; i< N; i++){
        for(int j=0; j<N; j++){
            if(tar != arr[i][j]) same = 0;
        }
        
    }

    if(same){
        cout << tar;
    }
    else{
        recursive(0, 0, N);    
    }

    

}
