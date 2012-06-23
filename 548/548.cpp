#include<iostream>
#include<sstream>
#include<climits>
using namespace std;

int ai[10000];
int ap[10000];
string s[2];
pair<int, int> least;

void tree(int i,int p,int n,int sum)
{
	int r = i;
	int child=0;
	sum += ai[r];
	while(r<=i+n-1&&ai[r]!=ap[p+n-1])r++;
	if(r-i>0){
		tree(i,p,r-i,sum);
		child++;
	}
	if(i+n-1-r>0){
		tree(r+1,p+r-i,i+n-1-r,sum);
		child++;
	}
	if(child==0)
		least = min(least, make_pair(sum, ai[r]));
}

int main()
{
	while(getline(cin,s[0])&&getline(cin,s[1])){
		if(s[0]=="")break;
		stringstream ss;
		ss.clear();
		ss.str(s[0]);
		int i;
		for(i=0;ss>>ai[i];i++);
		ss.clear();
		ss.str(s[1]);
		for(i=0;ss>>ap[i];i++);
		least=make_pair(INT_MAX, INT_MAX);
		tree(0,0,i,0);
		cout<<least.second<<endl;
	}
	return 0;
}
