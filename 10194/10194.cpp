#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char buf[1000];
char team[2][200];
int goal[2];
struct match{
	int t[2];
	int g[2];
}m[1000];
struct team{
	char name[200];
	int a,b,c,d,e,f,g,h,i;
}a[30];
int T;
int G;

int lookup(char *s)
{
	for(int i=0;i<T;i++)if(strcmp(s,a[i].name)==0)return i;
	printf("LOOKUP\n");
	while(1);
}

int mystrcmp(char *p,char *q)
{
	strcpy(team[0],p);
	strcpy(team[1],q);
	for(int i=0;team[0][i];i++)
		team[0][i]=tolower(team[0][i]);
	for(int i=0;team[1][i];i++)
		team[1][i]=tolower(team[1][i]);
	return strcmp(team[0],team[1]);
}

int cmp(struct team *p, struct team *q)
{
	int t;
	if(t=q->b-p->b)return t;
	if(t=q->d-p->d)return t;
	if(t=q->g-p->g)return t;
	if(t=q->h-p->h)return t;
	if(t=p->c-q->c)return t;
	return mystrcmp(p->name,q->name);
}


void score()
{
	for(int i=0;i<G;i++){
		int t0=m[i].t[0];
		int t1=m[i].t[1];
		int g0=m[i].g[0];
		int g1=m[i].g[1];
		a[t0].c++;
		a[t1].c++;
		a[t0].h+=g0;
		a[t1].h+=g1;
		a[t0].i+=g1;
		a[t1].i+=g0;
		if(g0>g1){
			a[t0].d++;
			a[t1].f++;
			a[t0].b+=3;
		}
		if(g0<g1){
			a[t0].f++;
			a[t1].d++;
			a[t1].b+=3;
		}
		if(g0==g1){
			a[t0].e++;
			a[t1].e++;
			a[t0].b+=1;
			a[t1].b+=1;
		}
	}
	for(int i=0;i<T;i++)a[i].g=a[i].h-a[i].i;
	qsort(a,T,sizeof(struct team),(int(*)(const void*,const void*))cmp);
}


int main()
{
	int tc;
	scanf("%d%*c",&tc);
	for(int i=0;i<tc;i++){
		if(i)printf("\n");
		scanf("%[^\n]%*c",buf);
		printf("%s\n",buf);
		scanf("%d%*C",&T);
//		printf("%d\n",T);
		for(int j=0;j<T;j++){
			scanf("%[^\n]%*c",a[j].name);
			a[j].a=a[j].b=a[j].c=a[j].d=a[j].e=0;
			a[j].f=a[j].g=a[j].h=a[j].i=0;
//			printf("%s\n",a[j].name);
		}
		scanf("%d%*c",&G);
		for(int j=0;j<G;j++){
			scanf("%[^#]#%d@%d#%[^\n]%*c",
				team[0],&goal[0],&goal[1],team[1]);
			for(int k=0;k<2;k++){
				m[j].t[k]=lookup(team[k]);
				m[j].g[k]=goal[k];
//				printf("%d %d\n",m[j].t[k],m[j].g[k]);
			}
//			printf("%s %d %d %s\n",team[0],goal[0],goal[1],team[1]);
		}
		score();
		for(int j=0;j<T;j++){
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				j+1,a[j].name,a[j].b,a[j].c,a[j].d,a[j].e,
				a[j].f,a[j].g,a[j].h,a[j].i);
		}
	}
	return 0;
}


