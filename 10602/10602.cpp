#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct word{
	string s;
	int pre;
};

struct word a[100];
int N;


int cmp(struct word *p, struct word *q)
{
	int t = - (p->pre - q->pre);
	if(t)return t;
	return strcmp((p->s).c_str(),(q->s).c_str());
}


int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		for(int j=0;j<N;j++){
			cin>>a[j].s;
			a[j].pre = 0;
			int len = min(a[j].s.size(),a[0].s.size());
			for(int k=0;k<len;k++){
				if(a[j].s[k]==a[0].s[k])
					a[j].pre++;
				else 
					break;
			}
		}
		qsort(a,N,sizeof(a[0]),(int(*)(const void * ,const void *))cmp);
		int X = a[0].s.size();
		for(int j=1;j<N;j++){
			int len = min(a[j-1].s.size(),a[j].s.size());
			int v = -1;
			for(int k=0;k<len;k++)
				if(a[j-1].s[k]==a[j].s[k])
					v=k;
				else
					break;
			int dx =a[j].s.size() - 1 - v;
			X+=dx;
		}
		cout<<X<<endl;
		for(int j=0;j<N;j++)
			cout<<a[j].s<<endl;
	}
	return 0;
}
