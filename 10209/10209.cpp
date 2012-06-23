#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	const double pi = acos(-1);
	const double sqrt3 = sqrt(3);
	double a;
	double square = 1.0;
	double s1 = pi / 4.0;
	double s2 = s1 / 3.0;
	double s3 = .25 * (sqrt3 - 1.0);
	double striped = 4.0 * (s2 - s3);
	double dotted = pi - 2.0 - 2.0 * striped;
	double rest = 1 - striped - dotted;
	while(cin>>a)
		printf("%.3f %.3f %.3f\n",striped*a*a,dotted*a*a,rest*a*a);
	return 0;
}
