#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct root {
	int data;
	struct root* left;
	struct root* right;

}root;
typedef struct root* node;

node head = NULL;
node sto = NULL, sto1 = NULL;
int cnt = 0, cnt1 = 0, cnt2 = 0;

int search(node new, node temp) {

	if (head != NULL) {
		if (temp->data == new->data) {
			cnt1++;
		}
		if (temp->left != NULL) {
			if (temp->data == new->data) {
				cnt1++;
			}
			search(new, temp->left);
		}
		if (temp->right != NULL) {
			if (temp->data == new->data) {
				cnt1++;
			}
			search(new, temp->right);
		}
		return;
	}
}
void search2(int data, node temp) { // ���� Ž��
	if (temp->data == data) {
		cnt2++;
	}
	if (temp->left != NULL) {
		if (temp->data == data) {
			cnt2++;
		}
		search2(data, temp->left);
	}
	if (temp->right != NULL) {
		if (temp->data == data) {
			cnt2++;
		}
		search2(data, temp->right);
	}
	return;
}
void append(node new, node temp) {
	cnt1 = 0;
	search(new, head);
	if (cnt1 > 0) {
		printf("�̹� ����� ������ ���Դϴ�. \n");
		return;
	}


	if (head == NULL)
	{
		head = new;
		return;
	}
	if (temp->data > new->data) {
		if (temp->left != NULL) {
			if (temp->data < new->data)
			{
				temp->right = new;
				return;
			}
			append(new, temp->left);
		}
		if (temp->left == NULL) {
			temp->left = new;
			return;
		}
	}
	else {
		if (temp->data < new->data)
			if (temp->right != NULL) {
				if (temp->data > new->data)
				{
					temp->left = new;
					return;
				}
				append(new, temp->right);
			}
		if (temp->right == NULL) {
			temp->right = new;
			return;
		}
	}
}

void createNode(int data) {
	node new;
	new = (node)malloc(sizeof(root));
	if (new == NULL) {
		printf("��� ������ ���� �޸� Ȱ�翡 ������ �ֽ��ϴ�.");
	}
	new->left = NULL;
	new->data = data;
	new->right = NULL;
	append(new, head);
	return;
}

void delete3(int data, node temp) {
	node sto = NULL, sto1 = NULL, sto2 = NULL;

	if (head->data == data) {               //head ����
		temp = head->left;
		if (temp->right == NULL) {
			temp->right = head->right;
			head = temp;
			return;
		}
		while (temp->right != NULL) {
			sto2 = temp;              //ū���� �� ���
			temp = temp->right;
			if (temp->right == NULL)  //ū ���� ���
			{
				head->data = temp->data;
				if (temp->left != NULL)
				{
					sto2->right = temp->left;
					return;
				}
				sto2->right = NULL;
				return;
			}
		}
	}

	if (temp->left != NULL) {
		if (temp->data == data)
		{ //������ ���
			sto = temp;
			temp = temp->left;
			if (temp == sto->left)  // ������ ��� left ���   
			{
				if (temp->right == NULL) {
					sto->data = temp->data;
					sto->left = temp->left;
					return;
				}

				if (head->data > data)
				{
					while (temp->right != NULL)
					{
						if (temp->right->right == NULL)
						{
							sto1 = temp;      //ū������ �� ���;
						}
						if (temp->right == NULL)
						{
							sto->data = temp->data;
							sto1->right = NULL;
							return;
						}
						temp = temp->right;
						if (temp->right == NULL)
						{
							sto->data = temp->data;
							sto1->right = NULL;
							return;
						}
					}
				}
				else {

					while (temp->left != NULL)
					{
						if (temp->left->left == NULL)
						{
							sto1 = temp;      //ū������ �� ���;
						}
						if (temp->left == NULL)
						{
							sto->data = temp->data;
							sto1->left = NULL;
							return;
						}
						temp = temp->left;
						if (temp->left == NULL)
						{
							sto->data = temp->data;
							sto1->left = NULL;
							return;
						}
					}
				}
			}
		}
		delete3(data, temp->left);
	}
	if (temp->right != NULL) {
		if (temp->data == data)
		{
			sto = temp; // ������ ���
			temp = temp->left;
			if (temp == sto->left)  // ������ ��� left ���   
			{
				if (temp->left == NULL) {
					sto->data = temp->data;
					sto->right = temp->right;
					return;
				}
				while (temp->right != NULL)
				{
					if (temp->right->right == NULL)
					{
						sto1 = temp;      //ū������ �� ���;
					}
					if (temp->right == NULL)
					{
						sto->data = temp->data;
						sto1->right = NULL;
						return;
					}
					temp = temp->right;
					if (temp->right == NULL)
					{
						sto->data = temp->data;
						sto1->right = NULL;
						return;
					}
				}
			}
			else {
				while (temp->left != NULL)
				{
					if (temp->left->left == NULL)
					{
						sto1 = temp;      //ū������ �� ���;
					}
					if (temp->left == NULL)
					{
						sto->data = temp->data;
						sto1->left = NULL;
						return;
					}
					temp = temp->left;
					if (temp->left == NULL)
					{
						sto->data = temp->data;
						sto1->left = NULL;
						return;
					}
				}
			}
		}
		delete3(data, temp->right);
	}
	return;
}


