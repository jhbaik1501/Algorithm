#include <stdio.h>
#include <stdlib.h>

#define __LB_STACK_H__

#define TRUE	1
#define FALSE	0

typedef char Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack
{
	//Node* p; //추가된 내용.
	Node* head;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
	//pstack->p = NULL; //추가
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}

/*
//추가
Data SNext(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}



		pstack->p = pstack->p->next;

		if (pstack->p == NULL) {
			return;
		}

	return pstack->p->data;
}
//추가
Data SFirst(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	pstack->p = pstack->head;

	return pstack->p->data;
}
*/




int main(void)
{
	Stack stack1;
	StackInit(&stack1);

	Stack Rstack1;
	StackInit(&Rstack1);

	Stack stack2;
	StackInit(&stack2);
	

	Stack Rstack2;
	StackInit(&Rstack2);
	char A[25];
	char T[300001];
	int index;

	//스택의 생성 및 초기화

	//printf("검열할 문자를 입력하시오.");
	scanf("%s", A);
	int i = 0;
	int k;
	
	while (A[i] != '\0') {
		i++;
	}
	k = i;
	while (k > 0) {
		SPush(&stack1, A[k-1]);
		k--;
	}
	//검열할 문자를 입력받아 A에 저장하고, stack2에 순서대로 읽기 위해 반대로 넣는다(LIFO구조이기 때문) . 

	//printf("검열당할 문자를 입력하시오.");
	scanf("%s", T);
	int j = 0;
	
	while (T[j] != '\0') {
		j++;
	}
	k = j;
	while (k > 0) {
		SPush(&stack2, T[k-1]);
		k--;
	}
	//검열할 문자를 입력받아 T에 저장하고, stack2에 순서대로 읽기 위해 반대로 넣는다(LIFO구조이기 때문) . 

	char target;
	char want;
	
	
	int left = 1;
	int right = 1;
	int stackindex =0;
	int check = 0;
	//left와 right는 그 검열하려는 문자가 있었는지 없었는지를 저장하는 변수이고, stackindex는 A문자와 T문자에서의 첫번째 이후의 문자 일치하지 않고 Rstack1에서 
	//문자를 빼내야 하는 경우, 다음 문자부터 다시 확인을 해야되기 때문에, Rstack2에 있던 문자들을 Rstack1에서 빼왔던 문자열의 수 -1 만큼 stack2에 다시 넣음.
	//check는 1이라면 문자열이 동일함을 알리고, 0이라면 동일하지 않다는 것을 알리는 변수.
	while (!(left == FALSE && right == FALSE) ) {

		left = FALSE;
		right = FALSE;
	//먼저 이 알고리즘을 시작할 시에, left와 right를 false(0)으로 초기화함.
	
		while (!SIsEmpty(&stack2) && left == FALSE) {
			//만약에 stack2가 비어서 전부 읽었는데 검열할 것이 없거나, 왼쪽에서부터 검열할 대상을 만나 검열되는 경우에는 left가 true가 되기 때문에 이 while문을 나올 수 있음. 
			target = SPop(&stack2);
			SPush(&Rstack2, target);
			
			want = SPop(&stack1);
			SPush(&Rstack1, want);
			
			//stack1, 2에서 뺴서 Rstack1, 2에 넣은 후 그 값을 비교.
			

			if (!SIsEmpty(&stack2)) {
				if (target == want) {

					check = 1;
					//먼저 체크 값을 1로 만듬
					while (!SIsEmpty(&stack1))
					{
						if (SIsEmpty(&stack2))
							break;

						target = SPop(&stack2);
						SPush(&Rstack2, target);

						want = SPop(&stack1);
						SPush(&Rstack1, want);
						//stack1, 2에서 뺴서 Rstack1, 2에 넣은 후 그 값을 비교.
						if (target != want) {
							check = 0;
							break;
						}
						//만약 두개의 값이 다르다면 체크 값을 0으로 만든후 break
						
					}

					if (!SIsEmpty(&stack2) || check == 1) {
						if (SIsEmpty(&stack1) && check == 1)
						{
							for (int a = 0; a < i; a++) {
								SPop(&Rstack2);
								left = TRUE;
								//printf("left\n");
							}
						}//만약에 체크값이 1이라면(꺼낸값들이 전부 동일했다면, 즉 검열할 문자가 발견됬다면) 그만큼 Rstack에서 Pop해서 삭제하고 left값을 1로만듬.
						else
						{
							while (!SIsEmpty(&Rstack1)) {
								SPush(&stack1, SPop(&Rstack1));
								stackindex++;
							}

							for (int a = 0; a < stackindex - 1; a++) {
								SPush(&stack2, SPop(&Rstack2));
							}
							//만약 검열할 문자가 발견되지 않고 취소 됬다면, 다시 stack1, 2를 되돌려놓음.
							//stack2는 Rstack2에서 문자 한개는 덜 빼냄(한 문자는 확인하였으니, 그 다음 문자부터 확인하기 위해)
							stackindex = 0;
						}
					}
				}
			}



			while (!SIsEmpty(&Rstack1))
				SPush(&stack1, SPop(&Rstack1));
			//Rstack1을 비움.

		}

		
		if (left != TRUE) break;
		//만약에 왼쪽에서부터 검열할 문자를 찾았는데 없다면 이 while문을 나감.

		//오른쪽!!!!
		while (!SIsEmpty(&stack2))
			SPush(&Rstack2, SPop(&stack2));
		while (!SIsEmpty(&stack1))
			SPush(&Rstack1, SPop(&stack1));
		//이제 오른쪽에서 부터 확인하기 위하여, stack1, 2에 들어있던 값들을 Rstack1, 2에 넣어 반대로 확인하는 절차를 실행.

		check = 0;

		//왼쪽에서부터 확인한 방식과 똑같게 하여(Rstack1과 stack1의 위치, Rstack2와 stack2의 위치만 바뀐채로) 실행함.
		//(Rstack1,2와 stack1,2의 위치를 제외하고는 위와 같은 방식이기 때문에 주석은 생략하였습니다.)
		while (!SIsEmpty(&Rstack2) && right == FALSE) {
			

			target = SPop(&Rstack2);
			SPush(&stack2, target);

			want = SPop(&Rstack1);
			SPush(&stack1, want);

			

			if (!SIsEmpty(&Rstack2)) {
				if (target == want) {
					check = 1;

					while (!SIsEmpty(&Rstack1))
					{
						if (SIsEmpty(&Rstack2))
							break;

						target = SPop(&Rstack2);
						SPush(&stack2, target);

						want = SPop(&Rstack1);
						SPush(&stack1, want);

						if (target != want) {
							check = 0;
							break;
						}

					}

					if (!SIsEmpty(&Rstack2) || check == 1) {
						if (SIsEmpty(&Rstack1) && check == 1)
						{
							for (int a = 0; a < i; a++) {
								SPop(&stack2);
								right = TRUE;
								//printf("right\n");
							}
						}
						else
						{
							while (!SIsEmpty(&stack1)) {
								SPush(&Rstack1, SPop(&stack1));
								stackindex++;
							}

							for (int a = 0; a < stackindex - 1; a++) {
								SPush(&Rstack2, SPop(&stack2));
							}

							stackindex = 0;
						}
					}
				}
			}



			while (!SIsEmpty(&stack1))
				SPush(&Rstack1, SPop(&stack1));



		}


		while (!SIsEmpty(&Rstack2))
			SPush(&stack2, SPop(&Rstack2));
		while (!SIsEmpty(&Rstack1))
			SPush(&stack1, SPop(&Rstack1));
		
		//이제 왼쪽에서 부터 확인하기 위하여, Rstack1, 2에 들어있던 값들을 stack1, 2에 넣어 반대로 확인하는 절차를 실행.

		if (right != TRUE) break;
		//만약에 오른쪽에서부터 검열할 문자를 찾았는데 없다면 이 while문을 나감
	}
	
	
	while (!SIsEmpty(&Rstack2))
		SPush(&stack2, SPop(&Rstack2));
	//Rstack2가 비어있지 않다면 stack2에 채움(정방향으로 읽기 위해서)

	
	while (!SIsEmpty(&stack2))
		printf("%c", SPop(&stack2));
	//문자를 읽음.

	return 0;
}