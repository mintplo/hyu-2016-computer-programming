#include <stdio.h>

void main() {
	int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int B[3] = {1,2,3};
	int C[3];

	printf("��� A�� ����\n");
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			printf("%d  ", A[i][j]);
		}
		printf("\n");
	}

	printf("��� B�� ����\n");
	for(int i=0; i<3; i++) {
		printf("%d\n", B[i]);
	}

	//C = A*B
	for(int i=0; i<3; i++) {
		C[i]=0;
		for(int j=0; j<3; j++) {
			C[i] += A[i][j] * B[j];
		}
	}
	printf("C�� ����\n");
	for(int i=0; i<3; i++) {
		printf("%d\n", C[i]);
	}

	//D array
	int D[3][7] = {{1,2,3,4,5,6,7},	
	{1,2,3,4,5,6,7},
	{1,2,3,4,5,6,7}};
	int E[3][7];
	
	for(int i=0; i<3; i++) {
		for(int j=0; j<7; j++) {
			E[i][j] = 0;
			for(int k=0; k<3; k++) {
				E[i][j] += A[i][k] * D[k][j];
			}
		}
	}

	printf("E�� ������� \n");
	for(int i=0; i<3; i++) {
		for(int j=0; j<7; j++) {
			printf("%d   ", E[i][j]);
		}
		printf("\n");
	}
}