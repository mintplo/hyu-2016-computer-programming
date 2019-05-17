#include <stdio.h>
#include "math.h"

double area(double h1, double h2, double eq) {
	double aa;
	aa = (h1+h2)*eq / 2.0;
	return aa;
}

double height(double a, double b, double c,
	double d, double e, double x) {
	double y;
	y = a*pow(x,4)+ b*pow(x,3)+c*pow(x,2)+
		d*pow(x,1)+e;
	return y;
}

void main() {
	double a,b,c,d,e,start,end, eq;
	int num;
	scanf("%lf%lf%lf%lf%lf%lf%lf%d",
		&a,&b,&c,&d,&e,&start,&end,&num);
	eq = (end-start) / num;
	double sum = 0;
	for(int i=0; i<num; i++) {
		sum+=area(height(a,b,c,d,e,eq*i+start),
			height(a,b,c,d,e,eq*(i+1)+start),
			eq);
	}
	printf("%lf", sum);
}