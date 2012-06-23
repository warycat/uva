#include<iostream>
using namespace std;

int main()
{
	int tc;
	int sum,diff;
	cin>>tc;
	while(cin>>sum>>diff){
		int cnt = 0;
		for(int i=sum;i>=sum/2;i--){
			int j = sum - i;
			if(i-j==diff){
				cnt++;
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
		if(!cnt)cout<<"impossible"<<endl;
	}
	return 0;
}
