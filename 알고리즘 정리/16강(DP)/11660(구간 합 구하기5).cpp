#include <iostream>

using namespace std;

int N,M;
int arr[1030][1030];
int DP[1030][1030];
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            cin >> arr[i][j];
    }


    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==1&&j==1){
                DP[i][j] = arr[i][j];
            }
            else{
                DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + arr[i][j];
            }
            // cout << DP[i][j] << " ";
        }
        // cout << "\n";
    }

    

    while(M--){
        int x1,y1 , x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1] << "\n";
    }
}