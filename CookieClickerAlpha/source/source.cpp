#include <stdio.h>
#include <iostream>
#include <iomanip>
int main()
{
	int noOfTestCases;
	double C, F, X;
	std::cin >> noOfTestCases;
	for(int i = 0;i<noOfTestCases;i++)
	{
		std::cin >> C >> F >> X;
		double prevSecs = 100001.0 , currSecs = 100000.0;
		int noOfBuys = 0;
		double answer = 100001.0;
		while(currSecs < prevSecs)
		{
			prevSecs = currSecs;
			currSecs=0.0;
			double rateOfProduction = 2.;
			for(int j =0; j < noOfBuys;j++)
			{
				currSecs += (C/rateOfProduction);
				rateOfProduction += F;
			}
			++noOfBuys;
			currSecs += X/rateOfProduction;

			if(currSecs < answer)
				answer = currSecs;
		}
		std::cout << std::fixed;
		std::cout << std::setprecision(7);
		std::cout <<"Case #"<<i+1<<": "<<answer<<std::endl;
	}
	return 0;
}
