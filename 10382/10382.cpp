#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int n;
struct sprinkler{
	double l;
	double r;
}a[10000];

int m;

int w;
int l;

void debug()
{
	for(int i=0;i<m;i++)
		cout<<a[i].l<<" "<<a[i].r<<endl;
	cout<<endl;
}

int cmp(struct sprinkler* p, struct sprinkler *q)
{
	return p->l - q->l;
}

int main()
{
	while(cin>>n>>l>>w){
		double r,x;
		m = 0;
		for(int i=0;i<n;i++){
			cin>>x>>r;
			double d = r*r-0.25*w*w;
			if (d<=0) continue;
			d = sqrt(d);
			a[m].l = x-d;
			a[m].r = x+d;
			m++;
		}
		qsort(a,m,sizeof(a[0]),(int(*)(const void*,const void*))cmp);
		//debug();
		double left = 0;
		double right = 0;
		int cnt = 1;
		int i;
		for(i=0;i<m;i++){
			if(a[i].l<=left){
				right = max(right, a[i].r);
			}else{
				if(right<a[i].l)break;
				left = right;
				cnt++;
				i--;
			}
		}
		if( right >= l)
			cout<<cnt<<endl;
		else
			cout<< -1 <<endl;
	}
	return 0;
}

