#include <queue>
#include <iostream>

using namespace std;

int n, m;
int d[100];
int v[100][100];

int main()
{
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) v[i][0] = 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			v[a][++v[a][0]] = b;
			++d[b];
		}
		queue<int> q;
		for (int i = 0; i < n; i++)
			if (!d[i]) q.push(i);
		bool f = true;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (f) f = false; else cout << " ";
			cout << p + 1;
			for (int i = 1; i <= v[p][0]; i++)
				if (!--d[v[p][i]]) q.push(v[p][i]);
		}
		cout << endl;
	}
	return 0;
}
