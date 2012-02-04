#include<iostream>
using namespace std;

main()
{
	int i,j,k,t,n,cur;
	int mat[205][205];

	scanf("%d",&t);

	while(t)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&mat[i][j]);

		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				cur=mat[i][j];
				for(k=0;k<n;k++)
					if((cur==mat[i][k]+mat[k][j]) && i!=k &j!=k)
						break;
				if(k==n)
					printf("%d %d\n",i+1,j+1);
			}
		printf("\n");
		t--;
	}
	return 0;
}
