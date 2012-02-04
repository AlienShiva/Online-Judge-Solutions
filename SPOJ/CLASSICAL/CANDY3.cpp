#include<iostream>
using namespace std;

main()
{
	int i,t,n;
    long long s,ave;
	scanf("%d",&t);
	while(t!=0)
	{
	    s=n=ave=0;
		scanf("%d",&n);
        for(i=0;i<n;i++)
		{
			scanf("%lld",&s);
			ave+=s;
			ave=ave%n;
		}
		if(ave)
			printf("NO\n");
		else
			printf("YES\n");
		t--;
	}
	return 0;
}
