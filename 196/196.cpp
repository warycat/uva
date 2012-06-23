#include <stdio.h>
#include <ctype.h>

struct cell;

struct node
{
	cell *v;
	node *n;
};

struct cell
{
	enum type{
		VALUE,
		SUM,
	} t;
	union {
		int n;
		node *c;
	};
} c[999][18278];

cell* read()
{
	int r = 0, c;
	char s[3] = { };
	int p = 0;
	while (!scanf("%d", &c))
		s[p++] = getchar() - 0x40;
	switch (p) {
	case 1:
		r = s[0];
		break;
	case 2:
		r = s[0] * 26 + s[1];
		break;
	case 3:
		r = s[0] * 676 + s[1] * 26 + s[2];
		break;
	}
	return ::c[c - 1] + r - 1;
}

void read(cell* c)
{
	if (scanf("%d", &c->n))
		c->t = cell::VALUE;
	else {
		c->t = cell::SUM;
		c->c = 0;
		while (getchar() != '=');
		do {
			node *n = new node;
			n->v = read();
			n->n = c->c;
			c->c = n;
		} while (getchar() == '+');
	}
}

int eval(cell *c)
{
	if (c->t == cell::VALUE) return c->n;
	node *i = c->c;
	int sum = 0;
	while (i) {
		sum += eval(i->v);
		node *p = i;
		i = i->n;
		delete p;
	}
	c->t = cell::VALUE;
	return c->n = sum;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				read(c[i] + j);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				printf("%d%c", eval(c[i] + j), j + 1 == n ? '\n' : ' ');
	}
}
