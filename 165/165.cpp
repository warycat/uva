#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int best;
int best_a[9];
int a[9];
int h;
int k;
int value[100000];

void debug()
{
	for(int i=0;i<k;i++)
		printf("%4d",a[i]);
	printf(" ->");
	printf("%d\n",a[k-1]*h);
}

int findValue(int n)
{
	memset(value,0,sizeof(value));
	value[0]++;
	for(int i=0;i<h;i++){
		for(int v=i*a[n-1];v>=0;v--){
			if(value[v]){
				for(int j=0;j<n;j++){
					value[v+a[j]]++;
				}
			}
		}
	}
	int cv;
	for(cv=0;cv<=h*a[n-1];cv++)
		if(!value[cv])break;
	if(cv-1>best){
		memcpy(best_a,a,sizeof(a));
		best = cv-1;
	}
	return cv-1;
}

void dfs(int l)
{
	if(l==k){
		findValue(k);
	}else{
		if(l==0){
			a[l]=1;
			dfs(l+1);
		}else{
			int m = findValue(l)+1;
			for(int i=a[l-1]+1; i<=m;i++){
				a[l]=i;
				dfs(l+1);
			}
		}
	}
}

int main()
{
	while(cin>>h>>k&&h&&k){
		best = 0;
		dfs(0);	
//		debug();

		for(int i=0;i<k;i++)
			printf("%3d",best_a[i]);
		printf(" ->");
		printf("%3d\n",best);
	}
	return 0;
}
