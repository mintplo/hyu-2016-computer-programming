#include <stdio.h>
#include <math.h>

double** doPivot(double a[][4]);
double** forawrdEliminate(double a[][4]);
double* backwardSubsitute(double a[][4], double b[3]);
void printDeterminant(double a[][4]);

void main() {
	double a[3][4] = {
		{3, 6, 9, 1},
		{6, 9, 12, 2},
		{9, 12, 12, 3}
	};

	double b[3] = {0, 0, 0};

	double** pivoted = doPivot(a);
	printDeterminant(pivoted);

	double** eliminated = forawrdEliminate(a);
	printDeterminant(eliminated);

	double* subsituted = backwardSubsitute(a, b);

	printf("\n\n\n");
	for (int i = 0; i < 3; i++) {
		printf("%.3lf\n", subsituted[i]);
	}
}

// �밢������ ���밪�� ū ������ �����ϴ� �Ǻ� �Լ�
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

// i * (j + 1) �� ����� ���� �Ұŷ� ��ﰢ����� ����� �Լ�
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

// �ٿ����������������� Ǯ�� ���� ���� �Լ�
double* backwardSubsitute(double a[][4], double b[3]) {
	for (int i = 3 - 1; i >= 0; i--) {
		double numerator = a[i][3];

		for (int j = 2; j >= i; j--) {
			numerator -= a[i][j] * b[i];
		}

		b[i] = numerator / a[i][i];
	}

	return b;
}

// ��� ���
void printDeterminant(double a[][4]) {
	printf("\n\n\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.3lf\t", a[i][j]);
		}
		printf("\n");
	}
}