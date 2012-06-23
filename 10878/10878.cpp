#include <cstdio>
#include <iostream>
using namespace std;
string s;

int main()
{
	while (getline(cin,s)) {
		if (s[0] != '|')continue;
		char c = 0;
		c |= (s[1] == 'o' ? 128 : 0);
		c |= (s[2] == 'o' ? 64 : 0);
		c |= (s[3] == 'o' ? 32 : 0);
		c |= (s[4] == 'o' ? 16 : 0);
		c |= (s[5] == 'o' ? 8 : 0);
		c |= (s[7] == 'o' ? 4 : 0);
		c |= (s[8] == 'o' ? 2 : 0);
		c |= (s[9] == 'o' ? 1 : 0);
		putchar(c);
	}
	return 0;
}
