#include <stdio.h>
#include <iostream>
#include <fstream>
#include "input.h"
#include "print.h"
#include "make_array.h"

using namespace std;

void main(void) {
	print pr;
	input in;
	ifstream ifs;
	ofstream ofs;

	ifs.open("input.txt");
	ofs.open("output.txt");

	int row_A, col_A;
	ifs>>row_A>>col_A;

	make_array ma;
	double** A = ma.two(row_A, col_A);
	in.two(row_A, col_A, A, &ifs);
	pr.two(row_A, col_A, A);

	int row_B;
	ifs>>row_B;

	double* B = ma.one(row_B);
	in.one(row_B, B, &ifs);
	pr.one(row_B, B);
}