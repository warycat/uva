#include<iostream>
#include<cstdio>
using namespace std;

int Z,L,I,M;
int a[10000];

int sequence()
{
	for(int i=0;i<10000;i++)a[i]=0;
	a[L]=1;
	int t=L;
	while(a[t=(Z*t+I)%M]==0)a[t]=1;
	int seq=1;
	int end=t;
	while((t=(Z*t+I)%M)!=end)seq++;
	return seq;
}

int main()
{
	int tc=1;
	while(cin>>Z>>I>>M>>L){
		if(Z==0&&I==0&&M==0&&L==0)break;
		printf("Case %d: %d\n",tc++,sequence());
	}
	return 0;
}

