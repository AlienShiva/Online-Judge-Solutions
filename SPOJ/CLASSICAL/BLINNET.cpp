#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,tc;
int parent[10010];

struct node
{
    int u;
    int v;
    int d;
};

bool operator <(const node& a, const node& b)
{
    return (a.d>b.d);
}

int findset(int v)
{
    while (v!=parent[v])
        v=parent[v];
    return v;
}

main()
{
    int i,j,e,v,w,r,cnt,u,d,pu,pv;
    char str[12];
    node t;
    int ans;

    scanf("%d",&tc);
    while (tc--)
    {
        priority_queue <node> q;

        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf(" %s",str);
            scanf("%d",&e);

            for (j=0;j<e;j++)
            {
                scanf("%d %d",&v,&w);
                t.u=i;
                t.v=v-1;
                t.d=w;
                if (t.v>i)
                    q.push(t);
            }
        }

        cnt=0;
        ans=0;

        for (i=0;i<n;i++)
            parent[i]=i;

        while (cnt<n-1 && !q.empty())
        {
            t=q.top();
            q.pop();
            u=t.u;
            v=t.v;
            d=t.d;

            pu=findset(u);
            pv=findset(v);

            if (pu!=pv)
            {
                ans+=d;
                parent[pu]=parent[pv];
                cnt++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
