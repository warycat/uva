#include<iostream>
using namespace std;

struct quadtree{
	char type;
	int size;
	quadtree * trees[4];
};

quadtree *readtree(int size)
{
	char c;
	cin>>c;
	quadtree *p= new quadtree;
	p->type=c;
	p->size=size;
	if(p->type=='p'){
		p->trees[0]=readtree(size/4);
		p->trees[1]=readtree(size/4);
		p->trees[2]=readtree(size/4);
		p->trees[3]=readtree(size/4);
	}
	return p;
}

void printtree(quadtree *p)
{
	cout<<p->type<<endl;
	if(p->type=='p'){
		printtree(p->trees[0]);
		printtree(p->trees[1]);
		printtree(p->trees[2]);
		printtree(p->trees[3]);
	}
}

int black(quadtree *p)
{
//	cout<<"black "<<p->size<<endl;
	if(p->type=='f')return p->size;
	if(p->type=='e')return 0;
	int sum=0;
	for(int i=0;i<4;i++)sum+=black(p->trees[i]);
	return sum;
}

int add(quadtree *a, quadtree *b)
{
//	cout<<"add "<<a->size<<a->type<<b->type<<endl;
	if(a->type=='f'||b->type=='f')return a->size;
	if(a->type=='p'&&b->type=='p'){
		int sum = 0;
		for(int i=0;i<4;i++)sum+=add(a->trees[i],b->trees[i]);
		return sum;
	}
	if(a->type=='p'&&b->type=='e')return black(a);
	if(a->type=='e'&&b->type=='p')return black(b);
	return 0;
}	

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		struct quadtree *a = readtree(32*32);
		struct quadtree *b = readtree(32*32);
		cout<<"There are "<<add(a,b)<<" black pixels.\n";
	}
	return 0;
}
