#include <stdio.h>

void main() {
	int A[3][3] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	int B[3] = { 1, 2, 3 };
	int D[3][7] = { { 1, 2, 3, 4, 5, 6, 7 }, { 1, 2, 3, 4, 5, 6, 7 }, { 1, 2, 3, 4, 5, 6, 7 } };

	for (int i = 0; i < 7; i++) {
		int result = 0;

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				for (int m = 0; m < 3; m++) {
					result += A[j][m] * A[k][m] * B[k] * D[k][i];
				}
			}
		}

		printf("%d\t", result);
	}
}