#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int a[10], b[10];
int c[10][10], d[10][10];

int f(int x, int y)
{
	if (c[x][y] || x == y) return c[x][y];
	int m = 0x7FFFFFFF;
	for (int i = x; i < y; i++) {
		int z = a[x] * b[i] * b[y] + f(x, i) + f(i + 1, y);
		if (z < m) m = z, d[x][y] = i;
	}
	return c[x][y] = m;
}

string g(int x, int y)
{
	char b[10];
	if (x == y) return sprintf(b, "A%d", x + 1), b;
	return "(" + g(x, d[x][y]) + " x " + g(d[x][y] + 1, y) + ")";
}

int main()
{
	int t = 0, n;
	while (cin >> n && n) {
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		f(0, n - 1);
		cout << "Case " << ++t << ": " << g(0, n - 1) << endl;
	}
	return 0;
}
