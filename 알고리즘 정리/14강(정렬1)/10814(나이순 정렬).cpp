#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

struct client{
    int age;
    int order;
    string name;
};

bool compareObject(client a, client b){
    if(a.age == b.age){
        return a.order < b.order;
    }
    return a.age < b.age;
}
int N;
client arr[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    int age;
    string name;
    for(int i=0; i<N; i++){
        cin >> age;
        cin >> name;
        arr[i] = {age,i,name};
    }

    sort(arr, arr+N, compareObject);

    for(int i=0; i<N; i++){
        cout << arr[i].age << " " << arr[i].name << "\n";
    }
}

/*
3 0
1 2 3
*/