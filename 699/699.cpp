#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node{
	int v;
	int p;
	node *l;
	node *r;
};

struct leaf{
	int v;
	int p;
}a[1000000];
int n;

node *readTree(int p)
{
	int x;
	node *t;
	if(cin>>x&&x==-1)return NULL;
	else{
		t = new node;
		t->v = x;
		t->p = p;
		t->l = readTree(p-1);
		t->r = readTree(p+1);
	}
	return t;
}

void printTree(node *p)
{
	if(p){
		printTree(p->l);
		printf("%d ",p->v);
		printTree(p->r);
	}
}

void deleteTree(node *p)
{
	if(p){
		deleteTree(p->l);
		deleteTree(p->r);
		a[n].p=p->p;
		a[n].v=p->v;
		n++;
		delete p;
	}
}

int cmp(struct node *a, struct node *b)
{
	return a->p - b->p;
}

int main()
{
	node *t;
	int tc = 0;
	for(int i=0;t=readTree(0);i++){
		printf("Case %d:\n",++tc);
		n=0;
		deleteTree(t);
		qsort(a,n,sizeof(a[0]),(int(*)(const void *, const void *))cmp);
		int p = a[0].p;
		int v = 0;
		for(int i=0;i<n;i++){
			if(a[i].p==p)v+=a[i].v;
			else {
				cout<<v<<" ";
				v = a[i].v;
				p = a[i].p;
			}
		}
		cout<<v<<endl;
		cout<<endl;
	}
	return 0;
}
