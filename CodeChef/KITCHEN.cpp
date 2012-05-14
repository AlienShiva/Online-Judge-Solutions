#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int n,m,l,t,r,b,hn,hm;
char grid[101][101];

float percent()
{
    int i,j,cnt;

    cnt=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(grid[i][j]=='#')
                cnt++;
    return (cnt*100.0/(n*m));
}

void solve()
{
    int i,j,cnt;

    i=j=0;

    l=0;
    t=2;
    r=m;
    b=n;
    hn=ceil(n/2);
    hm=ceil(m/2);

    while(1)
    {
        cnt=0;

        if(r>=hm)
        {
            for(; j<r; j++,cnt++)
                grid[i][j]='#';
            j--;
            r-=2;
        }

        if(b>=hn)
        {
            for(; i<b; i++,cnt++)
                grid[i][j]='#';
            i--;
            b-=2;
        }

        if(l<=hm && b>hn)
        {
            for(; j>=l; j--,cnt++)
                grid[i][j]='#';
            j++;
            l+=2;
        }

        if(t<=hn && r>hm)
        {
            for(; i>=t; i--,cnt++)
                grid[i][j]='#';
            i++;
            t+=2;
        }


        if(cnt==0)
            break;
    }
}

main()
{
    int tc,i,j;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d", &n, &m);

        memset(grid,'.',sizeof(grid));

        solve();

        //printf("\n%.2f\n",percent());
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                putchar(grid[i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
