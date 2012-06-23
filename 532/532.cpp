#include<iostream>
using namespace std;
#include<cstdio>
#define MAX_N 30000

int L,R,C;
char a[30][30][30];

struct triple{
	int l;
	int r;
	int c;
	int m;
};

struct triple queue[ MAX_N ];

int head;
int tail;

bool empty()
{
	return head==tail;
}

void enqueue(struct triple v)
{
	queue[tail++]=v;
	tail %= MAX_N;
}

struct triple dequeue()
{
	struct triple t = queue[head++];
	head %= MAX_N;
	return t;
}


void debug()
{
	for(int i=0;i<L;i++){
		for(int j=0;j<R;j++){
			for(int k=0;k<C;k++)
				cout<<a[i][j][k];
			cout<<endl;
		}
		cout<<endl;
	}
}

bool isValid(struct triple v)
{
	if(v.l<0||v.l>=L)return false;
	if(v.r<0||v.r>=R)return false;
	if(v.c<0||v.c>=C)return false;
	char c = a[v.l][v.r][v.c];
	if(c=='.'){
		a[v.l][v.r][v.c]='#';
		return true;
	}
	if(c=='E')return true;
	return false;
}	


int bfs()
{
	struct triple u;
	while(!empty()){
		struct triple v = dequeue();
		char c = a[v.l][v.r][v.c];
		if(c == 'E')return v.m;
		u=v;
		u.l++;
		u.m++;
		if(isValid(u))enqueue(u);
		u=v;
		u.l--;
		u.m++;
		if(isValid(u))enqueue(u);
		u=v;
		u.r++;
		u.m++;
		if(isValid(u))enqueue(u);
		u=v;
		u.r--;
		u.m++;
		if(isValid(u))enqueue(u);
		u=v;
		u.c++;
		u.m++;
		if(isValid(u))enqueue(u);
		u=v;
		u.c--;
		u.m++;
		if(isValid(u))enqueue(u);
	}
	return 0;
}



int escape()
{
	for(int i=0;i<L;i++)
		for(int j=0;j<R;j++)
			for(int k=0;k<C;k++)
				if(a[i][j][k]=='S'){
					struct triple s = {i,j,k,0};
					head=tail=0;
					enqueue(s);
					return bfs();
				}
	return 0;
}
					

int main()
{
	while(cin>>L>>R>>C&&L&&R&&C){
		for(int i=0;i<L;i++)
			for(int j=0;j<R;j++)
				for(int k=0;k<C;k++)
					cin>>a[i][j][k];
		int minute = escape();
		if(minute)
			printf("Escaped in %d minute(s).\n",minute);
		else 
			printf("Trapped!\n");
	//	debug();
	}
	return 0;
}
