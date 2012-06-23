#include<iostream>
#include<cstdio>
using namespace std;

int a[50];
int n;
int move;

int main()
{
	int tc=1;
	while(cin>>n&&n){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		int avg=sum/n;
		move=0;
		for(int i=0;i<n;i++)if(a[i]>avg)move+=a[i]-avg;
		printf("Set #%d\n",tc++);
		printf("The minimum number of moves is %d.\n\n",move);
	}
	return 0;
}	
