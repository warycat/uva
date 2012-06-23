#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <assert.h>
#include <ctype.h>
#define NO_LONG_LONG

using std::max;
using std::min;
//using std::swap;

int c[500][500];
/*
int v[501][501];
bool b[501][501];

int f(int i, int j)
{
	if (b[i][j]) return v[i][j];
	b[i][j] = true;
	return v[i][j] = (i && j) ? f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1) + c[i][j] : 0;
}

int f(int a, int b, int c, int d)
{
	return f(c, d) + f(a, b) - f(a, d) - f(b, c);
}
*/

struct point {
	int x, y;
};

union rect {
	struct {
		point p1, p2;
	};
	struct {
		int x1, y1, x2, y2;
	};
	bool in(const rect& r) const
	{
		return x1 >= r.x1 && x2 <= r.x2
			&& y1 >= r.y1 && y2 <= r.y2;
	}
	bool out(const rect& r) const
	{
		return x1 >= r.x2 || x2 <= r.x1
			|| y1 >= r.y2 || y2 <= r.y1;
	}
};

union pair {
	struct {
		int max, min;
	};
	long long v;
};

static struct {
	rect reg;
	union {
		pair v;
		struct {
			int max, min;
		};
	};
} a[1000000];

int l[500][500];

void calc(int v)
{
	a[v].max = max(a[v << 1].max, a[v << 1 | 1].max);
	a[v].min = min(a[v << 1].min, a[v << 1 | 1].min);
}

void init(const rect& r, int v = 1)
{
	a[v].reg = r;
	if (r.y2 - r.y1 == 1 && r.x2 - r.x1 == 1) {
		a[v].max = a[v].min = c[r.x1][r.y1];
		l[r.x1][r.y1] = v;
		return;
	}
	if (r.y2 - r.y1 > r.x2 - r.x1) {
		int y = r.y1 + r.y2 >> 1;
		rect reg = { r.x1, r.y1, r.x2, y };
		init(reg, v << 1);
		reg.y1 = y;
		reg.y2 = r.y2;
		init(reg, v << 1 | 1);
	} else {
		int x = r.x1 + r.x2 >> 1;
		rect reg = { r.x1, r.y1, x, r.y2 };
		init(reg, v << 1);
		reg.x1 = x;
		reg.x2 = r.x2;
		init(reg, v << 1 | 1);
	}
	calc(v);
}

void change(const point& p, int v)
{
	int x = l[p.x][p.y];
	a[x].max = a[x].min = v;
	while (x != 1) calc(x >>= 1);
}

const pair NONE = { INT_MIN, INT_MAX };

pair combine(const pair& a, const pair&	b)
{
	pair c = { max(a.max, b.max), min(a.min, b.min) };
	return c;
}

pair quest(const rect& r, int v = 1)
{
	if (a[v].reg.in(r)) return a[v].v;
	if (r.out(a[v].reg)) return NONE;
	return combine(quest(r, v << 1), quest(r, v << 1 | 1));
}
#ifndef NO_LONG_LONG
#define print_pair(p) printf("%d %d\n", p.v);
#else
#ifdef ONLINE_JUDGE
void print_pair(const pair& p)
{
	printf("%d %d\n", p.max, p.min);
}
#else
#define print_pair(p) printf("%d %d\n", p);
#endif
#endif

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("11297.in", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	//while (getchar() != '\n');
	assert(m == n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", c[i] + j);
	rect r = {0, 0, n, m};
	init(r);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		char c;
		assert(scanf("\n%c", &c) == 1);
		int v, x1, x2, y1, y2;
		switch (c) {
			case 'q':
				assert(scanf("%d%d%d%d", &x1, &y1, &x2, &y2) == 4);
				{
					rect r = {x1 - 1, y1 - 1, x2, y2};
					print_pair(quest(r));
				}
				break;
			case 'c':
				assert(scanf("%d%d%d", &x1, &y1, &v) == 3);
				{
					point c = {x1 - 1, y1 - 1};
					change(c, v);
				}
				break;
			defalut:
				assert(0);
		}
	}
	int x = 0;
	while (isspace(x = getchar()));
	assert(x == EOF);
	fflush(stdout);
	return 0;
}
