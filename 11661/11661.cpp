#include<iostream>
#include<cstdlib>
using namespace std;

int L;
string s;

int burger()
{
	int mind = L;
	int R = -1;
	int D = -1;
	for(int i=0;i<L;i++){
		if(s[i]=='Z')return 0;
		if(s[i]=='.')continue;
		if(s[i]=='R')R=i;
		if(s[i]=='D')D=i;
		if(D!=-1&&R!=-1&&abs(R-D)<mind)mind=abs(R-D);
	}
	return mind;
}

int main()
{
	while(cin>>L&&L){
		cin>>s;
		cout<<burger()<<endl;
	}
	return 0;
}

