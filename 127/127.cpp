#include<iostream>
#include<cstdio>
using namespace std;

struct node{
	struct node *down;
	int card;
};

struct pile{
	struct node *top;
	struct pile *left;
	struct pile *right;
};

char s[52];
char r[52];
struct node nodes[54];
struct pile piles[54];
struct pile *head;
struct pile *tail;
int n;

void printPiles()
{

	n=0;
	struct pile *p;
	for(p=head->right;p!=tail;p=p->right,n++);
	if(n==1)
		cout<<n<<" pile remaining:";
	else
		cout<<n<<" piles remaining:";
	for(p=head->right;p!=tail;p=p->right){
		int c=0;
		struct node *t;
		for(t=p->top;t;t=t->down)c++;
		cout<<" "<<c;
	}
	cout<<endl;
}

int moveable(struct pile *a, struct pile *b)
{
	char ra=r[a->top->card];
	char rb=r[b->top->card];
	char sa=s[a->top->card];
	char sb=s[b->top->card];
	if(ra==rb||sa==sb)return 1;
	return 0;
}

void move(struct pile *from, struct pile *to)
{
	struct node *t= from->top;
	from->top=t->down;
	if(from->top==NULL){
		from->left->right=from->right;
		from->right->left=from->left;
	}
	t->down=to->top;
	to->top=t;
}	

int getmove()
{
	struct pile *p=head->right;
	struct pile *p1,*p3;
	while(p!=tail){
		p1=p->left;
		p3=p1->left->left;
		if(p3!=head&&moveable(p3,p)){
			move(p,p3);
			return 1;
		}
		if(p1!=head&&moveable(p1,p)){
			move(p,p1);
			return 1;
		}
		p=p->right;
	}
	return 0;
}

void Accordian()
{
	head=&piles[0];
	head->left=head;
	head->right=&piles[1];
	tail=&piles[53];
	tail->left=&piles[52];
	tail->right=tail;
	for(int i=1;i<=52;i++){
		piles[i].top=&nodes[i];
		piles[i].left=&piles[i-1];
		piles[i].right=&piles[i+1];
		nodes[i].card=i-1;
		nodes[i].down=NULL;
	}
	while(getmove());
}

int main()
{
	int c;
	int i=0;
	while((c=getchar())!='#'){
		if(c==' '||c=='\n')continue;
		r[i]=c;
		s[i++]=getchar();
		if(i==52){
			Accordian();
			printPiles();
			i=0;
		}

	}
	return 0;
}
