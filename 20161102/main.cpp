#include <stdio.h>
void main() {
	double A[5][5] = { { 3,3,6,7,9 },
	{ 3,4,8,6,7 },{ 6,8,5,8,8 },
	{ 7,6,8,6,9 },{ 9,7,8,9,7 } };
	double AI[5][10];
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			AI[i][j] = A[i][j];
			AI[i][j + 5] = 0;
		}
		AI[i][i + 5] = 1;
	}

	//forward method
	double pivot = 0;
	for (int i = 0; i<4; i++) {
		for (int j = i + 1; j<5; j++) {
			pivot = AI[j][i] / AI[i][i];
			for (int k = 0; k<10; k++) {
				AI[j][k] = AI[i][k] * pivot - AI[j][k];
			}
		}
	}

	// backward method
	for (int i = 4; i >= 0; i--) {
		if (AI[i][i] != 1.0) {
			double factor = AI[i][i];

			for (int j = i; j < 10; j++) {
				AI[i][j] /= factor;
			}
		}

		for (int j = i - 1; j >= 0; j--) {
			double factor = AI[j][i] / AI[i][i];

			for (int k = i; k < 10; k++) {
				AI[j][k] -= AI[i][k] * factor;
			}
		}
	}

	for (int i = 0; i<5; i++) {
		for (int j = 0; j<10; j++) {
			printf("%.3lf ", AI[i][j]);
		}
		printf("\n");
	}

}
