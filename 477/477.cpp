#include<iostream>
#include<cstdio>
using namespace std;

struct rect{
	double x[2];
	double y[2];
};

struct cicle{
	double x;
	double y;
	double r;
};

struct shape{
	struct rect rect;
	struct cicle cicle;
	char type;
};

struct shape a[10];
int n;

bool equal(double x1, double y1, double x2, double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<0.00001;
}

bool contained(double x, double y, struct shape s)
{
	struct rect r = s.rect;
	struct cicle c = s.cicle;
	switch(s.type){
		case 'r':
			if(x<=r.x[0]||x>=r.x[1])return false;
			if(y<=r.y[1]||y>=r.y[0])return false;
			return true;
		case 'c':
			if((x-c.x)*(x-c.x)+(y-c.y)*(y-c.y)<=c.r*c.r)return true;
			else return false;
	}
}


int main()
{
	char c;
	for(n=0;cin>>c&&c!='*';n++){
		a[n].type = c;
		struct rect aRect;
		struct cicle aCicle;
		switch(c){
			case 'r':
				cin>>aRect.x[0];
				cin>>aRect.y[0];
				cin>>aRect.x[1];
				cin>>aRect.y[1];
				a[n].rect = aRect;
				break;
			case 'c':
				cin>>aCicle.x;
				cin>>aCicle.y;
				cin>>aCicle.r;
				a[n].cicle = aCicle;
				break;
		}
	}
	double x,y;
	for(int i=0;cin>>x>>y&&!equal(x,y,9999.9,9999.9);i++){
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
