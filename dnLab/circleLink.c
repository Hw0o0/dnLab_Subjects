#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
	int data;
	struct NODE* next;
}NODE;
typedef struct NODE* node;

node head = NULL;

int a = 0, b = 0;
int cnt = 0;
void append(node new) {


node temp = head;

	if (head == NULL)
	{
		head = new;
		new->next = head;
		return;
	}
	if (head->data == -1)
	{
		head = new;
		new->next = head;
		return;
	}

	while (temp->next != head) {
		temp = temp->next;
			if (temp->next == head) {
			break;
		}
			
	}
	temp->next = new;
	new->next = head;

	return;
}

void createNode(int data) {

	node  new;
	new = (node)malloc(sizeof(NODE));
	if (new == NULL) {

		printf("노드 생성을 위한 메모리 활당에 문제가 있습니다.");
	}
	new->data = data;
	new->next = NULL;
	append(new);
	return;
}
void printNode() {
	node temp = head;
	int a = 0;
	if (temp == NULL) {
		printf("출력할 노드가 없습니다.\n");
		return;
	}

	if (cnt == 0) {
		if (temp->data < 0) {
			temp->data = -1;
			printf("출력할 노드가 없습니다.\n");
			return;
		}
	}
	else
	{
		for (int a = 0; a < cnt; a++) {
			printf(" %d ", temp->data);
			temp = temp->next;
			if (temp == head) {
				break;
			}
		}
	}
}

int search(int data) {
	int a = 0;
	node temp = head;
	if (temp == NULL) {
		return 0;
	}
	while (temp->next != NULL)
	{
		if (temp->data == data)
		{
			a++;
			return 1;
		}
		temp = temp->next;
		if (temp->data == data)
		{
			a++;
			return 1;
		}
		if (temp->next == head)
		{
			break;
		}
	}
	if (temp->data == data)
	{
		a++;
		return 1;
	}

	if (a == 0) {
		return 0;
	}
}
void delete(int data)

{
	node temp = head;
	node pre = head;
	node sto = head;
	node sto2 = head;

	if (temp == NULL)
	{
		printf("\n삭제할 노드가 없습니다.\n\n");
		return;
	}


	
	while (temp->data != data)
	{//입력한 숫자의 노드
		temp = temp->next;

	}


	while (sto->next !=temp)
	{//입력한 데이터의 뒤의 노드
		sto = sto->next;
	}

	while (sto2->next != sto)
	{ //입력한 숫자의 뒤의 뒤 노드
		sto2 = sto2->next;
	}
	cnt--;
	if (temp == head)   //첫노드 삭제
	{
		head = head->next;
		free(temp);
		sto->next = head;
		if (temp->data < 0) {
			head = sto->next;
		}
		
		return;
	}
	if (temp->next != head) {
		sto->next = temp->next; //중간 노드 삭제
		return;
	}
	if (temp->next == head) {  //끝 노드 삭제
		while (pre->next != temp)
		{
			pre = pre->next;
		}
		pre->next = head;
		return;
	}
	}

int main(void) {
	int input;
	while (1) {
		printf("**************************************\n");
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.종료 *\n");
		printf("**************************************\n");
		puts("");
		printf("실행할 번호를 입력하세요. : ");
		scanf("%d", &input);
		puts("");
		switch (input) {

		case 1: //입력
			while (1) {
				printf("값을 입력하세요. : ");
				scanf("%d", &input);
				if (search(input)) {
					printf("\n중복된 값이 있습니다. \n\n 새로운 ");
				}
				else {
					createNode(input);
					cnt++;
					break;
				}
			}
			break;
		case 2: //출력
			printNode();
			puts("");
			break;
		case 3: //검색
			printf("값을 입력하세요. : ");
			scanf("%d", &input);
			if (search(input)) {
				printf("\n(O)\n\n");
			}
			else {
				printf("\n(X)\n\n");

			}
			break;

		case 4: //삭제
			while (1) {
				printf("삭제할 값을 입력하세요. : ");
				scanf("%d", &input);

				if (search(input)) {
					delete(input);
					break;
				}
				else {
					printf("\n삭제할 노드가 없습니다.\n\n");
				}

			}
			break;

		case 5: //종료
			return 0;
			break;

		case 6:
			printf("디버깅");
			break;


		default:
			printf("잘못된 입력입니다.\n");
			break;

		}
	}
}