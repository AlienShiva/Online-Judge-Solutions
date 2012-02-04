#include<iostream>
using namespace std;

int d,m,y,nd,nm,ny;
int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int mon2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

void calc_next()
{
	int leap=0;
	nd=d;
	nm=m;
	ny=y;
	nd++;
	if(ny%4==0 && ny%100!=0)
		leap=1;
	if(!leap)	
	{
		if(nd>mon[nm])
		{
			nd=1;
			nm++;
			if(nm>12)
			{
				nm=1;
				ny++;
			}
		}
	}
	else
	{
		if(nd>mon2[nm])
		{
			nd=1;
			nm++;
			if(nm>12)
			{
				nm=1;
				ny++;
			}
		}
	}
}

bool correct()
{
	if(d==nd && m==nm && y==ny)
		return true;
	return false;
}

main()
{
	int i,n,c,pc,days,sum;
	scanf("%d",&n);
	while(n)
	{
		days=sum=0;
		scanf("%d %d %d %d",&d,&m,&y,&c);
		calc_next();		
		for(i=0;i<n-1;i++)
		{
			pc=c;
			scanf("%d %d %d %d",&d,&m,&y,&c);
			if(correct())
			{	
				days++;
				sum+=c-pc;
			}
			calc_next();		
		}
		printf("%d %d\n",days,sum);
		scanf("%d",&n);
	}
	return 0;
}
