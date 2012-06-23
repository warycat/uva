#include<iostream>
using namespace std;

int a[10000];
int n,m;

int cmp(int *p,int *q)
{
	int t = *p%m - *q%m;
	if(t)return t;
	t = *q%2 - *p%2;
	if(t&&t!=2&&t!=-2)return t;
	if(*p%2)return *q-*p;
	else return *p-*q;
}

int main()
{
	while(cin>>n>>m&&n&&m){
		cout<<n<<" "<<m<<endl;
		for(int i=0;i<n;i++)cin>>a[i];
		qsort(a,n,sizeof(int),(int(*)(const void*,const void*))cmp);
		for(int i=0;i<n;i++)cout<<a[i]<<endl;
	}
	cout<<"0 0\n";
	return 0;
}
