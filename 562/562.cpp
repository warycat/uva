#include <iostream>
#include <cstring>

using namespace std;

bool u[100001], v[100001];
void set(bool *a, int i)
{
	a[i + 50000] = true;
}
bool get(bool *a, int i)
{
	return a[i + 50000];
}

int main()
{
	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		memset(u, 0, sizeof(u));
		set(u, 0);
		bool *p = u, *q = v;
		for (int i = 0; i < m; i++) {
			int a;
			memset(q, 0, sizeof(u));
			cin >> a;
			for (int j = 0; j < 100001; j++)
				if (p[j]) q[j + a] = q[j - a] = true;
			swap(p, q);
		}
		for (int i = 0; i < 500000; i++)
			if (get(p, i)) {
				cout << i << endl;
				break;
			}
	}
	return 0;
}
