#include<iostream>
using namespace std;

int h[100][100];
int a[100][100];
int R,C;
int longest;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int f(int r, int c)
{
	if(a[r][c])return a[r][c];
	a[r][c]=1;
	for(int i=0;i<4;i++){
		int rr=r+dx[i];
		int cc=c+dy[i];
		if(rr>=0&&rr<R&&cc>=0&&cc<C&&h[rr][cc]<h[r][c])
			a[r][c]=max(f(rr,cc)+1,a[r][c]);
	}
	return a[r][c];
}	

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		string name;
		cin>>name>>R>>C;
//		cout<<name<<R<<C<<endl;
		for(int j=0;j<R;j++){
			for(int k=0;k<C;k++){
				cin>>h[j][k];
				a[j][k]=0;
//				cout<<h[j][k]<<((k==C-1)?"\n":" ");
			}
		}
		longest=0;
		for(int j=0;j<R;j++)
			for(int k=0;k<C;k++)
				longest=max(f(j,k),longest);
		cout<<name<<": "<<longest<<endl;
	}
	return 0;
}
		
