#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main(void) {

	int input, dia = 1, i, j;



	printf("���ϴ� ���� �Է�:");

	scanf("%d", &input);






	if (input % 2) {   //Ȧ��


		for (i = 0; i < (input + 1) / 2; i++) {

			for (j = 0; j <= input / 2 - i - 1; j++) {

				printf(" ");

			}

			for (j = 0; j < dia; j++)

				printf("*");
			dia += 2;
			printf("\n");
		}
		for (i = 0; i < input / 2 + 1; i++) {

			for (j = 0; j < i + 1; j++) {

				printf(" ");

			}

			for (j = 0; j < dia - 4; j++)

				printf("*");
			dia -= 2;
			printf("\n");

		}
	}



	else {  //¦��

		for (i = 0; i < (input + 1) / 2; i++) {

			for (j = 0; j <= input / 2 - i - 1; j++) {

			printf(" ");
			}
			for (j = 0; j < dia+1; j++)

			printf("*");
			dia += 2;
			printf("\n");
	}
		for (i = 0; i < input / 2 + 1; i++) {

			for (j = 0; j < i + 2; j++) {
			printf(" ");
			}
			for (j = 0; j < dia - 3; j++)
				printf("*");
			dia -= 2;
			printf("\n");
		}
	}
	return 0;
}