void delete2(int data, node temp) { // ��尡 �ϳ��� ����Ʈ���� ���� ���
	node sto = NULL;

	if (head->data == data) {               //head ����
		if (temp->right == NULL) {
			head = head->left;
			return;
		}
		if (temp->left == NULL) {
			head = head->right;
			return;
		}
	}

	if (temp->left != NULL) {
		if (temp->left->data == data)
		{
			if (temp->left->right == NULL) {
				temp->left = temp->left->left;
				return;
			}
			else {
				temp->left = temp->left->right;
			}

		}
		delete2(data, temp->left);
	}
	if (temp->right != NULL) {
		if (temp->right->data == data)
		{
			if (temp->right->left == NULL) {
				temp->right = temp->right->right;
				return;
			}
			else {
				temp->right = temp->right->left;
			}
		}
		delete2(data, temp->right);
	}
	return;
}
void delete1(int data, node temp) { // �ܸ� ��� ������ ���             
	if (head->data == data) {
		head = NULL;
		return;
	}

	if (temp->left != NULL) {
		if (temp->left->data == data) {
			if (temp->left->left == NULL) {
				temp->left = temp->left->right;
				return;
			}
			else {
				temp->right = temp->left->left;
				return;
			}
			return;
		}
		delete1(data, temp->left);
	}
	if (temp->right != NULL) {
		if (temp->right->data == data) {
			if (temp->right->right == NULL) {
				temp->right = temp->right->left;
				return;
			}
			else {
				temp->left = temp->right->right;
				return;
			}
		}
		delete1(data, temp->right);
	}
	return;
}

void delete(int data, node temp) {   // �ڽ� �� Ž��

	if (head == NULL) {
		printf("\n������ �����Ͱ� �����ϴ�\n\n");
		return;
	}
	search2(data, head);
	if (cnt2 == 0) {
		printf("\n������ �����Ͱ� �����ϴ�.\n\n");
		return;
	}
	if (head->data == data) {
		if (head->left != NULL) {
			cnt++;
		}
		if (head->right != NULL) {
			cnt++;
		}
		if (cnt == 0) {
			delete1(data, head);
			printf("\n�����Ͽ����ϴ�\n\n");
			cnt = 0;
			cnt2 = 0;
			return;
		}
		if (cnt == 1) {
			delete2(data, head);
			printf("\n�����Ͽ����ϴ�\n\n");
			cnt = 0;
			cnt2 = 0;
			return;
		}
		if (cnt == 2) {
			delete3(data, head);
			printf("\n�����Ͽ����ϴ�\n\n");
			cnt = 0;
			cnt2 = 0;
			return;
		}
	}

	if (temp->left != NULL) {
		if (temp->left->data == data) {
			if (temp->left->left != NULL) {
				cnt++;
			}
			if (temp->left->right != NULL) {
				cnt++;
			}
			if (cnt == 0) {
				delete1(data, head);
				printf("\n�����Ͽ����ϴ�\n\n");
				cnt = 0;
				cnt2 = 0;
				return;
			}
			if (cnt == 1) {
				delete2(data, head);
				printf("\n�����Ͽ����ϴ�\n\n");
				cnt = 0;
				cnt2 = 0;
				return;
			}
			if (cnt == 2) {
				delete3(data, head);
				printf("\n�����Ͽ����ϴ�\n\n");
				cnt = 0;
				cnt2 = 0;
				return;
			}
		}
		delete(data, temp->left);
	}
	if (temp->right != NULL) {
		if (temp->right->data == data) {
			if (temp->right->left != NULL) {
				cnt++;
			}
			if (temp->right->right != NULL) {
				cnt++;
			}
			if (cnt == 0) {
				delete1(data, head);
				printf("\n�����Ͽ����ϴ�\n\n");
				cnt = 0;
				cnt2 = 0;
				return;
			}
			if (cnt == 1) {
				delete2(data, head);
				printf("\n�����Ͽ����ϴ�\n\n");
				cnt = 0;
				cnt2 = 0;
				return;
			}
			if (cnt == 2) {
				delete3(data, head);
				printf("\n�����Ͽ����ϴ�\n\n");
				cnt = 0;
				cnt2 = 0;
				return;
			}
		}
		delete(data, temp->right);

	}
	return;
}

void preorder(node temp) {
	if (head == NULL) {
		printf("����� ��尡 �����ϴ�.");
		return;
	}
	printf("%d  ", temp->data);
	if (temp->left != NULL) {
		preorder(temp->left);
	}
	if (temp->right != NULL) {
		preorder(temp->right);
	}
	return;
}
void inorder(node temp) {
	if (head == NULL) {
		printf("����� ��尡 �����ϴ�.");
		return;
	}
	if (temp->left != NULL) {
		inorder(temp->left);
	}
	printf("%d  ", temp->data);
	if (temp->right != NULL) {
		inorder(temp->right);
	}
	return;
}
void postorder(node temp) {
	if (head == NULL) {
		printf("����� ��尡 �����ϴ�.");
		return;
	}
	if (temp->left != NULL) {
		postorder(temp->left);
	}
	if (temp->right != NULL) {
		postorder(temp->right);
	}
	printf("%d  ", temp->data);
	return;
}



int main() {

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

		case 1:// �Է�                              ��������
			while (1) {
				printf("���� �Է��ϼ���. : ");
				scanf("%d", &input);
				createNode(input);
				break;
			}
			break;
		case 2://���                                ��������
			printf("���� ��ȸ : ");
			preorder(head);
			puts("\n");
			printf("���� ��ȸ : ");
			inorder(head);
			puts("\n");
			printf("���� ��ȸ : ");
			postorder(head);
			puts("\n");
			break;
		case 4://����                                                  �ܸ� ��� ���� o        ���� 1�� ���� x              ���� 2�� ���� x
			printf("���� �Է��ϼ���. : ");
			scanf("%d", &input);
			delete(input, head);
			break;
		case 5://����
			return;

			break;
		case 6:
			printf("����� Ȯ��\n");
			break;
		default:
			printf("�߸��� �Է°��Դϴ�.");
			break;
		}
	}
}