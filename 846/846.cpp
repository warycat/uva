#include<iostream>
using namespace std;

int x,y;

int steps()
{
	int d = y-x;
	int n=0;
	int v=1;
	while(d&&2*v<=d){
		n+=2;
		d-=2*v;
		v++;
	}
	if(d>v)n+=2;
	else if(d>0)n+=1;
	return n;
}

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>x>>y;
		cout<<steps()<<endl;
	}
	return 0;
}
