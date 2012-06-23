#include <string>
#include <list>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;
typedef basic_string<ii> pstring;
typedef list<pstring> lp;

int first(const pstring& p)
{
	return p[0].first;
}

int last(const pstring& p)
{
	return p.rbegin()->second;
}

lp t;
int c[51];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		t.push_back(pstring() += make_pair(a, b));
		++c[a], ++c[b];
	}
	bool flag = false;
	while (n--) {
		for (lp::iterator i = t.begin(); i != t.end(); ++i) {
			if (first(*i) == last(*i)) {
				if (!(c[fisrt(*i)] -= 2)) {
					flag = true;
					break;
				}
				p.remove(i++);
				--i;
			}
		}
		if (flag) break;
	}
}
