#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[100][100];
int p[100];

int f(int x, int y)
{
	if (y - x < 2) return 0;
	if (a[x][y]) return a[x][y];
	int m = 0x7FFFFFFF;
	for (int i = x + 1; i < y; i++)
		if (f(x, i) + f(i, y) < m) m = a[x][i] + a[i][y];
	return a[x][y] = p[y] - p[x] + m;
}

int main()
{
	int n, l;
	while (scanf("%d%d", &l, &n) == 2 && l) {
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++) scanf("%d", p + i);
		p[n] = l;
		sort(p, p + n + 2);
		printf("The minimum cutting is %d.\n", f(0, n + 1));
	}
}

