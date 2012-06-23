#include<iostream>
#include<cstdio>
using namespace std;

struct rect{
	double x[2];
	double y[2];
};

struct rect a[10];
int n;

bool equal(double x1, double x2, double y1, double y2)
{
	if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<0.000001)return true;
	else return false;
}

bool contained(double x, double y, struct rect r)
{
	if(x<=r.x[0]||x>=r.x[1]){
//		cout<<"x "<<x<<" "<<r.x[0]<<" "<<r.x[1]<<endl;
		return false;
	}
	if(y<=r.y[1]||y>=r.y[0]){
//		cout<<"y "<<y<<" "<<r.y[0]<<" "<<r.y[1]<<endl;
		return false;
	}
	return true;
}


int main()
{
	char c;
	for(n=0;cin>>c&&c=='r';n++){
		cin>>a[n].x[0]>>a[n].y[0]>>a[n].x[1]>>a[n].y[1];
	}
	double x,y;
	for(int i=0;cin>>x>>y&&!equal(x,9999.9,y,9999.9);i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(contained(x,y,a[j])){
				printf("Point %d is contained in figure %d\n",i+1,j+1);
				cnt++;
			}
		}
		if(!cnt)
			printf("Point %d is not contained in any figure\n",i+1);
	}
	return 0;
}

