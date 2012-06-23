#include<iostream>
#include<cstring>

using namespace std;

char m[100][64000];
int a[100];
char o[100];
int p;
int x;

void debug()
{
	for(int i=0;i<p;i++)
		cout<<a[i]<<o[i];
	cout<<x<<endl;
}

bool dfs(int l, int v)
{
	if(m[l][v+32000]==0){
		m[l][v+32000]++;
	}else{
		return false;
	}
	if(l==p-1){
		o[l]='=';
		if(v==x){
			debug();
			return true;
		}
		return false;
	}
	int t;
	t = v + a[l+1];
	if(t<32000){
		o[l]='+';
		if(dfs(l+1,t))
			return true;
	}
	t = v - a[l+1];
	if(t>-32000){
		o[l]='-';
		if(dfs(l+1,t))
			return true;
	}
	t = v * a[l+1];
	if(t<32000&&t>-32000){
		o[l]='*';
		if(dfs(l+1,t))
			return true;
	}
	t = v / a[l+1];
	if(v % a[l+1] == 0){
		o[l]='/';
		if(dfs(l+1,t))
			return true;
	}
	return false;
}
	

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>p;
		for(int j=0;j<p;j++)
			cin>>a[j];
		cin>>x;
		memset(m,0,sizeof(m));
		if(!dfs(0,a[0]))
			cout<<"NO EXPRESSION"<<endl;
	}
	return 0;
}

