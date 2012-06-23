#include<iostream>
#include<iomanip>
using namespace std;
double a,b,c;
double s;
int n;

int main()
{
	int tc;
	cin>>tc;
	cout<<fixed<<setprecision(2);
	for(int i=0;i<tc;i++){
		cin>>n;
		cin>>a>>b;
		s=n*a+b;
		for(int j=0;j<n;j++){
			cin>>c;
			s-=2*(n-j)*c;
		}
		if(i)cout<<endl;
		cout<<s/(n+1)<<endl;
	}
	return 0;
}
