/**************************
 *找出一个二维矩阵里的鞍数*
 **************************/
#include<stdio.h>
int main()
{
	const int ROW=5;
	const int COLUMN=5;
	int matrix[5][5]={0};
	int max_row[5]=  {0};
	int i,j,n;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	
	
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			if(max_row[i]<matrix[i][j])
			{
				max_row[i]=matrix[i][j];
			}
			int num=0;
			for(n=0;n<ROW;n++)
			{
				if(matrix[n][j]<max_row[i])
				{
					++num;
				}
			}
			if(num==0)
			{
				printf("%d %d %d\n",i+1,j+1,max_row[i]);
			}
		}
	}
	return 0;
}
