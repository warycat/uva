#include<iostream>
#include<cstdio>
using namespace std;

struct list{
	list() : v(),mark(),edge() {}
	struct vertex *v;
	int mark;
	struct list *edge;
};

struct vertex{
	vertex() :visit(-1), edge() { }
	int visit;
	struct list *edge;
};

struct cross{
	cross() : slash(), up(), left(), right(), down() {}
	char slash;
	struct vertex *up;
	struct vertex *left;
	struct vertex *right;
	struct vertex *down;
};

struct cross a[75][75];
int w,h;
int cnt;
int cycle;
int cycleLength;

void connect(struct vertex *a, struct vertex *b)
{
	struct list *aList = new list;
	struct list *bList = new list;
	aList->v = b;
	aList->edge=a->edge;
	bList->v = a;
	bList->edge=b->edge;
	a->edge=aList;
	b->edge=bList;
}


void buildGraph()
{
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			if(i==0)a[i][j].up = new vertex;
			else a[i][j].up = a[i-1][j].down;
			if(j==0)a[i][j].left = new vertex;
			else a[i][j].left = a[i][j-1].right; 
			a[i][j].right = new vertex;
			a[i][j].down = new vertex;
		}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(a[i][j].slash=='/'){
				connect(a[i][j].left,a[i][j].up);
				connect(a[i][j].right,a[i][j].down);
			}else if(a[i][j].slash=='\\'){
				connect(a[i][j].left,a[i][j].down);
				connect(a[i][j].right,a[i][j].up);
			}
}

void mark(struct vertex *p,struct vertex *q)
{
	for(struct list *e=p->edge;e;e=e->edge)
		if(e->v==q)
			e->mark++;
	for(struct list *e=q->edge;e;e=e->edge)
		if(e->v==p)
			e->mark++;
}

bool isMarked(struct vertex *p, struct vertex *q)
{
	bool m = false;
	for(struct list *e=p->edge;e;e=e->edge)
		if(e->v==q){
			if(e->mark)m = true;
			else e->mark++;
		}
	for(struct list *e=q->edge;e;e=e->edge)
		if(e->v==p){
			if(e->mark)m = true;
			else e->mark++;
		}
	return m;
}


void traverseR(struct vertex *p)
{
	if(p->visit!=-1)return;
	p->visit=cnt++;
	for(struct list *e=p->edge;e;e=e->edge)
		if(e->v->visit==-1){
			mark(p,e->v);
			traverseR(e->v);
		}else if(!isMarked(e->v,p)){
			cycle++;
			cycleLength =  max(cycleLength , p->visit - e->v->visit + 1);
		}

}
		
void traverseGraph()
{
	cnt = 0;
	cycle = 0;
	cycleLength = 0;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			traverseR(a[i][j].up);
			traverseR(a[i][j].left);
			traverseR(a[i][j].right);
			traverseR(a[i][j].down);
		}
}

void printGraph()
{
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			printf("|%2d %2d %2d %2d|"	,a[i][j].left->visit
							,a[i][j].up->visit
							,a[i][j].down->visit
							,a[i][j].right->visit);
		printf("\n");
	}
}

int main()
{
	int maze = 0;
	while(cin>>w>>h&&w&&h){
		char c;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>c;
				a[i][j].slash=c;
			}
		}
		buildGraph();
		traverseGraph();
//		printGraph();
		printf("Maze #%d:\n",++maze);
		if(cycle)
			printf("%d Cycles; the longest has length %d.\n",cycle,cycleLength);
		else
			printf("There are no cycles.\n");
		printf("\n");

	}
	return 0;
}


