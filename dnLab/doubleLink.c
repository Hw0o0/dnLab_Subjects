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
		printf("��� ������ ���� �޸� Ȱ�翡 ������ �ֽ��ϴ�.");
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
			printf("����� ��尡 �����ϴ�.\n");
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
		printf("\n������ ��尡 �����ϴ�.\n\n");
		return;
	}
	// ���� ���� ������ ������ ��尡 ����.
	while (temp->data != data)
	{
		temp = temp->next;
		}
	sto = temp->next; //������ ��� ���� ��� .

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
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� *\n");
		printf("**************************************\n");
		puts("");
		printf("������ ��ȣ�� �Է��ϼ���. : ");
		scanf("%d", &input);
		puts("");
		switch (input) {

		case 1: //�Է�		
			while (1) {
				printf("���� �Է��ϼ���. : ");
				scanf("%d", &input);

				if (search(input)) {
					printf("\n�ߺ��� ���� �ֽ��ϴ�. \n\n ���ο� ");
				}else {
					createNode(input);
					cnt++;
					break;
				}
				
			}
			break;

		case 2: //���
			printNode();
			puts("");
			break;

		case 3: //�˻�
			printf("���� �Է��ϼ���. : ");
			scanf("%d", &input);
			if (search(input)) {
				printf("\n(O)\n\n");
			}
			else {
				printf("\n(X)\n\n");

			}
			break;

		case 4: //����
			while (1) {
				printf("������ ���� �Է��ϼ���. : ");
				scanf("%d", &input);

				if (search(input)) {
					delete(input);
					break;
				}
				else {
					printf("\n������ ��尡 �����ϴ�.\n\n");
					if (head == NULL) {
						break;
					}
				}

			}
			break;

		case 5: //����
			return 0;
			break;
			

		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
	}
}