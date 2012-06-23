#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX_Q 50000000

int last[35];
unsigned long maskl[35];
unsigned long maskr[35];
int N;
int M;
int best;

void dfs(int l, int k, unsigned long sl, unsigned long sr)
{
	if(l==N){
		if (N<32){
			if(sr == (1<<N)-1)
				best=min(k,best);
		}else{
			if(((sl == (1<<(N-32))-1)) && (sr == -1)){
				best=min(k,best);
			}
		}
	}else{
		bool cut = false;	
		for(int i=0;i<=l;i++){
			if(i<32){
				if(!(sr & (1<<i)) && last[i]==l){
					cut = true;
					break;
				}
			}else{
				if(!(sl & (1<<(i-32))) && last[i]==l){
					cut = true;
					break;
				}
			}
		}
		if(!cut)dfs(l+1,k,sl,sr);
		unsigned long tl = sl | maskl[l];
		unsigned long tr = sr | maskr[l];
		if(tl!=sl || tr!=sr)
			dfs(l+1,k+1,tl,tr);
	}
}

void printmask(unsigned long m)
{
	for(int i=31;i>=0;i--)
		if(m&(1<<i))printf("1");
		else printf("0");
}

void debug()
{
	for(int i=0;i<N;i++){
		printmask(maskl[i]);
		printf(" ");
		printmask(maskr[i]);
		printf("\n");
	}
}

int main()
{
	while(cin>>N>>M){
		if(N==0&&M==0)break;
		memset(maskl,0,sizeof(maskl));
		memset(maskr,0,sizeof(maskr));
		int u;
		int v;
		for(int i=0;i<N;i++){
			last[i]=i;
			if(i<32){
				maskr[i]|=1<<i;
			}else{
				maskl[i]|=1<<(i-32);
			}
		}
		for(int i=0;i<M;i++){
			cin>>u>>v;
			u--;
			v--;
			last[u]=max(last[u],v);
			last[v]=max(last[v],u);
			if(u<32){
				maskr[v]|=1<<u;
			}else{
				maskl[v]|=1<<(u-32);
			}
			if(v<32){
				maskr[u]|=1<<v;
			}else{
				maskl[u]|=1<<(v-32);
			}
		}
		best = N;
		dfs(0,0,0,0);
		cout<<best<<endl;

	}
	return 0;
}
