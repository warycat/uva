#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;

struct point{
	int x;
	int y;
};

struct point v[100];
int n;

int cmp(struct point *p, struct point *q)
{
	return p->x-q->x;
}

double slides()
{
	int j=0;
	double ha=0,hb=0,la,lb,ch=0;
	double sum=0;
	for(int i=n-2;i>=0;i--){
		if(v[i].y>ch){
			ha=v[i].y;
			hb=v[i+1].y;
			la=v[i].x;
			lb=v[i+1].x;
			double theta = atan((lb-la)/(ha-hb));
//			cout<<theta<<endl;
			sum+=(ha-ch)/cos(theta);
			ch=ha;
		}
	}
	return sum;
}

void print()
{
	for(int i=0;i<n;i++)cout<<v[i].x<<" "<<v[i].y<<endl;
}

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>n;
		for(int j=0;j<n;j++)cin>>v[j].x>>v[j].y;
		qsort(v,n,sizeof(v[0]),(int(*)(const void*,const void*))cmp);
//		print();
		cout<<fixed<<setprecision(2)<<slides()<<endl;

	}
	return 0;
}
