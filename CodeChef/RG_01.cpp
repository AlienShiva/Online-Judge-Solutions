#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int u;
    int v;
    int d;
};

int E,V;
vector < node > adj[1010];
int ans[1010][1010];
int am[1010][1010];
priority_queue <node> q;
int parent[1010];

bool operator <(const node &a, const node &b)
{
    return (a.d<b.d);
}

int findset(int v)
{
    while (v!=parent[v])
        v=parent[v];
    return v;
}

void bfs(int s)
{
    queue < node > p;
    node t,temp;
    int i,val,l,v;
    bool visited[1010];

    memset(visited,false,sizeof(visited));
    t.v=s;
    t.d=2000000000;
    p.push(t);

    while (!p.empty())
    {
        t=p.front();
        p.pop();

        if (visited[t.v])
            continue;

        visited[t.v]=true;

        ans[s][t.v]=t.d;

        l=adj[t.v].size();
        for (i=0;i<l;i++)
        {
            temp.d=min(adj[t.v][i].d,t.d);
            temp.v=adj[t.v][i].v;
            p.push(temp);
        }
    }
}

main()
{
    int i,j,u,v,d,cnt,pu,pv;
    node t;

    memset(am,-1,sizeof(am));
    for (i=0;i<1010;i++)
        am[i][i]=0;

    scanf("%d %d",&V,&E);

    for (i=0;i<E;i++)
    {
        scanf("%d %d %d",&u,&v,&d);
        t.u=u;
        t.v=v;
        t.d=d;
        q.push(t);
    }

    for (i=0;i<V;i++)
        parent[i]=i;

    cnt=0;
    while (cnt!=V-1 && !q.empty())
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
            am[u][v]=am[v][u]=d;
            parent[pu]=parent[pv];
            cnt++;
        }
    }
	
    for (i=0;i<V;i++)
        for (j=i+1;j<V;j++)
        {
            if (am[i][j]!=-1 && i!=j)
            {
                t.v=j;
                t.d=am[i][j];
                adj[i].push_back(t);
                t.v=i;
                adj[j].push_back(t);
            }
        }

    memset(ans,127,sizeof(ans));
    for (i=0;i<V;i++)
    {
        bfs(i);
        ans[i][i]=0;
    }

    for (i=0;i<V;i++)
    {
        for (j=0;j<V;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}