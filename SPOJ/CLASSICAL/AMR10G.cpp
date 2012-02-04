#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int t,n,k,i,j,m,l,d;
    int h[20010];

    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&n,&k);
        for (i=0;i<n;i++)
            scanf("%d",&h[i]);

        if (k==1)
        {
            printf("0\n");
            continue;
        }

        sort(h,h+n);

        m=1000000001;
        l=n-k+1;
        k--;
        for (i=0;i<l;i++)
        {
            d=h[i+k]-h[i];
            if(d<m)
                m=d;
        }
        printf("%d\n",m);
    }
    return 0;
}
