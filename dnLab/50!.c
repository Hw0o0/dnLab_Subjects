#define _CRT_SECURE_NO_WARNINGS
#define SIZE 200
#include <stdio.h>

int main(void) {



	int  input, i, j, k, z, c;
	int x[SIZE] = { 0 };//이전의 값
	int y[SIZE] = { 0 }; //계산하고 들어갈 값


	printf("1~50 중 원하는 숫자를 입력하시오 :");
	scanf("%d", &input);


	x[0] = 1;
	y[0] = 1;

	if (input != 0) {
		for (i = 1; i <= input; i++) {
			k = 0;
			for (j = 0; j < SIZE; j++) {
				z = x[j] * i;
				z += k;
				y[j] = z % 10;
				k = z / 10;
			}
			for (j = 0; j < SIZE; j++) {
				x[j] = y[j];

			}
		}
	}
	printf("%d! =  ", input);

	for (j = SIZE; j > 0; j--) {
		for (c = 1; y[j - 1] != 0; c++) {
			if (j < c) {
				continue;
			}
			printf("%d", y[j - c]);

		}
	}
	
	return 0;
}
