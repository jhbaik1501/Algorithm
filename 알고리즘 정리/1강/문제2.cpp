#include <stdio.h>
#include <iostream>

int func4(int N){
    int i =1;
    while(i <= N){ i *= 2;}
    printf("%d", i/2);
}

int main(){
    func4(97615282);
}

// 시간 복잡도는 O(log N)