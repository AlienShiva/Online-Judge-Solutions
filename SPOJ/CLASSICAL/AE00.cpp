#include<iostream>
#include<cmath>
using namespace std;

int dp[10005];

main()
{
	int i,n,d,j,total;
	double s;
	scanf("%d",&n);
	if(n==1 || n==2 || n==3)
		total=n;

	else
	{
		total=3;
		for(i=4;i<=n;i++)
		{
			d=0;
			s=sqrt(i);
			for(j=1;j<=s;j++)
				if(i%j==0)
					d++;
			dp[i]=d;
			total+=d;
		}
	}
	printf("%d",total);
	return 0;
}
