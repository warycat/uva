#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
	double x[4],y[4];
	while(cin>>x[0]>>y[0]>>x[1]>>y[1]){
		if(x[0]==x[1]&&y[0]==y[1])
			cout<<"Impossible.\n";
		else{
			x[2]=(x[0]+x[1]-y[1]+y[0])/2.0;
			x[3]=(x[0]+x[1]+y[1]-y[0])/2.0;
			y[2]=(y[0]+y[1]+x[1]-x[0])/2.0;
			y[3]=(y[0]+y[1]-x[1]+x[0])/2.0;
			cout<<fixed<<setprecision(10);
			cout<<x[2]<<" "<<y[2]<<" "<<x[3]<<" "<<y[3]<<endl;
		}
	}
	return 0;
}
