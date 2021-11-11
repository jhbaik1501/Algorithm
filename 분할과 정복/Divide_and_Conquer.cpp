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
int sort(int a[], int n)
{
    int h;
    int b[n];
    h = n/2;
    // copy a[] to b[]
    sort(b, h);
    sort(b+h, n-h);
    // Merge two halves in b to a
    return;
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

int Qsort(int a[], int n)
{
    // if <= 5 do selection sort
    // else
    int p = a[0]; //-> pivot
    int i = 1; int j = n -1;
    while(i < j){
        while(a[i] < p && i<n) i++;
        while(a[j] < p) j--;
        if (i < j) swap a[i], a[j];
    }
    swap a[0] and a[j];
    //피봇을 기준으로 앞에는 피봇보다 작고 뒤에는 피봇보다 크도록 설정하는 코드들.
    
    Qsort(a,j); Qsort(a+j+1, n-j-1); // 여기까지 오면서 setup을 해놓았음.
    return;
}

/*
    최악의 경우 O(n^2)
    피봇이 끝에 있는 경우.

    Best Case -> O(nlogn)
*/