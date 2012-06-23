#include<iostream>
#include<iomanip>
using namespace std;

struct person{
	struct person *left;
	struct person *right;
	int no;
	int off;
}a[20];

int N,k,m;

void printRound()
{
	for(int i=0;i<N;i++)if(!a[i].off)cout<<a[i].no<<" ";
	cout<<endl;
}

int main()
{
	while(cin>>N>>k>>m){
		if(N==0&&k==0&&m==0)break;
		for(int i=0;i<N;i++){
			a[i].no=i+1;
			a[i].off=0;
			a[i].left=&a[i+1];
			a[i].right=&a[i-1];
		}
		a[0].right=&a[N-1];
		a[N-1].left=&a[0];
		struct person *o1 = &a[N-1];
		struct person *o2 = &a[0];
		int count=N;
		while(count){
			for(int i=0;i<k;i++){
				while(o1->left->off)o1=o1->left;
				o1=o1->left;
			}
			for(int i=0;i<m;i++){
				while(o2->right->off)o2=o2->right;
				o2=o2->right;
			}
			o1->off=o2->off=1;
			if(o1!=o2){
				count-=2;
				cout<<setw(3)<<o1->no<<setw(3)<<o2->no;
			}else{
				count--;
				cout<<setw(3)<<o1->no;
			}
			cout<<(count?",":"\n");
		}
	}
	return 0;
}
