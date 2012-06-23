#include <stdio.h>
#include <string.h>

#define check(x) if (x >= size) throw 0

const int fbit = 1048576;
const int size = 2097152;
int a[2097152];
int s[2097152];
int l[2097152];
int r[2097152];
int v[1024000];
char f[60];
int p[60];
int n;

void apply(int x, int f, int count)
{
	check(x);
	if (f & 1) a[x] = 0, s[x] |= 1;
	if (f & 2) a[x] = count - a[x], s[x] ^= 2;
}

void apply(int x, int f)
{
	check(x);
	if (f & 1) a[x] = 0, s[x] |= 1;
	if (f & 2) a[x] = ::r[x] - ::l[x] - a[x], s[x] ^= 2;
}

void godown(int x)
{
	check(x);
	if (l[x] + 1 == r[x]) return;
	apply(x << 1, s[x]);
	apply(x << 1 | 1, s[x]);
	s[x] = 0;
}

void set(int l, int r, int f, int v = 1)
{
	check(v);
	register int start = ::l[v], end = ::r[v];
	if (l >= end || r < start) return;
	if (l <= start && r + 1 >= end) return apply(v, f, end - start);
	godown(v);
	set(l, r, f, v << 1);
	set(l, r, f, v << 1 | 1);
	a[v] = a[v << 1] + a[v << 1 | 1];
}

int quest(int l, int r, int v = 1)
{
	check(v);
	register int start = ::l[v], end = ::r[v];
	if (l >= end || r < start) return 0;
	if (l <= start && r + 1 >= end) return a[v];
	godown(v);
	return quest(l, r, v << 1) + quest(l, r, v << 1 | 1);
}

void init(int l, int r, int v = 1)
{
	check(v);
	s[v] = 0;
	::l[v] = l, ::r[v] = r;
	if (l + 1 == r) {
		a[v] = ::v[l];
		return;
	}
	int m = l + r >> 1;
	init(l, m, v << 1);
	init(m, r, v << 1 | 1);
	a[v] = a[v << 1] + a[v << 1 | 1];
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		n = 0;
		printf("Case %d:\n", i + 1);
		int m;
		scanf("%d", &m);
		for (int p = 0; p < m; p++) {
			int t;
			scanf("%d\n", &t);
			gets(f);
			int l = strlen(f);
			for (int i = 0; i < l; i++) ::p[i] = f[i] - '0';
			for (int i = 0; i < t; i++) memcpy(::v + n, ::p, l * sizeof(int)), n += l;
		}
		init(0, n);
		int q;
		scanf("%d", &q);
		char c;
		int a, b;
		int x = 0;
		while (q--) {
			scanf("\n%c%d%d", &c, &a, &b);
			switch (c) {
				case 'S':
					printf("Q%d: %d\n", ++x, quest(a, b));
					break;
				case 'E':
					set(a, b, 1);
					break;
				case 'F':
					set(a, b, 3);
					break;
				case 'I':
					set(a, b, 2);
					break;
			}
		}
	}
}
