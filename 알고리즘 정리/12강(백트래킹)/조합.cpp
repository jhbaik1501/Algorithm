#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int arr[8] = {2,3,4,5,6,7,8,9};
    int temp[8] = {0,0,0,0,0,0,1,1};

    do{
        for(int i=0; i< 8; i++){
            if(temp[i] == 0){
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    } while(next_permutation(temp, temp+8));

    cout << "\n";


    vector<int> v{ 1, 2, 3};
 
    sort(v.begin(), v.end());
 
    do {
        for (auto it = v.begin(); it != v.end(); ++it)
            cout << *it << ' ';
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));

    unordered_set<int> set;
    set.insert(3);
    set.insert(5);
    set.insert(9);
    // set.insert(111);

    if(set.find(5) != set.end()){
        cout << " 5 !" << "\n";
    }

    if(set.find(111) == set.end()){
        cout << " 111 !" << "\n";
    }
}