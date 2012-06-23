#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[4][4];
int rook;

void debug()
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void put(int i, int j, int d)
{
	int ii,jj;
	a[i][j]+=d;
	ii=i-1;
	while(ii>=0&&a[ii][j]>=0)a[ii--][j]+=d;
	ii=i+1;
	while(ii<n&&a[ii][j]>=0)a[ii++][j]+=d;
	jj=j-1;
	while(jj>=0&&a[i][jj]>=0)a[i][jj--]+=d;
	jj=j+1;
	while(jj<n&&a[i][jj]>=0)a[i][jj++]+=d;
}


void dfs(int p, int r)
{
	if(r>rook){
		rook=r;
	}
	if(p==n*n){
		return;
	}
	while(p<n*n){
		if(a[p/n][p%n]==0){
			put(p/n,p%n,1);
			dfs(p+1,r+1);
			put(p/n,p%n,-1);
		}
		p++;
	}
}
		

int main()
{
	char c;
	while(cin>>n&&n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>c;
				if(c=='.')a[i][j]=0;
				if(c=='X')a[i][j]=-1000;
			}
		}
//		debug();
		rook=0;
		dfs(0,0);
		cout<<rook<<endl;
	}
	return 0;
}

