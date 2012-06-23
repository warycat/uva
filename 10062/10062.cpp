#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int cnt[256];
string s;
int n;
struct box{
	int ascii;
	int freq;
};

struct box a[256];

void clear()
{
	n=0;
	for(int i=0;i<256;i++)cnt[i]=0;
}

int cmp(struct box *p, struct box *q)
{
	int t;
	if(t=p->freq-q->freq)return t;
	return q->ascii-p->ascii;
}

void freq()
{
	for(int i=0;i<s.size();i++)cnt[s[i]]++;
	for(int i=32;i<128;i++)if(cnt[i]){
		struct box t = {i,cnt[i]};
		a[n++]=t;
	}
	qsort(a,n,sizeof(struct box),(int(*)(const void*,const void*))cmp);
}

void print()
{
	for(int i=0;i<n;i++)cout<<a[i].ascii<<" "<<a[i].freq<<endl;
}

int main()
{
	int t;
	int tc=0;
	while(getline(cin,s)){
//		if(s=="")continue;
		clear();
		freq();
		if(tc++)cout<<endl;
		print();
	}
	return 0;
}
