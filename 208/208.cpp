#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int adj[21][21];
int degree[21];
int set[21];
int dfs[21];
int V;
int fire;
int route;
int a[21];

void graphInit()
{
	memset(adj,0,sizeof(adj));
	memset(degree,0,sizeof(degree));
	memset(set,0,sizeof(set));
	route=0;
	V=0;
}

void addEdge(int u, int v)
{
	V = max(V,max(u,v)+1);
	degree[v]++;
	degree[u]++;
	adj[u][v]++;
	adj[v][u]++;
}

void printRoute(int k)
{
	for(int i=0;i<k;i++){
		printf("%d ",a[i]+1);
	}
	printf("%d\n",fire+1);
}

void printGraph()
{
	for(int i=0;i<V;i++){
		cout<<i<<" "<<dfs[i]<<": ";
		for(int j=0;j<V;j++)
			if(adj[i][j])cout<<j;
		cout<<endl;
	}
	cout<<endl;
}

void dfsR(int u,int k)
{
	if(set[u]||dfs[u]!=-1)return;
	dfs[u]=k;
	for(int i=0;i<V;i++)
		if(adj[u][i])
			dfsR(i,k+1);
}


bool connected(int a, int b)
{
	memset(dfs,-1,sizeof(dfs));
	dfsR(a,0);
	if(dfs[b]==-1)return false;
	return true;
}
	
void search(int k,int u)
{
	set[u]++;
	if(u==fire){
		route++;
		printRoute(k);
	}else{
		a[k]=u;
		for(int i=0;i<V;i++){
			if(adj[u][i]&&!set[i]){
				if(connected(i,fire))search(k+1,i);
			}
		}
	}
	set[u]--;
}


int main()
{
	int tc = 0;
	while(cin>>fire){
		fire--;
		graphInit();
		int u,v;
		while(cin>>u>>v){
			if(u==0&&v==0)break;
			addEdge(u-1,v-1);
		}
	//	printGraph();	
		printf("CASE %d:\n",++tc);
		search(0,0);
		printf("There are %d routes from the firestation to streetcorner %d.\n",route,fire+1);
	}
	return 0;
}
		
