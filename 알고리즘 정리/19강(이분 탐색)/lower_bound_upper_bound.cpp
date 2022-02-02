//lower_bound
//n개로 이루어진 정수 집합에서 원하는 수 k 이상인 수가 처음으로 등장하는 위치를 찾으시오
 
#include<iostream>
using namespace std;
 
int mylower_bound(int * arr, int n, int key){
    int start = 0;
    int end = n;
    
    int mid;
    while(end- start >0){

        mid = (start + end) /2;
        if(arr[mid] < key){
            start = mid +1;
        }
        else {
            end = mid;
        }

    }
    return end + 1;
}

int myupper_bound(int * arr, int n , int key){
    int start = 0;
    int end = n;
    int mid;
    while(end - start > 0){
        mid = (start + end) /2;
        if(arr[mid] <= key){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    return end + 1;
}

 
int main(void){
    int arr[10] = {1, 2, 4, 5, 6, 6, 7, 7, 7, 9};
 
    cout << "lower_bound(6) : " << mylower_bound(arr, 10, 6) << endl;
    cout << "lower_bound(7) : " << mylower_bound(arr, 10, 7) << endl;
    cout << "upper_bound(7) : " << myupper_bound(arr, 10, 7) << endl;
    cout << "lower_bound(8) : " << mylower_bound(arr, 10, 8) << endl;
    cout << "lower_bound(9) : " << mylower_bound(arr, 10, 9) << endl;
    return 0;
}


