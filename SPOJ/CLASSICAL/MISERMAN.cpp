#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int n,m,grid[101][101],i,j,minsum;

    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d",&grid[i][j]);

    for(i=1; i<n; i++)
        for(j=0; j<m; j++)
        {
            minsum=1e9;

            if(j-1>=0)
                minsum = min(minsum, grid[i][j] + grid[i-1][j-1]);

            if(j+1<m)
                minsum = min(minsum, grid[i][j] + grid[i-1][j+1]);

            minsum = min(minsum, grid[i][j] + grid[i-1][j]);

            grid[i][j] = minsum;
        }

    minsum = grid[n-1][0];
    for(j=1; j<m; j++)
        minsum = min(minsum, grid[n-1][j]);

    printf("%d\n",minsum);

	return 0;
}
