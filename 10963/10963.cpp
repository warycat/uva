#include<iostream>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		int n;
		cin>>n;
		int a,b;
		int t;
		int pt;
		int cnt = 0;
		for(int j=0;j<n;j++){
			cin>>a>>b;
			if(j)pt = t;
			t = a-b;
			if(j&&t!=pt)cnt++;
		}
		if(i)cout<<endl;
		cout<<(cnt?"no":"yes")<<endl;
	}
	return 0;
}
