#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <set>
#include <vector>
using namespace std;
#define getcx getchar_unlocked
inline void inpLine(char *str)
{
	register char c = 0;
	register int i = 0;
	while (c < 33)
		c = getcx();
	while (c != '\n') {
		str[i] = c;
		c = getcx();
		i = i + 1;
	}
	str[i] = '\0';
}
inline void inp( int &n )//fast input function
{
	n=0;
	register int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
int main()
{
	int noOfTestCases = 0;
	inp(noOfTestCases);
	size_t A, B,K,answer= 0 ;
	for(int i=0;i< noOfTestCases;i++)
	{
		answer = 0;
		cin >> A >> B >> K;
		if(A < B)
		{
			size_t temp = A;
			A = B;
			B = temp;
		}
		if (K < A  && K < B)
		{
			answer = (A- K)*K + K*B ;
			for (size_t j = K; j < A ;j++ )
			{
				for(size_t k = K; k < B; k++)
				{
					if ( (j & k) < K)
					{
						answer++;
					}
				}
			}
		}
		else
			answer = A * B;
		cout<<"Case #"<<i+1<<": "<<answer<<endl;
	}

	return 0;
}
