#include<iostream>
using namespace std;

int C;
int N;
int a[20];
int x[20];
int sum;

void init()
{
	for(int i=0;i<N;i++){
		cin>>a[i];
		x[i]=0;
	}
	sum=0;
}

void print()
{
	for(int i=0;i<N;i++)if(x[i])cout<<a[i]<<" ";
	cout<<"sum:"<<sum<<endl;
}

void dfs(int i,int c,int s)
{
	if(i==N){
		if(sum<C-c){
			sum=C-c;
			for(int i=N-1;i>=0;i--){
				x[i]=s&1;
				s>>=1;
			}
		}
	}else{
		dfs(i+1,c,(s<<1)|0);
		if(c>=a[i])dfs(i+1,c-a[i],(s<<1)|1);
	}
}

int main()
{
	while(cin>>C>>N){
		init();
		dfs(0,C,0);
		print();
	}
	return 0;
}

