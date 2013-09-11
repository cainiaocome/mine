#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row=0;int col=0;
	scanf("%d %d\n",&row,&col);
	char mine_map[102][102];
	int mine_num[102][102]={0};
	int i=0;int j=0;
	int times=1;
	
	while(row!=0)
	{
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				mine_num[i][j]=0;
			}
		}

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				scanf("%c",&mine_map[i][j]);
			}
			getchar();
		}

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(mine_map[i][j]=='*')
				{
					mine_num[i-1][j-1]++;
					mine_num[i-1][j]++;
					mine_num[i-1][j+1]++;
					mine_num[i][j-1]++;
					mine_num[i][j+1]++;
					mine_num[i+1][j-1]++;
					mine_num[i+1][j]++;
					mine_num[i+1][j+1]++;
				}
			}
		}

		printf("Field #%d:\n",times);
		times++;
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(mine_map[i][j]=='*')
					printf("*");
				else
					printf("%d",mine_num[i][j]);
			}
			printf("\n");
		}
		scanf("%d %d",&row,&col);
		getchar();
		if(row==0)
			break;
		else
			printf("\n");
	}
}	
