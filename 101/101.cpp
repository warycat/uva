#include <iostream>
#include <cstdlib>

using namespace std;

struct block{
	int no;
	struct block *up;
	struct block *down;
};

struct block heads[25];
struct block tails[25];
struct block blocks[25];

string s1, s2;
int n;
int a, b;

void initposition(struct block *t)
{
	struct block *next;
	while(t! = t->up){
		next=t->up;
		t->down->up=t->up;
		t->up->down=t->down;
		heads[t->no].up=tails[t->no].down=t;
		t->down=&heads[t->no];
		t->up=&tails[t->no];
		t=next;
	}
}

void command()
{
	struct block *ta=&blocks[a];
	struct block *tb=&blocks[b];
//	cout<<s1<<a<<s2<<b<<endl;
	while(ta->up!=ta)ta=ta->up;
	while(tb->up!=tb)tb=tb->up;
	if(ta==tb)return;
	struct block *pa=&blocks[a];
	struct block *pb=&blocks[b];
	struct block *t;
	if(s1=="move"&&s2=="onto"){
//		cout<<s1<<a<<s2<<b<<endl;
		initposition(pa->up);
		initposition(pb->up);
		pa->down->up=pa->up;
		pa->up->down=pa->down;
		pb->up->down=pa;
		pa->up=pb->up;
		pa->down=pb;
		pb->up=pa;
	}
	if(s1=="move"&&s2=="over"){
//		cout<<s1<<a<<s2<<b<<endl;
		initposition(pa->up);
		pa->down->up=pa->up;
		pa->up->down=pa->down;
		pa->down=tb->down;
		tb->down->up=pa;
		tb->down=pa;
		pa->up=tb;
	}
	if(s1=="pile"&&s2=="onto"){
		initposition(pb->up);
//		cout<<s1<<a<<s2<<b<<endl;
		struct block *pc = ta->down;
		ta->down=pa->down;
		pa->down->up=ta;
		pa->down=pb;
		pc->up=pb->up;
		pb->up->down=pc;
		pb->up=pa;
	}

	if(s1=="pile"&&s2=="over"){
//		cout<<s1<<a<<s2<<b<<endl;
		struct block *pc = ta->down;
		struct block *pd = tb->down;
		ta->down = pa->down;
		pa->down->up=ta;
		pa->down=pd;
		pc->up=tb;
		pd->up=pa;
		tb->down=pc;
	}
}

void print()
{
	for(int i=0;i<n;i++){
		cout<<i<<":";
		struct block *p;
		for(p=heads[i].up;p!=&tails[i];p=p->up)
			cout<<" "<<p->no;
		cout<<endl;
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		heads[i].up=&blocks[i];
		heads[i].down=&heads[i];
		tails[i].up=&tails[i];
		tails[i].down=&blocks[i];
		blocks[i].no=i;
		blocks[i].up=&tails[i];
		blocks[i].down=&heads[i];
	}
	while(1){
		cin>>s1>>a>>s2>>b;
		if(s1=="quit"){
			print();
			return 0;
		}else{
			command();
//			print();
		}
	}
	return 0;
}


