#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int i,j,t,n1,n2,alt1[1005],alt2[1005],d,diff;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n1);
        for(i=0; i<n1; i++)
            scanf("%d",&alt1[i]);

        scanf("%d",&n2);
        for(i=0; i<n2; i++)
            scanf("%d",&alt2[i]);

        diff=abs(alt1[0]-alt2[0]);
        for(i=0; i<n1 && diff; i++)
            for(j=0; j<n2 && diff; j++)
            {
                d=abs(alt1[i]-alt2[j]);
                if(d<diff)
                    diff=d;
            }

        printf("%d\n",diff);
    }
	return 0;
}
