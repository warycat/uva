#include<iostream>
#include<cstdio>
using namespace std;

int n;
int m;
int a[8];
string function;
string vva;

char sTree()
{
	int x=0;
	int v=0;
	for(int i=0;i<n;i++){
		x*=2;
		x+=vva[a[i]]-'0';
	}
	return function[x];
}

int main()
{
	int tc=0;
	while(cin>>n&&n){
		printf("S-Tree #%d:\n",++tc);
		for(int i=0;i<n;i++){
			char c;
			cin>>c;//x
			cin>>c;//?
			a[i]=c-'1';
		}
//		printT();
		cin>>function;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>vva;
			cout<<sTree();
		}
		cout<<endl;
		cout<<endl;
	}
	return 0;
}



