//finding_saddlepoint.c——寻找5*5矩阵的鞍点 
#include<stdio.h>
#define n 5
int main(void)
{
	int temp,count,flag=0;
	int m[n][n];
	int i,j;
	
	
	printf("输入一个5*5的矩阵，且满足每行只有一个最大值，每列只有一个最小值：\n"); 
	//下面开始读入矩阵中的每一个数 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&temp);
			m[i][j]=temp;
		}
	}
	//下面开始寻找鞍点
	for(i=0;i<n;i++)
	{//下面找出每行最大的数字
	    temp=m[i][0];
	    count=0;
	    for(j=1;j<n;j++)
	    {
	  	    if(temp<m[i][j])
	  	    {
	  		    temp=m[i][j];
	  		    count=j;
	        }
	    }
		//下面进行测试
	    for(j=0;j<n;j++) //在这里注意一下i,j的使用，这里只能用j，不能用i 
	    {
	        if(m[j][count]<temp)//注意符号，不可用“<=”，因为考虑到本身会导致左侧右侧相等，违背了我们的初衷 
	  	    flag++;
	    }
	    if(flag==0)
		{
		    printf("找到鞍点，且该鞍点在第%d行第%d列，值为%d\n",i+1,count+1,temp);
		    break;
		}
		flag=0;//一定要回归初始值！ 
	}
	
	
	if(i==n)//注意一下，n为符合常量 
		printf("not found");
	
	
	return 0;
 } 
