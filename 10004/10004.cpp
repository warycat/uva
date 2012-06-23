#include<iostream>
#include<cstring>
using namespace std;

int d[200];
int color[200];
int cnt;
int V;
int E;
int edge[100000][2];
struct list{
	list(){}
	list(int a,struct list *b):v(a),next(b){}
	int v;
	struct list *next;
	void *operator new(size_t);
} pool[100000];

int pool_size;
int conflict;

void *list::operator new(size_t)
{
	return pool + pool_size++;
}

struct list * adj[200];

void addEdge(int u, int v)
{
	struct list *pu = new list(u,adj[v]);
	adj[v]=pu;
	struct list *pv = new list(v,adj[u]);
	adj[u]=pv;
}

void init()
{
	conflict = 0;
	cnt = 0;
	pool_size = 0;
	memset(adj,0,sizeof(adj));
	memset(d,-1,sizeof(d));
	memset(color,0,sizeof(color));
}

void dfs(int v,int c)
{
	if(d[v]==-1){
		d[v]=cnt++;
		color[v]=c;
		for(struct list *p=adj[v];p;p=p->next){
			int u = p->v;
			dfs(u,!c);
		}
	}
}

void debug()
{
	for(int i=0;i<V;i++)
		cout<<d[i]<<" "<<color[i]<<endl;
	cout<<endl;
}

int main()
{
	while(cin>>V&&V){
		cin>>E;
		init();
		for(int i=0;i<E;i++){
			int u,v;
			cin>>u>>v;
			addEdge(u,v);
			edge[i][0]=u;
			edge[i][1]=v;
		}
		for(int i=0;i<V;i++)
			dfs(i,0);
		for(int i=0;i<E;i++){
			int u,v;
			u = edge[i][0];
			v = edge[i][1];
			if(color[u]==color[v])conflict++;
		}
		cout<<(conflict?"NOT BICOLORABLE.":"BICOLORABLE.")<<endl;
	}
	return 0;
}

