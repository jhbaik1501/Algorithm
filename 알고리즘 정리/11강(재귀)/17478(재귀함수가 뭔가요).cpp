/* �ŵ� ���� ��͹��� */

/* 1���� ����� �� �ִ�.
k���� ��������� 2k�°� 2k+1�µ� O(1)�� ����� �� �ִ�.*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N;

void recursive(int depth){
    if(depth == N) {
        for(int i=0; i<depth; i++) cout << "____";
        cout << "\"����Լ��� ������?\"\n";
        for(int i=0; i<depth; i++) cout << "____";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for(int i=0; i<depth; i++) cout << "____";
        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    for(int i=0; i<depth; i++) cout << "____";
    cout << "\"����Լ��� ������?\"\n";
    for(int i=0; i<depth; i++) cout << "____";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for(int i=0; i<depth; i++) cout << "____";
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for(int i=0; i<depth; i++) cout << "____";
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    recursive(depth+1);
    for(int i=0; i<depth; i++) cout << "____";
    cout << "��� �亯�Ͽ���.\n";

}

int main(){
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursive(0);
}
