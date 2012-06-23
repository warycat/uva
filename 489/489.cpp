#include <iostream>
#include <string>
using namespace std;

int round;

int game(string s, string g)
{
	int i;
	int j;
	int table[256] = {0};
	int hit = 0;
	int hang = 0;
	for(i=0;i<g.size();i++){
//		if(round==22)cout<<int(g[i])<<" ";
		if(!table[g[i]]){
			int find = 0;
			for(j=0;j<s.size();j++){
				if(g[i]==s[j])find++;
			}
//			if(round==22)cout<<find<<endl;
			if(!find)hang++;
			hit += find;
//			if(round==22)cout<<g[i]<<" find "<<find<<endl;
		}
		table[g[i]]=1;
		if(hang>=7)return 2;
		if(hit==s.size())return 0;
	}
	return 1;
}


int main()
{
	string puzzle;
	string guess;
	while(cin >> round && round!=-1){
		cin >> puzzle >> guess;
		cout << "Round " << round << endl;
		switch(game(puzzle,guess)){
			case 0: cout << "You win." << endl;
				break;
			case 1: cout << "You chickened out." << endl;
				break;
			case 2: cout << "You lose." << endl;
				break;
			default: cout << "error." << endl;
				break;
		}
	}
	return 0;
}
