#include<iostream>
#include<iomanip>
using namespace std;
int h,m;
int main()
{
	char c;
	while(cin>>h>>c>>m&&!(h==0&&m==0)){
//		cout<<h<<"."<<m<<endl;
		if (h>=12) h-=12;
		double ah=(h+m/60.0)*(360.0/12);
		double am=m/60.0*360.0;
		double delta =max(ah-am,am-ah);
		cout<<fixed<<setprecision(3)<<min(delta,360.0-delta)<<endl;
	}
	return 0;
}
