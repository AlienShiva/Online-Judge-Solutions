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

bool operator<(node a, node b)
{
    return (a.d>b.d);
}

int n,m,tb,di,dj;
int grid[101][101];
int ans;

int diffy[]= {0,-1,0,1};
int diffx[]= {-1,0,1,0};

bool solve()
{
    int k;
    bool visited[m][n];
    node temp,t;
    priority_queue <node> q;

    memset(visited,false,sizeof(visited));

    t.i=0;
    t.j=0;
    t.d=grid[0][0];

    q.push(t);
    while(!q.empty())
    {
        t=q.top();
        q.pop();

        visited[t.i][t.j]=true;

        if(t.i==di && t.j==dj)
            break;

        for(k=0; k<4; k++)
        {
            temp.i=t.i+diffy[k];
            temp.j=t.j+diffx[k];
            temp.d=t.d+grid[temp.i][temp.j];

            if(!visited[temp.i][temp.j] && temp.i>=0 && temp.i<m && temp.j>=0 && temp.j<n)
                q.push(temp);
        }
    }

    ans=tb-t.d;

    if(t.d<=tb)
        return true;
    else
        return false;
}

main()
{
    int i,j,k;

    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d",&m,&n);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%d",&grid[i][j]);

        scanf("%d %d %d",&di,&dj,&tb);
        di--;
        dj--;

        if(solve())
        {
            printf("YES\n%d\n",ans);
        }
        else
            printf("NO\n");
    }
    return 0;
}
