#include<iostream>
#include<cstdio>
using namespace std;

int a[1000];
int n;

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>n;
		int sum = 0;
		for(int j=0;j<n;j++){
			cin>>a[j];
			sum += a[j];
		}
		int average = sum / n;
		int count = 0;
		for(int j=0;j<n;j++)if(a[j]>average)count++;
		printf("%5.3f%%\n",100.0*count/n);
	}
	return 0;
}
