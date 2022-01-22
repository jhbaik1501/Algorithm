#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class PQ{
public:
	PQ();
	int Arr[300000];
	void Insert(int num);
	int Delete(void);
	int cnt;
};

PQ::PQ(){
	Arr[0] = 0;
	cnt = 0;
}
void PQ::Insert(int num){
	cnt++;
	int i = cnt;
	int temp = 0;
	if (i == 1){
		Arr[1] = num;
	}
	else
	{
		Arr[i] = num;
		while(true){
			if (i == 1)
				break;
			else if (Arr[i/2] < Arr[i]){
				
				temp = Arr[i/2]; Arr[i/2] = num; Arr[i] = temp;
				i /= 2;
			}
			else{
				break;
			}

		}
		
	}
}

int PQ::Delete(){
	int ret = Arr[1];
	Arr[1]= Arr[cnt];
	cnt--;
	int i = 1;
	int temp = 1;
	if (cnt == -1){
		cnt++;
		return 0;
	}
	if (cnt == 0){
		return ret;
	}
	else {
		while (true){
			
			if (cnt >= i*2 +1){
				if (Arr[i*2] > Arr[i] || Arr[i*2+1] > Arr[i]){
					if(Arr[i*2] > Arr[i*2+1]){
						temp =Arr[i*2]; Arr[i*2] = Arr[i]; Arr[i] = temp;
						i *= 2;
					}
					else{
						temp =Arr[i*2+1]; Arr[i*2+1] = Arr[i]; Arr[i] = temp;
						i = i*2 +1;
					}
				}
				else{
					break;
				}
				
			}
			else if(cnt == i*2){
				
				if (Arr[i*2] > Arr[i]){
					temp =Arr[i*2]; Arr[i*2] = Arr[i]; Arr[i] = temp;
				}
				else{
					break;
				}
			}

			else{ 
				break;
			}
		}

		return ret;
	}
}

int main(){
	PQ pq;
	int N;
	scanf("%d", &N);
	int k;
	for (int i =0; i< N; i++){
		scanf("%d", &k);
		if (k == 0){
			printf("%d\n", pq.Delete());
		}
		else{
			pq.Insert(k);	
		}
		
	}
	
}