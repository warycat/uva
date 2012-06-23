#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int n;
struct box{
	int x;
	int y;
	int z;
};

struct box a[90];
int h[90];
int best;

void print()
{
	for(int i=0;i<3*n;i++){
		printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);
	}
	printf("\n");
}

int cmp(struct box *p, struct box *q)
{
	int t=p->x-q->x;
	if(t)return -t;
	t=p->y-q->y;
	if(t)return -t;
	t=p->z-q->z;
	return t;
}

void LIS()
{
	best=0;
	for(int i=0;i<3*n;i++){
		h[i]=a[i].z;
		int sum=0;
		for(int j=0;j<i;j++){
			if(a[i].x<a[j].x&&a[i].y<a[j].y){
				sum=max(sum,h[j]);
//				printf("%d %d %d\n",i,j,sum);
			}
		}
		h[i]+=sum;
//		printf("%d %d %d %d\n",a[i].x,a[i].y,a[i].z,h[i]);
	}
	for(int i=0;i<3*n;i++)best=max(best,h[i]);
}

int main()
{
	int tc=0;
	while(cin>>n&&n){
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i*3].x=x;
			a[i*3].y=y;
			a[i*3].z=z;
			a[i*3+1].x=y;
			a[i*3+1].y=z;
			a[i*3+1].z=x;
			a[i*3+2].x=z;
			a[i*3+2].y=x;
			a[i*3+2].z=y;
		}
		for(int i=0;i<3*n;i++){
			if(a[i].x<a[i].y)swap(a[i].x,a[i].y);
		}
		qsort(a,3*n,sizeof(a[0]),(int(*)(const void*,const void*))cmp);
//		print();
		LIS();
		printf("Case %d: maximum height = %d\n",++tc,best);
	}
	return 0;
}


