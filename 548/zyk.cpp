#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int f[10000];
int g[10000];

pair<int, int> operator + (pair<int, int> a, int b)
{
	a.first += b;
	return a;
}

pair<int, int> build(int l, int r, int m = 0)
{
	return l > r ? make_pair(INT_MAX, 0) : l == r ? make_pair(g[l], g[l]) : min(build(l, f[g[r]] - m - 1 + l, m), build(f[g[r]] - m + l, r - 1, f[g[r]] + 1)) + g[r];
}

int main()
{
	while (true) {
		memset(f, -1, sizeof(f));
		int n = 0;
		while (true) {
			int x;
			if (cin >> x); else break;
			if (f[x] != -1) {
				g[0] = x;
				break;
			}
			f[x] = n++;
		}
		if (!cin) break;
		for (int i = 1; i < n; i++) cin >> g[i];
		cout << build(0, n - 1).second << endl;
	}
}
