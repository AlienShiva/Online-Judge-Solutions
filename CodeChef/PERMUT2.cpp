#include<iostream>
using namespace std;

main()
{
	int n,p,ip[100001],i,P[100001];
	bool flag;
	scanf("%d",&n);
	while(n!=0)
	{
		flag=false;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p);
			*(P+i)=p;
			*(ip+p)=i;
		}
		for(i=1;i<=n && !flag;i++)
			if(*(ip+i)!=*(P+i))
				flag=true;

		if(flag)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
		scanf("%d",&n);
	}
	return 0;
}
