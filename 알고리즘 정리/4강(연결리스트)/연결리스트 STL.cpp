//두 개의 합

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>

using namespace std;


int main(){
    
    //선언
    list<int> List = {11,22,33};

    //맨 앞,맨 뒤 추가.
    List.push_front(20);
    List.push_back(10);
    
    //맨 앞,맨 뒤 삭제.
    List.pop_front();
    List.pop_back();
    
    //커서(포인터의 위치) 앞, 뒤 만들기
    auto cursor = List.begin(); // 오토형 사용, 원래는 list<int>::iterator cursor와 동일
    cursor = List.end();
    
    //커서 위치 이동
    cursor++; cursor--; // 한 칸 뒤로, 한 칸 앞으로

    //커서 위치에 요소 추가 및 삭제
    List.insert(cursor, 3);
    cursor--;
    cursor = List.erase(cursor); // 중요 ! 삭제 후 cursor 값에 다시 넣어줘야함.
    List.insert(cursor, 3);

    //리스트의 모든 요소 출력
    for(auto iter = List.begin(); iter != List.end(); iter++){
        cout << *iter << " ";
    }
}
