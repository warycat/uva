#include<iostream>
#include<cstdio>
using namespace std;

int l;
int c[100];
int n;
int mem[100][100];

int f(int l,int r)
{
	if(r-l==1)return 0;
	if(mem[l][r])return mem[l][r];
	int v=0x7fffffff;
	for(int i=l+1;i<=r-1;i++){
		int t=f(l,i)+f(i,r);
		if(v>t)v=t;
	}	
	return mem[l][r]=v+c[r]-c[l];
}


int main()
{
	while(cin>>l&&l){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>c[i];
		c[0]=0;
		c[n+1]=l;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				mem[i][j]=0;
		printf("The minimum cutting is %d.\n",f(0,n+1));
	}
	return 0;
}	
