#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int v[1024000];
int a[1024000];
char f[60];
int p[60];
int n;

struct node {
	int l, r;
	int ll, rr;
	int c, f, s, d;
	union {
		struct {
			node *ln, *rn, *p;
		};
		node *v[2];
	};
	node **ps;
#ifdef POOLS
	void *operator new(size_t);
	void operator delete(void*, size_t) { }
} pool[20000];
int count = 0;

void *node::operator new(size_t)
{
	if (count > 20000) throw 0;
	return pool + count++;
}
#else
};
#endif
node *root;

void apply_node(node *node, int flag)
{
	if (flag & 1) node->d = 0, node->s = 1;
	if (flag & 2) node->d = node->r - node->l - node->d, node->s ^= 2;
}

void apply(node *node, int flag)
{
	if (flag & 1) node->c = 0, node->f = 1;
	if (flag & 2) node->c = node->rr - node->ll - node->c, node->f ^= 2;
	apply_node(node, flag);
}

void apply(node *node)
{
	if (node->ln) apply(node->ln, node->f);
	if (node->rn) apply(node->rn, node->f);
	node->f = 0;
}

void reload(node *node)
{
	if (node->s & 1) node->d = 0; else node->d = a[node->r] - a[node->l];
	if (node->s & 2) node->d = node->r - node->l - node->d;
}

void calc(node *node)
{
	node->c = node->d;
	if (node->ln)
		node->c += node->ln->c,
		node->ll = node->ln->ll;
	else
		node->ll = node->l;
	if (node->rn)
		node->c += node->rn->c,
		node->rr = node->rn->rr;
	else
		node->rr = node->r;
}

template <int t>
void roll(node *p)
{
	node *org = p, *tar = p->v[t];
	apply(org);
	apply(tar);
	if (org->v[t] = tar->v[t ^ 1])
		org->v[t]->ps = org->v + t,
		org->v[t]->p = org;
	tar->v[t ^ 1] = org;
	tar->ps = org->ps;
	tar->p = org->p;
	org->ps = tar->v + (t ^ 1);
	org->p = tar;
	*tar->ps = tar;
	calc(org);
	calc(tar);
}

void splay(node *node)
{
	while (node->p) {
		if (node->p->ln == node)
			roll<0>(node->p);
		else
			roll<1>(node->p);
	}
}

node *find(node *root, int key)
{
	node *p = root;
	while (p) {
		apply(p);
		if (p->l > key) p = p->ln;
		else if (p->r <= key) p = p->rn;
		else return p;
	}
	return p;
}

void insert(node *root, node *sub)
{
	node *p = root, *q = p;
	while (p) {
		apply(p);
		if (p->l > sub->l) q = p, p = p->ln;
		else if (p->r <= sub->l) q = p, p = p->rn;
	}
	if (q->l > sub->l) q->ln = sub, sub->ps = &q->ln;
	else q->rn = sub, sub->ps = &q->rn;
	sub->p = q;
	splay(sub);
}

void cut(int key)
{
	int c = root->c;
	node *org = find(root, key);
	if (!org || key == org->l) return;
	//assert(org->l <= key && org->r > key);
	node *sub = new node;
	sub->l = key;
	sub->r = org->r;
	sub->s = org->s;
	sub->f = 0;
	sub->ln = sub->rn = 0;
	org->r = key;
	reload(org);
	reload(sub);
	calc(sub);
	calc(org);
	insert(root, sub);
	calc(org);
	assert(c == root->c);
}

void set(node *p, int l, int r, int f)
{
	if (p->ll >= l && p->rr <= r) return apply(p, f);
	if (p->ll >= r || p->rr <= l) return;
	apply(p);
	if (p->ln) set(p->ln, l, r, f);
	if (p->l >= l && p->r <= r)
		apply_node(p, f);
	if (p->rn) set(p->rn, l, r, f);
	calc(p);
}

void set(int l, int r, int f)
{
	cut(l);
	cut(r);
	set(root, l, r, f);
}

int quest(node *p, int l, int r)
{
	if (p->ll >= l && p->rr <= r) return p->c;
	if (p->ll >= r || p->rr <= l) return 0;
	apply(p);
	int v = 0;
	if (p->ln) v += quest(p->ln, l, r);
	if (p->l >= l && p->r <= r) v += p->d;
	if (p->rn) v += quest(p->rn, l, r);
	return v;
}

int quest(int l, int r)
{
	cut(l);
	cut(r);
	return quest(root, l, r);
}

void init(int l, int r)
{
	root = new node;
	root->ll = root->l = l;
	root->rr = root->r = r;
	root->f = root->s = 0;
	root->ln = root->rn = root->p = 0;
	root->ps = &root;
	root->c = root->d = a[r] - a[l];
}

void destory(node *&node = root)
{
#ifndef POOLS
	if (node->ln) destory(node->ln);
	if (node->rn) destory(node->rn);
	delete node;
#else
	count = 0;
#endif
}

int main()
{
	//freopen("11402.in", "r", stdin);
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
			for (int i = 0; i < t; i++)
				memcpy(::v + n, ::p, l * sizeof(int)), n += l;
		}
		a[0] = 0;
		for (int i = 0; i < n; i++) a[i + 1] = a[i] + ::v[i];
		init(0, n);
		int q;
		scanf("%d", &q);
		char c;
		int a, b;
		int x = 0;
		while (q--) {
			scanf("\n%c%d%d", &c, &a, &b);
			++b;
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
		destory();
	}
}
