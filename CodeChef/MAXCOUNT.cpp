#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
	int i,v,c,n,t,temp;
    int val[10001];

    scanf("%d",&t);
    while(t--)
    {
        memset(val,0,sizeof(val));

        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&temp);
            val[temp]++;
        }

        v=0;
        c=val[0];
        for(i=1; i<10001; i++)
            if(c<val[i])
            {
                c=val[i];
                v=i;
            }

        printf("%d %d\n",v,c);
    }
	return 0;
}
