#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n,t;
int grid[101][101];
int dp[101][101];

void fastRead(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

main()
{
    //freopen("sip.txt","r",stdin);
    //freopen("op.txt","w",stdout);
    int i,j,m;

    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);

        for (i=0;i<n;i++)
            for (j=0;j<=i;j++)
                fastRead(&grid[i][j]);

        memset(dp,-1,sizeof(dp));

        dp[0][0]=grid[0][0];
        for(i=0;i<n-1;i++)
            for(j=0;j<=i;j++)
            {
                dp[i+1][j]=max(dp[i+1][j],grid[i+1][j]+dp[i][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],grid[i+1][j+1]+dp[i][j]);
            }

        m=-1;
        for(j=0;j<n;j++)
            m=max(m,dp[n-1][j]);

        printf("%d\n",m);
    }
    return 0;
}