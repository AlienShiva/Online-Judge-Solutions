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
bool visited[10010];

struct node
{
    int v;
    int d;
};

bool operator <(const node& a, const node& b)
{
    return (a.d>b.d);
}

int solve(int s, int e, vector < pair<int,int> > adj[])
{
    priority_queue < node > q;
    node t,temp;
    int alt,l,i,u,v,w;
    int dist[10010];

    memset(dist,127,sizeof(dist));
    memset(visited,false,sizeof(visited));

    dist[s]=0;
    t.v=s;
    t.d=0;
    q.push(t);

    while (!q.empty())
    {
        t=q.top();
        q.pop();

        u=t.v;

        if(visited[u])
        {
            continue;
        }
        visited[u]=true;

        if (u==e)
        {
            break;
        }

        l=adj[u].size();

        for (i=0;i<l;i++)
        {
            v=adj[u][i].first;
            alt=t.d+adj[u][i].second;

            if (alt<dist[v])
            {
                dist[v]=alt;
                temp.v=v;
                temp.d=alt;
                q.push(temp);
            }
        }
    }
    return dist[e];
}

main()
{
    int i,j,e,v,w,r;
    char str[12],name1[12],name2[12];

    scanf("%d",&tc);
    while (tc--)
    {
        map <string,int> names;
        vector < pair<int,int> > adj [10010];

        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf(" %s",str);
            names[str]=i;

            scanf("%d",&e);

            for (j=0;j<e;j++)
            {
                scanf("%d %d",&v,&w);
                adj[i].push_back(make_pair(v-1,w));
            }
        }
        scanf("%d",&r);
        for (i=0;i<r;i++)
        {
            scanf(" %s %s",name1,name2);
            printf("%d\n",solve(names[name1],names[name2],adj));
        }
    }
    return 0;
}
