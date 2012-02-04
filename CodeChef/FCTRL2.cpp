#include<iostream>
#include<list>
using namespace std;

main()
{
	int i,n,t,r,c;
	list <int> f;
	list <int>::iterator j,k;
	scanf("%d",&t);
	while(t)
	{
		f.clear();
		f.push_back(1);
		scanf("%d",&n);
		c=0;
		for(i=2;i<=n;i++)
		{
			for(j=f.begin();j!=f.end();j++)
			{
				r=*j*i+c;
				if(r>=10)
				{
					c=r/10;
					k=j;
					k++;
					if(k==f.end())
						f.push_back(0);
					*j=r%10;
				}
				else
				{
					c=0;
					*j=r;
				}
			}
		}
		for(j=f.end();j!=f.begin();)
			printf("%d",*--j);
		printf("\n");
		t--;
	}
	return 0;
}
