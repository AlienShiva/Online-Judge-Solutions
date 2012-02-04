#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int i,j,d;
};

int n,m;
char grid[185][185];
int ans[185][185];
int di[]={0,-1,0,1};
int dj[]={-1,0,1,0};

void solve()
{
    queue <node> q;
    node t,temp;
    int i,j,d,k,ex=0;
    bool pushed[185][185];

    memset(pushed,false,sizeof(pushed));

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(grid[i][j]=='1')
            {
                t.i=i;
                t.j=j;
                t.d=0;
                q.push(t);
            }

    while(!q.empty())
    {
        t=q.front();
        q.pop();

        ans[t.i][t.j]=t.d;

        for(k=0;k<4;k++)
        {
            i=t.i+di[k];
            j=t.j+dj[k];
            d=t.d+1;

            if(i>=0 && i<n && j>=0 && j<m && d<ans[i][j] && grid[i][j]=='0' && !pushed[i][j])
            {
                temp.i=i;
                temp.j=j;
                temp.d=d;
                pushed[i][j]=true;
                q.push(temp);
            }
        }
    }
}

main()
{
    int i,j,t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            scanf(" %s",grid[i]);

        memset(ans,127,sizeof(ans));
        solve();

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
	return 0;
}
