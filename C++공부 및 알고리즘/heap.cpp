#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


/* �켱���� ť ����*/
/* ������ ���� �θ�*/
class PQ {
public :
	PQ();
	void Insert(pair <int, int> a);
	pair <int, int> Delete();

	pair <int, int> Arr[1000];
	int cnt;
};

PQ::PQ(){
	cnt = 0;
}

void PQ::Insert(pair <int, int> a) {
	int i;
	pair <int, int> temp;

	Arr[++cnt] = a;
	i = cnt;
	while (i > 1) {
		if (Arr[i].second < Arr[i / 2].second) { // ������ �ִ� ���
			temp = Arr[i]; Arr[i] = Arr[i / 2]; Arr[i / 2] = temp; // ��ȯ
			i /= 2;
		}
		else
			break;
	}
}

pair <int, int> PQ::Delete(void) {

	pair <int, int> ret, temp;
	int i;
	ret = Arr[1];
	Arr[1] = Arr[cnt]; // �������� �ִ� ���Ҹ� 1������ �ű�.
	if (cnt == 1) {
		cnt = 0;
	}
	else {
		Arr[1] = Arr[cnt]; cnt--;
		i = 1;
		while (true) {
			if (cnt >= i * 2 + 1) { // child�� �� �� �ִ�.
				if (Arr[i].second > Arr[i * 2].second || Arr[i].second > Arr[i * 2 + 1].second) { //������ ���� ���
					if (Arr[i].second < Arr[i*2 +1].second) { // ������ ���� ��� (���� �� �÷�����)
						temp = Arr[i]; Arr[i] = Arr[i * 2]; Arr[i * 2] = temp;
						i = i * 2;
					}
					else {
						temp = Arr[i]; Arr[i] = Arr[i * 2 +1]; Arr[i * 2 +1] = temp;
						i = i * 2 +1;
					}
				}
			}
			else if (cnt == i * 2) { //child ���� ��常 �ִ� ���
				if (Arr[i].second > Arr[i * 2].second) { // ������ ���� ���
					temp = Arr[i]; Arr[i] = Arr[i * 2]; Arr[i * 2] = temp;
				}
				else {
					break;
				}
			}
			else { //�ƹ��͵� ���� ���. �̻��� ȥ�� �ִ°��.
				break;
			}
		}
	}

	return ret;
}

int main() 
{
	PQ Q;
	pair <int, int> temp, temp2;
	vector <pair <int, int>> Edge[1000];
	int Mark[1000];
	int Out[1000]; 
	int oi;
	int n, m, i,j, a, b, w;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		temp.first = b; temp.second = w;
		Edge[a].push_back(temp);
		temp.first = a; temp.second = w;
		Edge[b].push_back(temp);

	}
	
	for (i = 1; i <= n; i++) Mark[i] = 0;
	Mark[1] = 1;
	for (j = 0; j < Edge[1].size(); j++) {
		temp.first = Edge[1][j].first; temp.second = Edge[1][j].second;
		Q.Insert(temp);
	}
	oi = 1; 

	while (oi < n) {
		temp = Q.Delete();
		//printf("temp : %d %d", temp.first, temp.second);
		
		if (Mark[temp.first] == 0) {
			Out[oi++] = temp.second;
			Mark[temp.first] = 1;
			for (j = 0; j < Edge[temp.first].size(); j++) {
				temp2.first = Edge[temp.first][j].first; temp2.second = Edge[temp.first][j].second;
				Q.Insert(temp2);
			}
			
		}
	}


	for(i =1; i< oi; i++){
		printf("%d ", Out[i]);
	}
	
	

	return 0;
}
/*
4 5
1 2 3
2 3 2
3 4 4
4 1 1
2 4 5
*/

/*
5 10
1 2 10
1 4 5
1 5 6
2 3 1
2 4 3
2 4 4
3 4 2
3 5 4
3 5 6
4 5 2
*/