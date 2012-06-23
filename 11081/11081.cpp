#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string a, b, c;
int r[61][61][61];
bool g[61][61][61];
int t;
int f(int i, int j, int k)
{
	if (i < 0 || j < 0 || k < 0) return 0;
	if (g[i][j][k]) return r[i][j][k];
	if (k == 0) return r[i][j][k] = 1;
	r[i][j][k] = f(i - 1, j, k) + f(i, j - 1, k) - f(i - 1, j - 1, k);
	if (a[i - 1] == c[k - 1]) r[i][j][k] += f(i - 1, j, k - 1) - f(i - 1, j - 1, k - 1);
	if (b[j - 1] == c[k - 1]) r[i][j][k] += f(i, j - 1, k - 1) - f(i - 1, j - 1, k - 1);
	g[i][j][k] = true;
	return r[i][j][k] %= 10007;
}

int pos(int v)
{
	return v < 0 ? v + 10007 : v;
}

int main()
{
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		memset(g, 0, sizeof(g));
		cout << pos(f(a.length(), b.length(), c.length())) << endl;
	}
	return 0;
}
