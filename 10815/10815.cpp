#include<iostream>
#include<cstdio>
using namespace std;

string a[5000];
int p[5000];
int n=0;
string t="";

void insert(string s)
{
	for(int i=0;i<n;i++)if(a[i]==s)return;
	a[n]=s;
	p[n]=n;
	n++;
	for(int i=n-1;i>0;i--)
		if(a[p[i-1]]>a[p[i]])swap(p[i-1],p[i]);
		else break;
}

int main()
{
	char c;
	while((c=getchar())!=EOF){
		if(isalpha(c)){
			c=tolower(c);
			t.push_back(c);
		}else{
			if(t!="")insert(t);
			t="";
		}
	}
	for(int i=0;i<n;i++)cout<<a[p[i]]<<endl;
	return 0;
}
			

