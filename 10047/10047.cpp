#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char map[25][25];
int M,N;
int reachable;
int min_time;
int a[25][25][4][5];
char pd[]={'^','>','v','<',};

enum direction{
	North,
	East,
	South,
	West,
};

struct state{
	int i;
	int j;
	int d;
	int t;
	int c;
};

struct state T;

struct state queue[2500];
int head;
int tail;

void init()
{
	head = tail = 0;
}

bool empty()
{
	return head==tail;
}

void print(struct state s)
{
	printf("%d %d %d %d\n",s.i,s.j,s.d,s.t);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
			if(i==s.i&&j==s.j)cout<<pd[s.d];
			else cout<<map[i][j];
		cout<<endl;
	}
	cout<<endl;
}

void enQueue(struct state s)
{
	a[s.i][s.j][s.d][s.c]=1;
	queue[tail++]=s;
	tail%=2500;
}

struct state deQueue()
{
	struct state t = queue[head++];
	head%=2500;
//	print(t);
	return t;
}

bool isValid(struct state s)
{
	if(s.i<0||s.i>=M||s.j<0||s.j>=N)return false;
	if(map[s.i][s.j]=='#')return false;
	if(a[s.i][s.j][s.d][s.c])return false;
	return true;
}

struct state forward(struct state s)
{
	switch (s.d){
		case North:
			s.i--;
			break;
		case East:
			s.j++;
			break;
		case South:
			s.i++;
			break;
		case West:
			s.j--;
			break;
	}
	s.t++;
	s.c++;
	s.c%=5;
	return s;
}

struct state left(struct state s)
{
	s.d = (s.d+4-1)%4;
	s.t++;
	return s;
}

struct state right(struct state s)
{
	s.d = (s.d+4+1)%4;
	s.t++;
	return s;
}

bool end(struct state s)
{
	return (T.i==s.i&&T.j==s.j&&(s.c==0));
}

int cycle()
{
	init();
	memset(a,0,sizeof(a));
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++){
			if(map[i][j]=='S'){
				struct state s;
				s.i = i;
				s.j = j;
				s.d = North;
				s.t = 0;
				s.c = 0;
				enQueue(s);
			}
			if(map[i][j]=='T'){
				T.i = i;
				T.j = j;
			}
		}
	while(!empty()){
		struct state s = deQueue();
		if(end(s)){
			min_time = s.t;
			return 1;
		}
		struct state f = forward(s);
		struct state l = left(s);
		struct state r = right(s);
		if(isValid(f))enQueue(f);
		if(isValid(l))enQueue(l);
		if(isValid(r))enQueue(r);
	}
	return 0;
}


int main()
{
	int tc = 0;
	while(cin>>M>>N&&M&&N){
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				cin>>map[i][j];
		reachable = cycle();
		if(tc)cout<<endl;
		tc++;
		cout<<"Case #"<<tc<<endl;
		if(reachable)
			cout<<"minimum time = "<<min_time<<" sec"<<endl;
		else 
			cout<<"destination not reachable"<<endl;
	}
	return 0;
}
