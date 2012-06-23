#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double B,H,C;

int main()
{
	int tc;
	cin>>tc;
	double pi = 2*acos(0);
	for(int i=0;i<tc;i++){
		cin>>B>>H;
		double a=atan2(B/2,H);
		double r;
		C=0;
		for(double h=H;(r=h*tan(a)*tan((pi/2-a)/2))>0.000001;h-=2*r)
			C+=2*pi*r;
		if(i)cout<<endl;
		cout<<fixed<<setw(13)<<setprecision(6)<<C<<endl;
	}
	return 0;
}
