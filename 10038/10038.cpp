#include<iostream>
using namespace std;

int n;
int a[3000];
int j[3000];

int abs(int x)
{
	return max(x,-x);
}

bool isJolly()
{
	for(int i=0;i<n;i++)j[i]=0;
	for(int i=1;i<n;i++)j[abs(a[i]-a[i-1])]++;
	for(int i=1;i<n;i++)if(j[i]!=1)return false;
	return true;
}



int main()
{
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<(isJolly()?"Jolly":"Not jolly")<<endl;
	}
	return 0;
}
