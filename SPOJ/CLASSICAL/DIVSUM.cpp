#include<iostream>
#include<cmath>
using namespace std;

main()
{
	int t,n,m,r,d,s;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d",&n);
		if(n==1)
			s=0;
		else
		{
			s=1;
			r=sqrt(n);
			for(m=2;m<=r;m++)
			{
				if(n%m==0)
				{
					d=n/m;
					if(m==d)
						s+=m;
					else
						s+=m+d;
				}
			}
		}
		printf("%d\n",s);
		t--;
	}
	return 0;
}
