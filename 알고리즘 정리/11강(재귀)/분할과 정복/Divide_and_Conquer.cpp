/*
입력을 나누어,
더 작은 문제를 풀고,
작은 문제들의 답을 조합하여
전체 문제의 답을 만든다
아주 작은 문제는 어쨌든 풀린다.
 
어떻게 나누지????? 
*/

/*Merge Sort*/
/*

n개 (3 5 8 10 15
    (1 2 4 6 9 11

Merge --> 1 2 3 4 5 6 8 10 11 15 
머지는 O(n)시간!

*/
#include <stdio.h>

int sort(int a[], int n)
{
    int h;
    int b[n];
    h = n/2;
    // copy a[] to b[]
    sort(b, h);
    sort(b+h, n-h);
    // Merge two halves in b to a
    return 1;
}

/*
T(n) = 2T(n/2) + n
O(nlogn) -> 굉장히 좋은 sort!

특수한 sort을 제외하고는
(오로지 비교만) 비교말고 다른 것은 못한다고 가정한게 -> Comparison Model
Merge Sort가 가장 빠르다 !
생각보다 별로 안쓰인다. Why? 배열을 추가로 할당해야하기 때문. 메모리가 2배가 된다.
new(), malloc()을 사용해야 하는데, -> 비용이 많이 든다.

그래서 Quick Sort 사용
*/
void swap(int a[], int i, int j){
    
    int temp = a[i]; a[i] = a[j]; a[j] = temp; 

}

int Qsort(int a[], int n)
{
    if(n <= 5){
        int least;
        for (int i =0; i< n-1; i++){
            least= i;

            for(int j = i+1; j<n; j++){
                if(a[j] <a[least])
                    least = j;
            }

            if(i != least){
                swap(a, i, least);
            }
        }

    }

     else{

     
        int p = a[0]; //-> pivot
        int i = 1; int j = n -1;
        while(i < j){
            while(a[i] < p && i<n) i++;
            while(a[j] > p) j--;

            if (i < j) {
                swap(a, i, j);
                i++;
                j--;
            }
            
            
        }
        swap(a, 0, j);
        //피봇을 기준으로 앞에는 피봇보다 작고 뒤에는 피봇보다 크도록 설정하는 코드들.
        
        Qsort(a,j); Qsort(a+j+1, n-j-1); // 여기까지 오면서 setup을 해놓았음.
        return 1;
    }
}


/* 
Quick Sort에서 Median을 찾는 경우 아주 성능이 좋아짐.
-> Median을 찾는 Selection problem
Median을 찾아보자.
Approximate Median Problem


r = 0.3으로 고정.

ㅇㅇㅇㅇㅇ|ㅇㅇㅇㅇㅇ|ㅇㅇㅇㅇㅇ|ㅇㅇㅇㅇㅇ
각자 sort  각자 sort  각자 sort 각자 sort
 ㅇ ㅇ ..ㅇ.. ㅇ ㅇ
 ㅇ ㅇ ..ㅇ.. ㅇ ㅇ
(ㅇ ㅇ ..ㅇ.. ㅇ ㅇ) -> Sorting 했다고 상상. 나머지는 따라서 움직였다. 중간값을 정했다고 상상.
 ㅇ ㅇ ..ㅇ.. ㅇ ㅇ
 ㅇ ㅇ ..ㅇ.. ㅇ ㅇ
 -> 이렇게 되는경우 오른쪽 위 30% 왼쪽 아래 30%

 n개 Approxi.Median - 5개의 그룹, 개별 그룹 sort, O(n)
                    - n/5개에서 Median -> selection 사용.
                    - 끝.
*/




int main(){
    int N;
    scanf("%d", &N);
    int k[1000];
    int a = 0;
    for (int i= 0; i< N; i++){
        scanf("%d", &a);
        k[i]=a;
    }
    
        
    Qsort(k, N);

    for (int i = 0; i<N; i++){
        printf("%d\n", k[i]);
    }
}
/*
    최악의 경우 O(n^2)
    피봇이 끝에 있는 경우.

    Best Case -> O(nlogn)
*/
