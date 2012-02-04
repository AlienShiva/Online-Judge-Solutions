#include <stdio.h>
#include <string.h>

main()
{
	int t,r,c,w,i,j,ts,tl,tr,val;
	int grid[101][101];

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&r,&c);

		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				scanf("%d",&grid[i][j]);

		for(i=1;i<r;i++)
			for(j=0;j<c;j++)
			{
				ts=tl=tr=0;

				ts=grid[i-1][j];

				if(j-1>=0)
					tl=grid[i-1][j-1];

				if(j+1<c)
					tr=grid[i-1][j+1];

				val=(ts>tl)?ts:tl;
				val=(val>tr)?val:tr;

				grid[i][j]+=val;
			}

		val=0;
		for(i=r-1,j=0;j<c;j++)
			if(grid[i][j]>val)
				val=grid[i][j];

		printf("%d\n",val);
	}	
	return 0;
}
