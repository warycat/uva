#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

map<string, string> m;
vector<string> v;

int main()
{
	string s;
	while (cin >> s) {
		if (s == "#") break;
		string k = s;
		for (int i = 0; i < k.length(); ++i) k[i] = tolower(k[i]);
		sort(k.begin(), k.end());
		pair<map<string, string>::iterator, bool> p = m.insert(make_pair(k, s));
		if (!p.second) p.first->second.clear();
	}
	for (map<string, string>::iterator i = m.begin(); i != m.end(); i++)
		if (!i->second.empty()) v.push_back(i->second);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) puts(v[i].c_str());
}
