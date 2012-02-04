#include<iostream>
#include<cmath>
using namespace std;

main()
{
	int i,t,p,n,y,c,op,cur,max,rp,cum,j,in;
	double r;
	scanf("%d",&t);

	while(t)
	{
		scanf("%d %d %d",&rp,&y,&n);
		max=0;
		for(i=0;i<n;i++)
		{
			p=rp;
			scanf("%d %lf %d",&c,&r,&op);
			in=cum=0;
			if(c==0)
			{
				for(j=0;j<y;j++)
				{
					cum+=int(p*r);
					p-=op;
				}
				cur=cum+p;
			}
			else
			{
				for(j=0;j<y;j++)
				{
					in=int(p*r);
					p=p+in-op;
				}
				cur=p;
			}
			if(cur>max)
				max=cur;
		}
		printf("%d\n",max);
		t--;
	}
	return 0;
}
