//lower_bound
//n개로 이루어진 정수 집합에서 원하는 수 k 이상인 수가 처음으로 등장하는 위치를 찾으시오
#include<algorithm>
#include<iostream>
using namespace std;
 
int mylower_bound(int * arr1, int * arr2, int key){
    int size = arr2 - arr1;
    
    int st = 0;
    int en = size;
    int mid;
    while(en > st){
        mid = (st + en) / 2;

        if(key > arr1[mid]){
            st = mid + 1;
        }
        else{
            en = mid;
        }
    }

    return st;
}


int myupper_bound(int * arr1, int * arr2, int key){
    int size = arr2 - arr1;
    
    int st = 0;
    int en = size;
    int mid;
    while(en > st){
        mid = (st + en) / 2;

        if(key >= arr1[mid]){
            st = mid + 1;
        }
        else{
            en = mid;
        }
    }

    return st;
}

int main(void){
    int arr[10] = {1, 2, 4, 5, 6, 6, 7, 7, 7, 9};
    int n= 10;
    cout << mylower_bound(arr, arr+n, 6);
    cout << myupper_bound(arr, arr+n, 6);
}


