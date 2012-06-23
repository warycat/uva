#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int a,b,c,d;

int m[201][201][201];

void dfs(int aa, int bb, int cc, int v)
{
	if(m[aa][bb][cc]==-1 || m[aa][bb][cc]>v){
		m[aa][bb][cc]=v;
		int xa = a - aa;
		int xb = b - bb;
		int xc = c - cc;
		int dv;
		if(aa!=0){
			if(aa>=xb)
				dv = xb;
			else
				dv = aa;
			dfs(aa-dv,bb+dv,cc,v+dv);
			if(aa>=xc)
				dv = xc;
			else
				dv = aa;
			dfs(aa-dv,bb,cc+dv,v+dv);
		}
		if(bb!=0){
			if(bb>=xa)
				dv = xa;
			else
				dv = bb;
			dfs(aa+dv,bb-dv,cc,v+dv);
			if(bb>=xc)
				dv = xc;
			else
				dv = bb;
			dfs(aa,bb-dv,cc+dv,v+dv);
		}
		if(cc!=0){
			if(cc>=xa)
				dv = xa;
			else
				dv = cc;
			dfs(aa+dv,bb,cc-dv,v+dv);
			if(cc>=xb)
				dv = xb;
			else
				dv = cc;
			dfs(aa,bb+dv,cc-dv,v+dv);
		}
	}
}

void debug()
{
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				cout<<m[i][j][k];
				cout<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

int diff(int p, int q)
{
	return max(p-q,q-p);
}

int closest(int old_d)
{
	int new_d=c;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				if(m[i][j][k]!=-1){
					int di = diff(i,old_d);
					int dj = diff(j,old_d);
					int dk = diff(k,old_d);
					if(di<diff(new_d,old_d))new_d=i;
					if(dj<diff(new_d,old_d))new_d=j;
					if(dk<diff(new_d,old_d))new_d=k;
				}
			}
		}
	}
	return new_d;
}

int least()
{
	int value = INT_MAX;
	for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++)
			for(int k=0;k<=c;k++)
				if(m[i][j][k]!=-1 && (i==d||j==d||k==d))
					value = min(m[i][j][k],value);
	return value;
}

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>a>>b>>c>>d;
		memset(m,-1,sizeof(m));
		dfs(0,0,c,0);
//		debug();
		d = closest(d);
		cout<<least()<<" "<<d<<endl;
	}
	return 0;
}
