#include<iostream>
#include<sstream>
#include<cstdlib>
using namespace std;

struct card{
	char face;
	char suit;
};

int value[256];
struct card hand[5];
struct card deck[5];
int result;

void init()
{
	value['1']=1;
	value['2']=2;
	value['3']=3;
	value['4']=4;
	value['5']=5;
	value['6']=6;
	value['7']=7;
	value['8']=8;
	value['9']=9;
	value['T']=10;
	value['J']=11;
	value['Q']=12;
	value['K']=13;
	value['A']=14;
}
void debug(){
	cout<<"Hand: ";
	for(int i=0;i<5;i++)cout<<hand[i].face<<hand[i].suit<<" ";
	cout<<"Deck: ";
	for(int i=0;i<5;i++)cout<<deck[i].face<<deck[i].suit<<" ";
	cout<<"Best hand: ";
}

void print(int r)
{
	switch(r){
		case 1:cout<<"straight-flush";
		       break;
		case 2:cout<<"four-of-a-kind";
		       break;
		case 3:cout<<"full-house";
		       break;
		case 4:cout<<"flush";
		       break;
		case 5:cout<<"straight";
		       break;
		case 6:cout<<"three-of-a-kind";
		       break;
		case 7:cout<<"two-pairs";
		       break;
		case 8:cout<<"one-pair";
		       break;
		case 9:cout<<"highest-card";
		       break;
		default:cout<<"ERROR";
		       break;
	}
}

int kind()
{
	int cnt[15]={0};
	int kinds[5]={0};
	for(int i=0;i<5;i++)cnt[value[hand[i].face]]++;
	for(int i=1;i<=14;i++)kinds[cnt[i]]++;
	if(kinds[4]==1)return 2;
	if(kinds[3]==1&&kinds[2]==1)return 3;
	if(kinds[3]==1)return 6;
	if(kinds[2]==2)return 7;
	if(kinds[2]==1)return 8;
	return 9;
}

int isFlush()
{
	for(int i=1;i<5;i++)if(hand[i].suit!=hand[i-1].suit)return 0;
	return 1;
}

int isStraight()
{
	int cnt[15]={0};
	for(int i=0;i<5;i++){
		if(hand[i].face=='A')cnt[1]++;
		cnt[value[hand[i].face]]++;
	}
	for(int i=1;i<=10;i++)if(cnt[i]&&cnt[i+1]&&cnt[i+2]&&cnt[i+3]&&cnt[i+4])return 1;
	return 0;
}

int isStraightFlush()
{
	return isStraight()&&isFlush();
}

int rank()
{
	int k=kind();
	if(isStraightFlush())return 1;
	if(k==2)return 2;
	if(k==3)return 3;
	if(isFlush())return 4;
	if(isStraight())return 5;
	if(k==6)return 6;
	if(k==7)return 7;
	if(k==8)return 8;
	return 9;
}


void dfs(int card,int no,int pos)
{
	if(card==no){
//		debug();
//		cout<<endl;
		result=min(result,rank());
	}else{
		for(int i=pos;i<5;i++){
			swap(hand[i],deck[no]);
			dfs(card,no+1,i+1);
			swap(hand[i],deck[no]);
		}
	}
}

int bruteForce()
{
	result=9;
	for(int i=0;i<=5;i++){
//		cout<<"card "<<i<<endl;
		dfs(i,0,0);
	}
}



int main()
{
	init();
	char f,s;
	string line;
	stringstream ss;
	while(getline(cin,line)){
		if(line=="")break;
		ss.clear();
		ss.str(line);
		for(int i=0;i<5;i++)ss>>hand[i].face>>hand[i].suit;
		for(int i=0;i<5;i++)ss>>deck[i].face>>deck[i].suit;
		bruteForce();
		debug();
		print(result);
		cout<<endl;
	}
	return 0;
}

