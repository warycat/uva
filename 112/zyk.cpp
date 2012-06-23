#include <iostream>
#include <cstdio>

using namespace std;

int g;

int check(int i)
{
	char c;
	int n;
	cin >> c;
	if (cin >> n) return i -= n, check(i) & check(i) && !i ? g = 1 : 1, cin >> c, 0;
	else return cin.clear(), cin >> c, 1;
}

int main()
{
	int i;
	while (cin >> i) g = 0, check(i), puts(g ? "yes" : "no");
	return 0;
}
