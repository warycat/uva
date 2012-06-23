#include<iostream>
#include<cstdio>
using namespace std;

int N;
int a[10000];
int pre[10000];
int maximun;

int main()
{
	int maximun = 0;
	while(cin>>N&&N){
		for(int i=0;i<N;i++)
			cin>>a[i];
		pre[0]=a[0];
		for(int i=1;i<N;i++){
			if(pre[i-1]<0)
				pre[i]=a[i];
			else
				pre[i]=pre[i-1]+a[i];
		}
		maximun = 0;
		for(int i=0;i<N;i++){
			maximun = max(maximun,pre[i]);
		}
		if(maximun)
			printf("The maximum winning streak is %d.\n",maximun);
		else
			printf("Losing streak.\n");
	}
	return 0;
}
