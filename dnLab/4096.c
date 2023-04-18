#include <stdio.h>

int main(void) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				for (int l = 1; l <= 8; l++) {
					printf("%5d", l + 64 * k + 8 * j + i * 512);
				}
				printf("    ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
