#include<iostream>
using namespace std;

string s;
int id;
int a[32];
int p[32];
int n;
int cnt;

int cell(int id, int left, int middle, int right)
{
	int v = id & (1 << ( (left << 2) | (middle << 1) | right));
	if(v)return 1;
	return 0;
}

void debug()
{
	for(int i=0;i<n;i++)cout<<p[i];
	cout<<endl;
	for(int i=0;i<n;i++)cout<<a[i];
	cout<<endl;
}

void searchR(int k)
{
	if(cnt)return;
	if(k==n){
		if(cell(id,p[n-2],p[n-1],p[0])!=a[n-1])
			return;
		if(cell(id,p[n-1],p[0],p[1])!=a[0])
			return;
//		debug();
		cnt++;
	}
	for(int i=0;i<2;i++){
		p[k]=i;
		if(k>=2&&cell(id,p[k-2],p[k-1],p[k])!=a[k-1])
			continue;
		searchR(k+1);
	}
}


bool reachable()
{
	cnt = 0;
	searchR(0);
	if(cnt)return true;
	else return false;
}

int main()
{
	while(cin>>id>>n>>s){
		int ss = s.size();
		for(int i=0;i<ss;i++)a[i]=s[i]-'0';
		if(reachable())cout<<"REACHABLE"<<endl;
		else cout<<"GARDEN OF EDEN"<<endl;
	}
	return 0;
}
