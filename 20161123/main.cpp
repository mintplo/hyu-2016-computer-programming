#include <stdio.h>
#include <iostream>

using namespace std;

class matrix_algebra {
public:
	void mat_mat(int a, int b, int c, double** aa, double** bb, double** cc) {
		for (int i = 0; i < a; i++) {
			for (int k = 0; k < c; k++) {
				cc[i][k] = 0;

				for (int j = 0; j < b; j++) {
					cc[i][k] += aa[i][j] * bb[j][k];
				}
			}
		}
	}

	void mat_mat2(int a, int b, double** aa, double* bb, double* cc) {
		for (int i = 0; i < a; i++) {
			cc[i] = 0;

			for (int k = 0; k < b; k++) {
				cc[i] += aa[i][k] * bb[k];
			}
		}
	}

	void transpose(int a, int b, double** c, double** d) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				d[j][i] = c[i][j];
			}
		}
	}
};

class print {
public:
	void one(int p, double* a) {
		for (int i = 0; i < p; i++) {
			std::cout << a[i] << '\n';
		}
	}

	void two(int a, int b, double** c) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				std::cout << c[i][j] << '\t';
			}
			std::cout << '\n';
		}
	}
};

void main(void) {
	int m, n;
	std::cin >> m >> n;

	double** A = new double*[m];
	for (int i = 0; i < m; i++) {
		A[i] = new double[n];
	}

	double** A_T = new double*[n];
	for (int i = 0; i < n; i++) {
		A_T[i] = new double[m];
	}

	double* B = new double[m];

	double inc = 0;
	for (int i = 0; i < m; i++) {
		B[i] = i + 1;

		for (int j = 0; j < n; j++) {
			A[i][j] = inc + 1;
			inc++;
		}
	}

	print pr;
	pr.one(m, B);
	pr.two(m, n, A);

	matrix_algebra al;
	al.transpose(m, n, A, A_T);
	pr.two(n, m, A_T);

	double** TT = new double*[m];
	for (int i = 0; i < m; i++) {
		TT[i] = new double[m];
	}

	al.mat_mat(m, n, m, A, A_T, TT);
	pr.two(m, m, TT);

	double* TT2 = new double[m];
	al.mat_mat2(m, m, TT, B, TT2);

	pr.one(m, TT2);
}