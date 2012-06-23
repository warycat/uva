#include<iostream>
#include<iomanip>
using namespace std;

string a[100];
int N, C, L, R;

int cmp(string *p, string *q)
{
	return strcmp(p->c_str(),q->c_str());
}

int main()
{
	while(cin>>N){
		L=0;
		for(int i=0;i<N;i++){
			cin>>a[i];
			int t=a[i].size();
			L=max(L,t);
		}
		for(C=1;C*L+(C-1)*2<=60;C++);
		C--;
		R=N/C;
		if(N%C)R++;
		for(int i=0;i<60;i++)cout<<'-';
		cout<<endl;
	//	printf("N%d L%d C%d R%d\n",N,L,C,R);
		qsort(a,N,sizeof(string),(int(*)(const void*,const void*))cmp);
		for(int i=0;i<R;i++){
			for(int j=0;j<C&&j*R+i<N;j++)
				cout<<setw(L+2)<<setiosflags(ios::left)<<a[j*R+i];
			cout<<endl;
		}
				
	}
	return 0;
}

