#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
typedef struct stu {
	int stunum;
	char stuname[100];
	int kor;
	int math;
	int eng;
	int add;
	int ave;
}stu;

int main() {
	struct stu student[100];
	int input, inputs = 0, cnt = 0,cnt1= 0, temp;               // cnt = �л� ��
	struct stu sto[1];
	char name[100];
	FILE* f;
	char fname[] = "students.txt";
	
	while (1) {
		printf("****************************************************\n");
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� 6.�ε� 7.���� *\n");
		printf("****************************************************\n");
		puts("");
		printf("������ ��ȣ�� �Է��ϼ���. : ");
		scanf("%d", &input);
		puts("");
		switch (input) {

		case 1:
			printf("�й��� �Է��ϼ���. : ");
			scanf("%d", &inputs);
			puts("");
			if (inputs <= 0) {
				while (inputs <= 0) {
					printf("�й����� ������ �ƴ� ���ڸ� �Է����ּ���.");
					puts("\n");
					printf("�й��� �Է��ϼ���. : ");
					scanf("%d", &inputs);
					puts("");
			for (int a = 0; a < cnt; a++) {
						if (inputs == student[a].stunum) {
							while (inputs == student[a].stunum) {
								printf("�̹� ����Ǿ��ִ� �й��Դϴ�.");
								puts("\n");
								printf("�й��� �Է��ϼ���. : ");
								scanf("%d", &inputs);
								puts("");
							}
						}
					}
				}
			}
			for (int a = 0; a < cnt; a++) {
				if (inputs == student[a].stunum) {
					while (inputs == student[a].stunum) {
						printf("�̹� ����Ǿ��ִ� �й��Դϴ�.");
						puts("\n");
						printf("�й��� �Է��ϼ���. : ");
						scanf("%d", &inputs);
						puts("");
						if (inputs < 0) {
							while (inputs < 0) {
								printf("�й����� ������ �ƴ� ���ڸ� �Է����ּ���.");
								puts("\n");
								printf("�й��� �Է��ϼ���. : ");
								scanf("%d", &inputs);
								puts("");
							}
						}
					}
				}
			}
			student[cnt].stunum = inputs;
			printf("�̸��� �Է��ϼ���. : ");
			scanf("%s", name);
			for (int a = 0; a < 100; a++) {
				student[cnt].stuname[a] = name[a];
			}
			puts("");
			printf("������ �Է��ϼ���. : ");
			scanf("%d", &inputs);

			if (inputs > 100) {
				while (inputs > 100) {
					printf("�������� 100�� �ѱ��� �ʴ� ���� �Է����ּ���.");
					puts("\n");
					printf("������ �Է��ϼ���. : ");
					scanf("%d", &inputs);
					puts("");
				}
			}
			if (inputs < 0) {
				while (inputs < 0) {
					printf("�������� ������ �ƴ� ���ڸ� �Է����ּ���.");
					puts("\n");
					printf("������ �Է��ϼ���. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs > 100) {
						while (inputs > 100) {
							printf("�������� 100�� �ѱ��� �ʴ� ���� �Է����ּ���.");
							puts("\n");
							printf("������ �Է��ϼ���. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			student[cnt].kor = inputs;
			puts("");
			printf("������ �Է��ϼ���. : ");
			scanf("%d", &inputs);

			if (inputs > 100) {
				while (inputs > 100) {
					printf("�������� 100�� �ѱ��� �ʴ� ���� �Է����ּ���.");
					puts("\n");
					printf("������ �Է��ϼ���. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs < 0) {
						while (inputs < 0) {
							printf("�������� ������ �ƴ� ���ڸ� �Է����ּ���.");
							puts("\n");
							printf("������ �Է��ϼ���. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			if (inputs < 0) {
				while (inputs < 0) {
					printf("�������� ������ �ƴ� ���ڸ� �Է����ּ���.");
					puts("\n");
					printf("������ �Է��ϼ���. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs > 100) {
						while (inputs > 100) {
							printf("�������� 100�� �ѱ��� �ʴ� ���� �Է����ּ���.");
							puts("\n");
							printf("������ �Է��ϼ���. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			student[cnt].math = inputs;
			puts("");
			printf("������ �Է��ϼ���. : ");
			scanf("%d", &inputs);

			if (inputs > 100) {
				while (inputs > 100) {
					printf("�������� 100�� �ѱ��� �ʴ� ���� �Է����ּ���.");
					puts("\n");
					printf("������ �Է��ϼ���. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs < 0) {
						while (inputs < 0) {
							printf("�������� ������ �ƴ� ���ڸ� �Է����ּ���.");
							puts("\n");
							printf("������ �Է��ϼ���. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			if (inputs < 0) {
				while (inputs < 0) {
					printf("�������� ������ �ƴ� ���ڸ� �Է����ּ���.");
					puts("\n");
					printf("������ �Է��ϼ���. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs > 100) {
						while (inputs > 100) {
							printf("�������� 100�� �ѱ��� �ʴ� ���� �Է����ּ���.");
							puts("\n");
							printf("������ �Է��ϼ���. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			student[cnt].eng = inputs;
			puts("");
			for (int a = 0; a < 100; a++) {
				student[a].add = student[a].kor + student[a].math + student[a].eng;
				student[a].ave = (student[a].kor + student[a].math + student[a].eng) / 3;
			}
			cnt++;
			break;
		case 2:

			if (cnt == 0) {
				cnt += cnt1;
			}
			if (cnt == 0) {
				puts("");
				printf("����� �л� ������ �����ϴ�.");
				puts("\n");
			}

			for (int a = 0; a < cnt - 1; a++)
			{
				for (int b = 0; b < cnt - 1 - a; b++)
				{
					if (student[b].ave > student[b + 1].ave)
					{
						sto[0] = student[b];
						student[b] = student[b + 1];
						student[b + 1] = sto[0];

					}
				}
			}
			for (int a = 0; a < cnt; a++) {

				printf("�й� : %d | �̸� : %s | �������� : %d | �������� : %d | �������� : %d | �������� : %d | ������� : %d |",
					student[a].stunum, student[a].stuname, student[a].kor, student[a].math, student[a].eng, student[a].add, student[a].ave);
				puts("\n");
			}
			cnt1 = 0;
			break;

		case 3:
			printf("�˻��� �л��� �й��� �Է��ϼ���. : ");
			scanf("%d", &input);
			temp = 0;
			for (int a = 0; a <= cnt; a++) {
				if (input == student[a].stunum) {
					puts("");
					printf("�˻��� �л��� ������ ������ �����ϴ�.");
					puts("\n");
					printf("�й� : %d | �̸� : %s | �������� : %d | �������� : %d | �������� : %d | �������� : %d | ������� : %d |",
						student[a].stunum, student[a].stuname, student[a].kor, student[a].math, student[a].eng, student[a].add, student[a].ave);
					puts("\n");
					temp++;
				}
			}
			if (temp == 0) {
				puts("");
				printf("����� �л� ������ �����ϴ�.");
				puts("\n");
				break;
			}

			break;

		case 4:
			printf("������ �л��� �й��� �Է��ϼ���. : ");
			scanf("%d", &input);
			puts("");
			printf("�л��� ������ �����߽��ϴ�");
			puts("");
			for (int a = 0; a < cnt; a++) {
				if (input == student[a].stunum) {
					for (int b = a; b < cnt; b++) {
						student[b].stunum = student[b + 1].stunum;
					}
					cnt--;
				}
			}
			break;

		case 5:

			if ((f = fopen(fname, "w")) == NULL)
			{
				printf("������ ������ �ʽ��ϴ�.\n");
				exit(1);
			};
			for (int a = 0; a < cnt - 1; a++)
			{
				for (int b = 0; b < cnt - 1 - a; b++)
				{
					if (student[b].ave > student[b + 1].ave)
					{
						sto[0] = student[b];
						student[b] = student[b + 1];
						student[b + 1] = sto[0];

					}
				}
			}
			for (int a = 0; a < cnt; a++) {

				fprintf(f, "%d %d %s %d %d %d %d %d\n",
					a + 1, student[a].stunum, student[a].stuname, student[a].kor, student[a].math, student[a].eng, student[a].add, student[a].ave);
			}
			fclose(f);
			printf("�л� ����Ʈ�� �����Ͽ����ϴ�. 'students.txt'���� Ȯ���Ͻ� �� �ֽ��ϴ�.");
			puts("\n");
			break;

		case 6:
			if (cnt!=0) {
				for (int a = 0; a < cnt; a++) {
					student[a].stunum =-1;
				}
				cnt = 0;
			}
		

			if ((f = fopen(fname, "r")) == 0) {
				printf("������ ������ �ʽ��ϴ�.\n");
				exit(1);
			}

			stu tempStu;
			stu student1[100];
			int idxNum = 1;

			while (fscanf(f, "%d %d %s %d %d %d %d %d\n", &idxNum, &tempStu.stunum, tempStu.stuname, &tempStu.kor, &tempStu.math, &tempStu.eng, &tempStu.add, &tempStu.ave) != EOF)
			{
				student[idxNum-1] = tempStu;
				cnt1++;
			}
			fclose(f);
			break;
			puts("");
			printf("'students.txt'���� �л� ����Ʈ�� �ε��Ͽ����ϴ�.");
			puts("\n");
			break;
		case 7:
			printf("�ý����� �����մϴ�");
			return 0;
		}
	}
}