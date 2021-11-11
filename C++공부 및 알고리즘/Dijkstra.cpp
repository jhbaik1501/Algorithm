/* Shortest Path */
/* Dijkstra Algorithm 
 소스에서 다른 모든 노드들로 가는 모든 패스들 중의 최소  
 Shortest Path의 모든 부분은 Shortest Path이다.
 타겟으로 가는 Shortest Path를 찾으면 굉장히 많은 노드들의 Shortest Path를 찾는 것.
 하나의 노드의 Shortest Path를 찾는 것과 모든 노드의 Shortest Path를 찾는 것은 다른 것이 아니다.
 
 Dijkstra Algorithm (G(V,E), n, v0(소스), dmin(답출력))
 
 dmin (v)<- g(v0, u)
 바로 가는 엣지가 없는 경우 -> 무한대
 g(v0, v0) = 0
 
 Red : dmin(v)가 최종 정답.
 Blue : dmin(v)는 Red set만 거치는 Shortest Path의 길이
 파란 숫자 중 가장 작은 값은 정답이다.

 O(mlogn)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct QD{
    int a, b, w, d; // a -> b로 가는 엣지, 엣지의 무게는 w, 소스로부터의 거리 d.
};

class PQ {
public :
	PQ();
	void Insert(QD x);
	QD Delete();

	QD Arr[1000];
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

int main() 
{
	PQ Q;
    pair <int,int> temp;
	QD t1, t2;
	vector <pair <int,int>> Edge[1000];
	int Mark[1000]; // = distance 
	int Out[1000]; 
	int oi;
	int n, m, i,j, s, t, w;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &t, &w);
		temp.first = t; temp.second = w;
		Edge[s].push_back(temp);
		temp.first = s; temp.second = w;
		Edge[t].push_back(temp);

	}
	
	for (i = 1; i <= n; i++) Mark[i] = 1000000; //1000000 = infinity
	Mark[1] = 0;
	for (j = 0; j < Edge[1].size(); j++) {
        t1.a = 1;
		t1.b = Edge[1][j].first; 
        t1.w = Edge[1][j].second;
        t1.d = Mark[1] + Edge[1][j].second;
		Q.Insert(t1);
	}
	oi = 1; // how much finalized

	while (oi < n) {
		t1 = Q.Delete(); // a b w d
		
		
		if (Mark[t1.b] == 1000000) { //1000000이 아니면 이미 finalized 된 것.

            printf("%d ", t1.b);
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

    printf("\n\n\n\n\n");
    
	for(i =1; i <= n; i++){
		printf("%d ", Mark[i]);
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