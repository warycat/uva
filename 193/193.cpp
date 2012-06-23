#include<iostream>
#include<cstring>
using namespace std;

int adj[100][100];
int V;
int E;
int color[100];
int black[100];
int best;
int best_color[100];

enum color_t{
	WHITE,
	BLACK,
};


void graphInit()
{
	memset(adj,0,sizeof(adj));
	memset(color,0,sizeof(color));
	memset(black,0,sizeof(black));
	V=0;
	E=0;
}

void addEdge(int u, int v)
{
	adj[u][v]++;
	adj[v][u]++;
}

void printGraph()
{
	for(int i=0;i<V;i++){
		cout<<i;
		cout<<(color[i]?"#: ":" : ");
		for(int j=0;j<V;j++)
			if(adj[i][j])
				cout<<j;
		cout<<endl;
	}
	cout<<endl;
}


void search(int k)
{
	if(k==V){
		int sum = 0;
		for(int i=0;i<V;i++)
			if(color[i]==BLACK)sum++;
		if(sum>best){
			best = sum;
			memcpy(best_color,color,sizeof(color));
		}
	}else{
		if(!black[k]){
			color[k]=BLACK;
			for(int i=0;i<V;i++)
				if(adj[k][i])black[i]++;
			search(k+1);
			for(int i=0;i<V;i++)
				if(adj[k][i])black[i]--;
		}
		color[k]=WHITE;
		search(k+1);
	}
}


int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		graphInit();
		cin>>V>>E;
		for(int j=0;j<E;j++){
			int u,v;
			cin>>u>>v;
			addEdge(u-1,v-1);
		}
		search(0);
		cout<<best<<endl;
		for(int i=0;i<V;i++)
			if(best_color[i]==BLACK)
				cout<<i+1<<(--best?' ':'\n');
	}
	return 0;
}
