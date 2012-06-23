#include<iostream>
using namespace std;

int d[4000];
int N;
int a[100];
int P;

void print()
{
	for(int i=0;i<N;i++)cout<<d[i]<<endl;
}

void mark()
{
	for(int i=0;i<P;i++)
		for(int j=a[i]-1;j<N;j+=a[i])
			d[j]++;
}

int count()
{
	int h=0;
	for(int i=0;i<N;i++){
		if(i%7==5||i%7==6)continue;
		if(d[i])h++;
	}
	return h;
}

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>N>>P;
		for(int j=0;j<P;j++)cin>>a[j];
		for(int j=0;j<N;j++)d[j]=0;
		mark();
		cout<<count()<<endl;
		//cout<<endl;
		//print();
	}
	return 0;
}
