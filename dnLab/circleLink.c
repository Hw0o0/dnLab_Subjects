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

		printf("��� ������ ���� �޸� Ȱ�翡 ������ �ֽ��ϴ�.");
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
		printf("����� ��尡 �����ϴ�.\n");
		return;
	}

	if (cnt == 0) {
		if (temp->data < 0) {
			temp->data = -1;
			printf("����� ��尡 �����ϴ�.\n");
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
		printf("\n������ ��尡 �����ϴ�.\n\n");
		return;
	}


	
	while (temp->data != data)
	{//�Է��� ������ ���
		temp = temp->next;

	}


	while (sto->next !=temp)
	{//�Է��� �������� ���� ���
		sto = sto->next;
	}

	while (sto2->next != sto)
	{ //�Է��� ������ ���� �� ���
		sto2 = sto2->next;
	}
	cnt--;
	if (temp == head)   //ù��� ����
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
		sto->next = temp->next; //�߰� ��� ����
		return;
	}
	if (temp->next == head) {  //�� ��� ����
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
				}
				else {
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
				}

			}
			break;

		case 5: //����
			return 0;
			break;

		case 6:
			printf("�����");
			break;


		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;

		}
	}
}