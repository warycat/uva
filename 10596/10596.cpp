#include <stdio.h>

int a[200];
int s[200];

int find(int v)
{
	while (s[v] != v) v = s[v];
	return v;
}

void uni(int a, int b)
{
	a = find(a), b = find(b);
	if (a) s[a] = b; else s[b] = a;
}

int main()
{
	int n, r, p, q;
	while (scanf("%d%d", &n, &r) == 2) {
		for (int i = 0; i < n; i++) a[i] = 0, s[i] = i;
		for (int i = 0; i < r; i++)
			scanf("%d%d", &p, &q),
			++a[p], ++a[q], uni(p, q);
		int p = 0;
		for (int i = 0; i < n; i++) p |= a[i] & 1, p |= find(i);
		printf("%sPossible\n", p ? "Not " : "");
	}
	return 0;
}
