#include <stdio.h>
#include <math.h>

double** doPivot(double a[][4]);
double** forawrdEliminate(double a[][4]);
double** backwardEliminate(double a[][4]);
void printDeterminant(double a[][4]);

void main() {
	double a[3][4] = {
		{ 3, 6, 9, 1 },
		{ 6, 9, 12, 2 },
		{ 9, 12, 12, 3 }
	};

	double b[3] = { 0, 0, 0 };

	double** pivoted = doPivot(a);
	printDeterminant(pivoted);

	double** eliminated = forawrdEliminate(a);
	printDeterminant(eliminated);

	double** finalEliminated = backwardEliminate(a);

	printDeterminant(finalEliminated);
}

// 대각원소의 절대값이 큰 순서로 정렬하는 피봇 함수
double** doPivot(double a[][4]) {
	int currentRow = 0;
	int pivotRow = currentRow;

	double maxValue;

	// find pivot row
	for (int i = 0; i < 3; i++) {
		currentRow = i;
		pivotRow = currentRow;
		maxValue = a[i][i];

		// find 
		for (int j = i + 1; j < 3; j++) {
			if (maxValue < abs(a[j][i])) {
				maxValue = a[j][i];
				pivotRow = j;
			}
		}

		// subsitute current row to pivot row
		if (pivotRow != currentRow) {
			for (int k = 0; k < 4; k++) {
				double temp = a[currentRow][k];
				a[currentRow][k] = a[pivotRow][k];
				a[pivotRow][k] = temp;
			}
		}
	}

	return a;
}

// i * (j + 1) 의 행렬을 전방 소거로 상삼각행렬을 만드는 함수
double** forawrdEliminate(double a[][4]) {
	for (int i = 0; i < 3 - 1; i++) {
		for (int j = i + 1; j < 3; j++) {
			double factor = a[j][i] / a[i][i];

			for (int k = 0; k < 4; k++) {
				a[j][k] -= a[i][k] * factor;
			}
		}
	}

	return a;
}

double** backwardEliminate(double a[][4]) {
	for (int i = 2; i >= 0; i--) {
		if (a[i][i] != 1.0) {
			double factor = a[i][i];

			for (int j = i; j < 4; j++) {
				a[i][j] /= factor;
			}
		}

		for (int j = i - 1; j >= 0; j--) {
			double factor = a[j][i] / a[i][i];

			for (int k = i; k < 4; k++) {
				a[j][k] -= a[i][k] * factor;
			}
		}
		printDeterminant(a);
	}

	return a;
}

// 행렬 출력
void printDeterminant(double a[][4]) {
	printf("\n\n\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.3lf\t", a[i][j]);
		}
		printf("\n");
	}
}