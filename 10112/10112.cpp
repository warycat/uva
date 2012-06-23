#include<iostream>
using namespace std;

char q[15];
double x[15];
double y[15];
double s[15][15][15];
int n;
int a,b,c;

double area(int p1,int p2,int p3)
{
	double t= 0.5*((y[p3]-y[p1])*(x[p2]-x[p1])-(y[p2]-y[p1])*(x[p3]-x[p1]));
	return max(t,-t);
}

int valid(int p1,int p2, int p3)
{
	for(int i=0;i<n;i++){
		if(i==p1||i==p2||i==p3)continue;
//		cout<<p1<<p2<<p3<<" "<<i<<endl;
		if((s[i][p1][p2]+s[i][p2][p3]+s[i][p3][p1]-s[p1][p2][p3])<1e-10)return 0;
	}
	return 1;
}

void power()
{
	int i,j,k,l;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				s[i][j][k]=area(i,j,k);
	double m=0;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			for(k=j+1;k<n;k++)
				if(s[i][j][k]>m&&valid(i,j,k)){
					m=s[i][j][k];
					a=i;
					b=j;
					c=k;
				}
}

int main()
{
	while(cin>>n&&n){
		for(int i=0;i<n;i++)cin>>q[i]>>x[i]>>y[i];
		power();
		cout<<q[a]<<q[b]<<q[c]<<endl;
	}
	return 0;
}
