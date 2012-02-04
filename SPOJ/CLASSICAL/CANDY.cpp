#include<iostream>
using namespace std;

int pack[10000];

main()
{
	int i,n,ave,t,count;
	scanf("%d",&n);
	while(n!=-1)
	{
		count=ave=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			ave+=t;
			pack[i]=t;
		}
		if(ave%n)
			printf("-1\n");
		else
		{
			ave/=n;
			for(i=0;i<n;i++)
				if(pack[i]>ave)
					count+=pack[i]-ave;
			printf("%d\n",count);
		}

		scanf("%d",&n);
	}
	return 0;
}
