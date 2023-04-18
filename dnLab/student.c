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
	int input, inputs = 0, cnt = 0,cnt1= 0, temp;               // cnt = 학생 수
	struct stu sto[1];
	char name[100];
	FILE* f;
	char fname[] = "students.txt";
	
	while (1) {
		printf("****************************************************\n");
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.저장 6.로드 7.종료 *\n");
		printf("****************************************************\n");
		puts("");
		printf("실행할 번호를 입력하세요. : ");
		scanf("%d", &input);
		puts("");
		switch (input) {

		case 1:
			printf("학번을 입력하세요. : ");
			scanf("%d", &inputs);
			puts("");
			if (inputs <= 0) {
				while (inputs <= 0) {
					printf("학번에는 음수가 아닌 숫자를 입력해주세요.");
					puts("\n");
					printf("학번을 입력하세요. : ");
					scanf("%d", &inputs);
					puts("");
			for (int a = 0; a < cnt; a++) {
						if (inputs == student[a].stunum) {
							while (inputs == student[a].stunum) {
								printf("이미 저장되어있는 학번입니다.");
								puts("\n");
								printf("학번을 입력하세요. : ");
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
						printf("이미 저장되어있는 학번입니다.");
						puts("\n");
						printf("학번을 입력하세요. : ");
						scanf("%d", &inputs);
						puts("");
						if (inputs < 0) {
							while (inputs < 0) {
								printf("학번에는 음수가 아닌 숫자를 입력해주세요.");
								puts("\n");
								printf("학번을 입력하세요. : ");
								scanf("%d", &inputs);
								puts("");
							}
						}
					}
				}
			}
			student[cnt].stunum = inputs;
			printf("이름을 입력하세요. : ");
			scanf("%s", name);
			for (int a = 0; a < 100; a++) {
				student[cnt].stuname[a] = name[a];
			}
			puts("");
			printf("국어을 입력하세요. : ");
			scanf("%d", &inputs);

			if (inputs > 100) {
				while (inputs > 100) {
					printf("점수에는 100을 넘기지 않는 값을 입력해주세요.");
					puts("\n");
					printf("국어을 입력하세요. : ");
					scanf("%d", &inputs);
					puts("");
				}
			}
			if (inputs < 0) {
				while (inputs < 0) {
					printf("점수에는 음수가 아닌 숫자를 입력해주세요.");
					puts("\n");
					printf("국어을 입력하세요. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs > 100) {
						while (inputs > 100) {
							printf("점수에는 100을 넘기지 않는 값을 입력해주세요.");
							puts("\n");
							printf("국어을 입력하세요. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			student[cnt].kor = inputs;
			puts("");
			printf("수학을 입력하세요. : ");
			scanf("%d", &inputs);

			if (inputs > 100) {
				while (inputs > 100) {
					printf("점수에는 100을 넘기지 않는 값을 입력해주세요.");
					puts("\n");
					printf("수학을 입력하세요. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs < 0) {
						while (inputs < 0) {
							printf("점수에는 음수가 아닌 숫자를 입력해주세요.");
							puts("\n");
							printf("수학을 입력하세요. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			if (inputs < 0) {
				while (inputs < 0) {
					printf("점수에는 음수가 아닌 숫자를 입력해주세요.");
					puts("\n");
					printf("수학을 입력하세요. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs > 100) {
						while (inputs > 100) {
							printf("점수에는 100을 넘기지 않는 값을 입력해주세요.");
							puts("\n");
							printf("수학을 입력하세요. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			student[cnt].math = inputs;
			puts("");
			printf("영어을 입력하세요. : ");
			scanf("%d", &inputs);

			if (inputs > 100) {
				while (inputs > 100) {
					printf("점수에는 100을 넘기지 않는 값을 입력해주세요.");
					puts("\n");
					printf("영어을 입력하세요. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs < 0) {
						while (inputs < 0) {
							printf("점수에는 음수가 아닌 숫자를 입력해주세요.");
							puts("\n");
							printf("영어을 입력하세요. : ");
							scanf("%d", &inputs);
							puts("");
						}
					}
				}
			}
			if (inputs < 0) {
				while (inputs < 0) {
					printf("점수에는 음수가 아닌 숫자를 입력해주세요.");
					puts("\n");
					printf("영어을 입력하세요. : ");
					scanf("%d", &inputs);
					puts("");
					if (inputs > 100) {
						while (inputs > 100) {
							printf("점수에는 100을 넘기지 않는 값을 입력해주세요.");
							puts("\n");
							printf("영어을 입력하세요. : ");
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
				printf("출력할 학생 정보가 없습니다.");
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

				printf("학번 : %d | 이름 : %s | 국어점수 : %d | 수학점수 : %d | 영어점수 : %d | 총합점수 : %d | 평균점수 : %d |",
					student[a].stunum, student[a].stuname, student[a].kor, student[a].math, student[a].eng, student[a].add, student[a].ave);
				puts("\n");
			}
			cnt1 = 0;
			break;

		case 3:
			printf("검색할 학생의 학번을 입력하세요. : ");
			scanf("%d", &input);
			temp = 0;
			for (int a = 0; a <= cnt; a++) {
				if (input == student[a].stunum) {
					puts("");
					printf("검색할 학생의 정보는 다음과 같습니다.");
					puts("\n");
					printf("학번 : %d | 이름 : %s | 국어점수 : %d | 수학점수 : %d | 영어점수 : %d | 총합점수 : %d | 평균점수 : %d |",
						student[a].stunum, student[a].stuname, student[a].kor, student[a].math, student[a].eng, student[a].add, student[a].ave);
					puts("\n");
					temp++;
				}
			}
			if (temp == 0) {
				puts("");
				printf("출력할 학생 정보가 없습니다.");
				puts("\n");
				break;
			}

			break;

		case 4:
			printf("삭제할 학생의 학번을 입력하세요. : ");
			scanf("%d", &input);
			puts("");
			printf("학생의 정보를 삭제했습니다");
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
				printf("파일이 열리지 않습니다.\n");
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
			printf("학생 리스트를 저장하였습니다. 'students.txt'에서 확인하실 수 있습니다.");
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
				printf("파일이 열리지 않습니다.\n");
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
			printf("'students.txt'에서 학생 리스트를 로드하였습니다.");
			puts("\n");
			break;
		case 7:
			printf("시스템을 종료합니다");
			return 0;
		}
	}
}