#include<iostream>
#include<iomanip>
using namespace std;

int s[8][8];
int a[8][8];
int p[8];
int d[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1}};
int best;

void init()
{
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>s[i][j];
			a[i][j]=0;
		}
	}
	best=0;
}

void put(int r,int c,int v)
{
	for(int i=0;i<8;i++){
		int rr=r;
		int cc=c;
		while(rr>=0&&rr<8&&cc>=0&&cc<8){
			a[rr][cc]+=v;
			rr+=d[i][0];
			cc+=d[i][1];
		}
	}
}

void dfs(int l)
{
	if(l==8){
		int sum=0;
		for(int i=0;i<8;i++)sum+=s[i][p[i]];
		if(sum>best)best=sum;
	}else{
		for(int i=0;i<8;i++){
			if(a[l][i]==0){
				p[l]=i;
				put(l,i,1);
				dfs(l+1);
				put(l,i,-1);
			}
		}
	}
}


int main()
{
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		init();
		dfs(0);
		cout<<setw(5)<<best<<endl;
	}
	return 0;
}
