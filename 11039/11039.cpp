#include<iostream>
#include<cstdlib>
using namespace std;

int a[500000];
int n;

int cmp(int *a, int *b)
{
	return max(*a,-*a)-max(*b,-*b);
}

int count()
{
	int v=a[0];
	int t=1;
	for(int i=1;i<n;i++)
		if(v>0&&a[i]<0||v<0&&a[i]>0){
			v=a[i];
			t++;
		}
	return t;
}


int main()
{
	int tc;
	cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		qsort(a,n,sizeof(int),(int(*)(const void*,const void*))cmp);
		cout<<count()<<endl;
	}
	return 0;
}
