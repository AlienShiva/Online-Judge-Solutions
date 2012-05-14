#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

main()
{
    int t,n,i;
    int x[1001],y[1001];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d %d",&x[i],&y[i]);

        sort(x,x+n);
        sort(y,y+n);

        if(n%2)
            printf("1\n");
        else
        {
            long long ans=(x[n/2]-x[n/2-1]+1);
            ans*=(y[n/2]-y[n/2-1]+1);
            printf("%lld\n",ans);
        }
    }

	return 0;
}
