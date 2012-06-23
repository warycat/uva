#include<iostream>
using namespace std;

int a[10000];
int n=0;

int median()
{
	int i=n-1;
	while(i-1>=0){
		if(a[i]>a[i-1])swap(a[i],a[i-1]);
		else break;
		i--;
	}
//	for(int i=0;i<n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	if(n%2)return a[n/2];
	else return (a[n/2]+a[n/2-1])/2;
}


int main()
{
	int x;
	while(cin>>x){
		a[n++]=x;
		cout<<median()<<endl;
	}
	return 0;
}
		
