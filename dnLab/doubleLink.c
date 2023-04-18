#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
	int data;
	struct NODE* pre;
	struct NODE* next;
}NODE;
typedef struct NODE* node;

node head = NULL;
int cnt = 0;

void append(node new) {

	node temp = head;
	node temp2 = head;
	if (head == NULL)
	{
		head = new;
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	} 
	temp->next = new;
	new->pre = temp;
	return;
}



void createNode(int data) {
	node  new;
	new = (node)malloc(sizeof(NODE));
	if (new == NULL) {
		printf("노드 생성을 위한 메모리 활당에 문제가 있습니다.");
	}
	new->pre = NULL;
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
		}
		else {
			while (temp->next != NULL) 
			{
	
				printf("%d ", temp->data);
				temp = temp->next;
				if (temp->next == NULL) 
				{
					printf("%d", temp->data);
				}
				a++;
			} 
			puts("");
			while (temp->pre != NULL)
			{

				printf("%d ", temp->data);
				temp = temp->pre;
				if (temp->pre == NULL)
				{
					printf("%d", temp->data);
				}
				a++;
			}
			if (a == 0)
			{
				if (temp->data >= 0)
				{
					printf("%d", temp->data);
				}			
				puts("");		
				if (temp->data >= 0)
				{
					printf("%d", temp->data);
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
	
	while (temp->next != NULL) {
		if (temp->data == data) {
			a++;
			return 1;
		}
		temp = temp->next;
		if (temp->data == data) {
			a++;
			return 1;
		}
	}
	if (temp->data == data) {
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
	node temp2 = head;
	node sto = head;  
	if (head == NULL)
	{
		printf("\n삭제할 노드가 없습니다.\n\n");
		return;
	}
	// 없는 수를 넣으면 삭제할 노드가 없다.
	while (temp->data != data)
	{
		temp = temp->next;
		}
	sto = temp->next; //삭제할 노드 다음 노드 .

	cnt--;

	if (temp == head) {
		head = head->next;
		free(temp);
		temp= sto;
		if (head == NULL) {
			return;
		}
		sto->pre = NULL;
		return;
	}

	if (temp->next != NULL ) {
		while (temp2->next != temp)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp->next;
		sto->pre = temp->pre;
	}
	else {
		while (temp2->next != temp)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp->next;
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
				}else {
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
					if (head == NULL) {
						break;
					}
				}

			}
			break;

		case 5: //종료
			return 0;
			break;
			

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}