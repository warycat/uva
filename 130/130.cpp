#include<iostream>
using namespace std;



int n;
int k;

struct person{
	int no;
	struct person * left;
	struct person * right;
};

struct person a[100];

void debug(struct person * head)
{
	struct person *p;

	for(p=head;p->left!=head;p=p->left)
		cout<<p->no<<" ";
	cout<<p->no<<endl;
}


int main()
{
	while(cin>>n>>k){
		if(n==0&&k==0)break;
		for(int i=0;i<n;i++){
			a[i].no = i;
			a[i].left = &a[(i+1)%n];
			a[i].right = &a[(i+n-1)%n];
		}
		struct person * p = &a[0];
		while(p->left != p){
//			debug(p);
			struct person * v = p->right;
			for(int i=0;i<k;i++)
				v = v->left;
			struct person *b = v->right;
			for(int i=0;i<k;i++){
				b = b->left;
				if (b == v)b=b->left;
			}
			v->no = b->no;
//			debug(p);
			b->left->right = b->right;
			b->right->left = b->left;
			p=v->left;
		}
		cout<<(n - p->no)%n + 1<<endl;
	}
	return 0;
}
