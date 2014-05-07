#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
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
        vector<string> allStrings;
        set<string> hash;
        vector<vector<int > > LettersInString;
        inp(noOfStrings);
        string buff;
        for (int j =0;j<noOfStrings;j++)
        {
            inpLine(buffer);
//            cout<<buffer<<" : ";
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
            allStrings.push_back(string(buffer));
            LettersInString.push_back(vector<int> (buff.size(),1));
            prev = buffer[0];
            bufferLen = strlen(buffer);
            int idxInArray =0;
            for(int k = 1;k < bufferLen;k++)
            {
                if(buffer[k] == prev)
                {
                    LettersInString[j][idxInArray]++;
                    continue;
                }
                else
                {
                    prev = buffer[k];
                    idxInArray++;
                }
            }
        }
        if(hash.size() > 1)
        {
            cout<<"Case #"<<i+1<<": Fegla Won"<<endl;
            continue;
        }
        size_t globalMin = 0;
        size_t max = LettersInString[0].size();
        size_t answer = 0;
        for (size_t k = 0; k< max ;k++)
        {
            vector<int > tempvec;
            for (size_t j = 0 ; j< LettersInString.size(); j++)
                tempvec.push_back(LettersInString[j][k]);

            sort(tempvec.begin(), tempvec.end(),less<int>());
            int median = 0;

            if(tempvec.size() % 2 == 0)
                median = (tempvec[tempvec.size()/2 -1] + tempvec[tempvec.size()/2]) / 2;
            else
                median = tempvec[(tempvec.size()+1)/2 -1];

            for (size_t j = 0 ; j< LettersInString.size(); j++)
                answer += abs(LettersInString[j][k] - median);
        }


        cout<<"Case #"<<i+1<<": "<<answer<<endl;
    }
    return 0;
}
