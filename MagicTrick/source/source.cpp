#include <stdio.h>
	int array[4][4];
	int row1 [4];
	int row2 [4];
int main()
{
	int noOfTestCases, inp1, inp2;
	scanf("%d",&noOfTestCases);
	for(int i =0;i< noOfTestCases;i++)
	{
		scanf("%d",&inp1);
		for(int j=0;j< 4;j++)
		{
			for(int k =0;k<4;k++)
			{
				scanf("%d",&array[j][k]);
				if(j+1 == inp1)
					row1[k] = array[j][k];
			}
		}
		scanf("%d",&inp2);
		for(int j=0;j< 4;j++)
		{
			for(int k =0;k<4;k++)
			{
				scanf("%d",&array[j][k]);
				if(j+1 == inp2)
					row2[k] = array[j][k];
			}
		}
		int answer;
		int sameCount = 0;
		for(int j =0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(row1[j] == row2[k])
				{
					answer = row1[j];
					++sameCount;
					break;
				}
			}
		}

		if(sameCount == 0)
		{
			printf("Case #%d: Volunteer cheated!\n",i+1);
		}
		else if(sameCount == 1)
		{
			printf("Case #%d: %d\n",i+1,answer);
		}
		else
		{
			printf("Case #%d: Bad magician!\n",i+1);
		}

	}
	return 0;
}
