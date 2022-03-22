#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
#define INF 987654321

struct QD{
    int a, b, w, d; // a -> b로 가는 엣지, 엣지의 무게는 w, 소스로부터의 거리 d.
};




class PQ {
public :
	PQ();
	void Insert(QD x);
	QD Delete();

	QD Arr[300000];
	int cnt;
};

PQ::PQ(){
	cnt = 0;
}

void PQ::Insert(QD x) {
	int i;
	QD temp;

	Arr[++cnt] = x;
	i = cnt;
	while (i > 1) {
		if (Arr[i].d < Arr[i / 2].d) { // ������ �ִ� ���
			temp = Arr[i]; Arr[i] = Arr[i / 2]; Arr[i / 2] = temp; // ��ȯ
			i /= 2;
		}
		else
			break;
	}
}

QD PQ::Delete(void) {

	QD ret, temp;
	int i;
	if (cnt == 0){
		ret = {-1,-1,-1,-1};
		return ret;
	}
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
				if (Arr[i].d > Arr[i * 2].d || Arr[i].d > Arr[i * 2 + 1].d) { //������ ���� ���
					if (Arr[i*2].d < Arr[i*2 +1].d) { // ������ ���� ��� (���� �� �÷�����)
						temp = Arr[i]; Arr[i] = Arr[i * 2]; Arr[i * 2] = temp;
						i = i * 2;
					}
					else {
						temp = Arr[i]; Arr[i] = Arr[i * 2 +1]; Arr[i * 2 +1] = temp;
						i = i * 2 +1;
					}
				}
                else{
                    break;
                }
			}
			else if (cnt == i * 2) { //child ���� ��常 �ִ� ���
				if (Arr[i].d > Arr[i * 2].d) { // ������ ���� ���
					temp = Arr[i]; Arr[i] = Arr[i * 2]; Arr[i * 2] = temp;
                    i = i*2;
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




int Shortest(vector <pair <int,int>> Edge[], int start, int n, int where){
	
	QD t1, t2;
	PQ Q;
	int Mark[300000];
	Mark[where] = INF;
	int i, j, oi;
	for (i = 1; i <= n; i++) Mark[i] = INF; //1000000 = infinity
	Mark[start] = 0;
	for (j = 0; j < Edge[start].size(); j++) {
		t1.a = start;
		t1.b = Edge[start][j].first; 
		t1.w = Edge[start][j].second;
		t1.d = Mark[start] + Edge[start][j].second;
		Q.Insert(t1);
	}
	oi = 1; // how much finalized

	while (oi < n) {
		t1 = Q.Delete(); // a b w d
		if (t1.a == -1){
			return Mark[where];
		}
		
		if (Mark[t1.b] == INF) { //1000000이 아니면 이미 finalized 된 것.

			//printf("%d ", t1.b);
			oi++;
			Mark[t1.b] = t1.d;
			for (j = 0; j < Edge[t1.b].size(); j++) {
				t2.a = t1.b;
				t2.b = Edge[t1.b][j].first;
				t2.w = Edge[t1.b][j].second;
				t2.d = Mark[t1.b] + Edge[t1.b][j].second;
				
				Q.Insert(t2);
			}
			
		}
	}

	return Mark[where];

}


int main() 
{
	PQ Q;
    pair <int,int> temp;
	QD t1, t2;
	vector <pair <int,int>> Edge[300000];
	int n, m, i, j, s, t, w, start, m1, m2;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &t, &w);
		temp.first = t; temp.second = w;
		Edge[s].push_back(temp);
		temp.first = s; temp.second = w;
		Edge[t].push_back(temp);

	}
	scanf("%d %d", &m1, &m2);
	
	
	int a1= Shortest(Edge, 1, n, m1);
	int a2= Shortest(Edge, m1, n, m2);
	int a3= Shortest(Edge, m2, n, n);

	//printf("%d %d %d", a1, a2, a3);
	int b1 =Shortest(Edge, 1, n, m2);
	int b3 =Shortest(Edge, m1, n, n);

	int is_possible = 0;
	if (a1 == INF || a2 == INF || a3 == INF){
		is_possible = 1;
	}
	if (b1 == INF || a2 == INF || b3 == INF){
		is_possible = 1;
	}


	a1 = a1 + a2 + a3;
	a2 = b1 + a2 + b3;
	
	if(is_possible){
		printf("-1");
	}
	else if (a1 > a2){
		printf("%d", a2);
	}
	else {
		printf("%d", a1);
	}

	
	

	return 0;
}
