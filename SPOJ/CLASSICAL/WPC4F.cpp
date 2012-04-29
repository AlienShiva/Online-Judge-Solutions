#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int i,j,k,t,n,cost[21][3],mincost;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d %d %d",&cost[i][0],&cost[i][1],&cost[i][2]);

        for(i=1; i<n; i++)
            for(j=0; j<3; j++)
            {
                mincost = 1e9;

                for(k=0; k<3; k++)
                    if(j!=k)
                        mincost = min(mincost, cost[i][j] + cost[i-1][k]);

                cost[i][j] = mincost;
            }

        mincost = min(min(cost[n-1][0],cost[n-1][1]),cost[n-1][2]);

        printf("%d\n",mincost);
    }
    return 0;
}
