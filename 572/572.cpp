#include<iostream>
using namespace std;

char a[100][100];
int m,n;
int deposits;
int di[]={-1,-1,-1,0,0,1,1,1,};
int dj[]={-1,0,1,-1,1,-1,0,1,};

int isValid(int i,int j)
{
	if(i>=0&&i<m&&j>=0&&j<n)return 1;
	return 0;
}

void fill(int i, int j)
{
	a[i][j]='x';
	for(int k=0;k<8;k++){
		int ii=i+di[k];
		int jj=j+dj[k];
		if(isValid(ii,jj)&&a[ii][jj]=='@')
			fill(ii,jj);
	}
}

void debug()
{
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j];
		cout<<endl;
	}
}

int main()
{
	while(cin>>m>>n&&m){
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		deposits = 0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(a[i][j]=='@'){
					fill(i,j);
					deposits++;
				}
			
		cout<<deposits<<endl;
	}
	return 0;
}

