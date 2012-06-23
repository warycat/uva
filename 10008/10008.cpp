#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
using namespace std;

struct count{
	char c;
	int v;
}a[26];
int n;

int cmp(struct count *p, struct count *q)
{
	int t = - p->v + q->v;
	if(t)return t;
	t = p->c - q->c;
	return t;
}

void debug()
{
	for(int i=0;i<26;i++)
		if(a[i].v)
			printf("%c %d\n",a[i].c,a[i].v);
}

int main()
{
	char c;
	memset(a,0,sizeof(a));
	while((c=getchar())!=EOF){
		if(isalpha(c)){
			c = toupper(c);
			a[c-'A'].c=c;
			a[c-'A'].v++;
		}
	}
	qsort(a,26,sizeof(a[0]),(int (*)(const void *, const void *))cmp);
	debug();
	return 0;
}
