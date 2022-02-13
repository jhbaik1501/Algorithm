/*3 9 27 81 243 729 2187 */


#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int arr[2200][2200];
int N;

int ans[3];

void recursive(int x, int y, int size){
    if(size == 1) {
        int tar = arr[x][y];
        if(tar == -1)
            ans[0]++;
        else if(tar == 0)
            ans[1]++;
        else
            ans[2]++;
        return;
    }

    int plus = size / 3;
    for(int i = x; i < (x + size) ; i += plus){
        for (int j = y; j < (y + size) ; j += plus){

            
            int tar = arr[i][j];
            int check = 0;
            for(int m = 0; m < plus; m++){
                for(int n = 0; n < plus; n++){
                    if(arr[i+m][j+n] == tar) continue;
                    check = 1;
                }
            }

            //cout << "i, j : " << i << ", " << j << " // check : " << check << " // plus :" << plus << "\n";

            if(check == 1){
                recursive(i, j, plus);
            }
            else{
                if(tar == -1){
                    ans[0]++;
                }
                else if(tar == 0){
                    ans[1]++;
                }
                else{
                    ans[2]++;
                }
            }

        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    int tar;
    int same = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];

            if(i == 0 && j == 0){
                tar = arr[0][0];
            }

            if(tar != arr[i][j]) same = 0;

        }
    }

    
    if(same){
        ans[tar+1] = 1;
    }
    else{
        recursive(0, 0, N);
    }

    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}
