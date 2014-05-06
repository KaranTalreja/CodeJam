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
	int noOfStrings =0;
	char* buffer = (char*)malloc(sizeof(char)*100);
	inp(noOfTestCases);
	for(int i =0;i < noOfTestCases ; ++i)
	{
		set<string> allStringsHash;
		vector<string> allStrings;
		set<string> hash;
		inp(noOfStrings);
		string buff;
		for (int j =0;j<noOfStrings;j++)
		{
			inpLine(buffer);
//			cout<<buffer<<" : ";
			buff.clear();
			char prev = buffer[0];
			buff += buffer[0];
			int bufferLen = strlen(buffer);
			for(int k = 1;k < bufferLen;k++)
			{
				if(buffer[k] == prev)
					continue;
				else
				{
					buff += buffer[k];
					prev = buffer[k];
				}
			}
//			cout<< buff.c_str()<<endl;
			hash.insert(buff);
			allStringsHash.insert(string(buffer));
			allStrings.push_back(string(buffer));
		}
		if(hash.size() > 1)
		{
			cout<<"Case #"<<i+1<<": Fegla Won"<<endl;
			continue;
		}
		bool notInSrc = false;
		if(allStringsHash.find(buff) == allStringsHash.end())
			notInSrc = true;
		allStringsHash.insert(buff);
		allStrings.push_back(buff);
		int globalMin = 10000000;
		vector<string>::iterator itrTar = allStrings.begin();
		for (; itrTar != allStrings.end(); ++itrTar)
		{
			int localMin =0;
			vector<int> posOfStart;
			const char* targetStr = (itrTar)->c_str();
			char prev = targetStr[0];
			int diff = 0;
			for (int m =0; m < strlen(targetStr);m++)
			{
				if(targetStr[m] == prev)
					continue;
				else
				{
					prev = targetStr[m];
					posOfStart.push_back(m - diff);
					diff = m;
				}
			}
			posOfStart.push_back(strlen(targetStr) - diff);
			vector<string>::iterator itrSrc = allStrings.begin();
			for (;  itrSrc != allStrings.end(); ++itrSrc)
			{
				vector<int> posOfEnd;

				const char* sourceStr = (itrSrc)->c_str();
				if (strcmp (sourceStr,targetStr) == 0) continue;
				if (notInSrc == true && strcmp (sourceStr, buff.c_str()) == 0) continue;
				char prev = sourceStr[0];
				int diff = 0;
				for (int m =0; m < strlen(sourceStr);m++)
				{
					if(sourceStr[m] == prev)
						continue;
					else
					{
						prev = sourceStr[m];
						posOfEnd.push_back(m - diff);
						diff = m;
					}
				}
				posOfEnd.push_back(strlen(sourceStr) - diff);
//				cout<< targetStr << " : " << sourceStr <<endl;
				for (int m =0; m < posOfEnd.size();m++)
				{
//					cout<< posOfStart[m] << " : " << posOfEnd[m];
					localMin += abs(posOfStart[m] - posOfEnd[m]);
//					cout<< ":" << localMin <<endl;
				}
			}
			if(globalMin > localMin)
				globalMin = localMin;
		}
		cout<<"Case #"<<i+1<<": "<<globalMin<<endl;
	}
	return 0;
}
