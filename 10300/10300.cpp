#include <iostream>
using namespace std;

int main()
{
	int n;
	int f;
	cin >> n;
	int i;
	for(i=0;i<n;i++) {
		cin >> f;
		int j;
		long long sum = 0;
		int size;
		int animals;
		int friendliness;
		for(j=0;j<f;j++){
			cin >> size >> animals >> friendliness;
			sum += size * friendliness;
		}
		cout << sum << endl;
	}
	return 0;
}
