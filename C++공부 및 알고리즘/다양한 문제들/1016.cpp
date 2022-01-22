#include <stdio.h>
#include <iostream>

int main(){
    int min, max;
    scanf("%d %d", &min, &max);

    
    
    int check[1000000] = {0,};
    
    for(int i = 2; i< 1000000; i++){
        int k = i*i;
        if (check[k] == 0){
            for(int j = k ; j < max; j += k){
                check[j] = 1;
            }
        }
    }

    int index = 0;
    for(int i = min; i < max+1; i++){
        //몫 * 제곱수 부터 시작.
        // 101 201
        // i/4, i/9, i/16, i/25 ... i/
        // 26 * 4 -> check[3]번 자리., 27 * 4 -> [7]번 자리, 28 * 4 .. 지움. 3 7 11 15 19 ...
        // 4로 나눴을때 몫 25, 100 + 4 = 104, 104 - 101 = [3]
        // 100 + 8 = 108, 108 - 101= [7]
        // 9로 나눴을때 몫 11, 99 + 9 = 108, 108 - 101 = 7

        //...
        // 100로 나눴을때 몫 1, 100 + 100 = 200, 200- 101 = check[99]를 1로.
        //                              이 200이라는 수가 max보다 큰 경우는 나간다.
        
        sqrt(i);
        if (check[i] == 0){
        //    printf("i = %d ", i);
            index++;
        }
    }

    printf("%d", index);
}