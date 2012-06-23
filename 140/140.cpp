#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int adj[26][26];
int degree[26];
int a[8];
int ba[8];
int best;
int n;

void graphInit()
{
	memset(adj,0,sizeof(adj));
	memset(degree,0,sizeof(degree));
}

void addEdge(int u, int v)
{
	adj[u][v]++;
	adj[v][u]++;
	degree[v]++;
	degree[u]++;
}

void printGraph()
{
	for(int i=0;i<26;i++){
		if(degree[i]){
			cout<<(char)('A'+i)<<": ";
			for(int j=0;j<26;j++){
				if(adj[i][j])cout<<(char)('A'+j);
			}
			cout<<endl;
		}
	}
}

void collect()
{
	n = 0;
	for(int i=0;i<26;i++){
		if(degree[i])a[n++]=i;
	}
}

int bandwidth()
{
	int m = 0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(adj[a[i]][a[j]])m = max(m,j-i);
	return m;
}

void permute(int k)
{
	if(k==n){
		int t = bandwidth();
		if(t<best){
			best = t;
			memcpy(ba,a,sizeof(a));
		}
	}
	for(int i=k;i<n;i++){
		swap(a[k],a[i]);
		permute(k+1);
		swap(a[k],a[i]);
	}
}

int main()
{
	string s;
	while(getline(cin,s)&&s!="#"){
		graphInit();
		int ss = s.size();
		int u;
		int v;
		char pc,c;
		pc = ';';
		for(int i=0;i<ss;i++){
			if(i)pc = c;
			c = s[i];
			if(pc==';'){
				u = c - 'A';
			}else{
				if(isalpha(c)) {
					v = c - 'A';
					addEdge(u,v);
				}
			}
		}
		collect();
		best = n;
		permute(0);
		for(int i=0;i<n;i++)
			cout<<(char)('A'+ba[i])<<" ";
		cout<<"-> "<<best<<endl;
	}
	return 0;
}
