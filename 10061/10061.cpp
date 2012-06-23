#include<iostream>
#include<cmath>
#include<cstdio>
#include<climits>
using namespace std;

int n,b;

int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,};
const int nprimes=sizeof(primes) / sizeof(*primes);
const int N = 1<<20;
const int B = nprimes;
int factors[N][B]={0};
int factorial_factors[N][B]={0};
long double logOfDigits[N]={0};
int zeros;
int digits;

void init()
{
	logOfDigits[1]=0;
	for(int i=2;i<N;i++){
		int v=i;
		for(int j=0;j<nprimes;j++){
			while(v%primes[j]==0){
				v/=primes[j];
				factors[i][j]++;
			}
			factorial_factors[i][j]=
				factorial_factors[i-1][j]+factors[i][j];
		}
		logOfDigits[i]=logOfDigits[i-1]+log((long double)i);
	}
}

void count()
{
	zeros=0x7fffffff;
	for(int i=0;i<nprimes;i++){
		if(factors[b][i])
			zeros=min(zeros,factorial_factors[n][i]/factors[b][i]);
	}
	digits=logOfDigits[n]/log((long double)b)+1;
}

int main()
{
	init();
	while(cin>>n>>b){
		count();
		printf("%d %d\n",zeros,digits);
	}
	return 0;
}
