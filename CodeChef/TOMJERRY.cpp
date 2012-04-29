#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int i,j;
    vector < pair<int,int> > path;
};

int dy[]= {-1,0,0,1};
int dx[]= {0,1,-1,0};

int m,n,si,sj;
char grid[51][51];
vector < pair<int,int> > shpath;
vector < pair<int,int> > ans;

bool find_move()
{
    queue < node > q;
    node t,temp;
    int k,l;
    bool visited[51][51],found=false;

    memset(visited,false,sizeof(visited));

    t.i=si;
    t.j=sj;

    q.push(t);
    visited[t.i][t.j]=true;
    while(!q.empty())
    {
        t=q.front();
        q.pop();

        if(grid[t.i][t.j]=='0')
        {
            found=true;
            break;
        }

        for(k=0; k<4; k++)
        {
            temp=t;
            temp.i+=dy[k];
            temp.j+=dx[k];

            if(!visited[temp.i][temp.j] && temp.i>=0 && temp.i<m && temp.j>=0 && temp.j<n && grid[temp.i][temp.j]!='#')
            {
                temp.path.push_back(make_pair(temp.i,temp.j));
                q.push(temp);
                visited[temp.i][temp.j]=true;
            }
        }
    }

    if(!found)
        return false;

    shpath=t.path;
    return true;
}

int find_score(int i, int j)
{
    return 0;
}

void solve()
{
    int i,l,cur_score,best_score,best,moves=1;

    while(1)
    {
        if(moves==190)
            break;

        if(!find_move())
            break;

        if(grid[shpath[0].first][shpath[0].second]=='0')
            break;

        best=0;

        grid[shpath[best].first][shpath[best].second]='#';
        ans.push_back(shpath[best]);

        moves++;

        if(!find_move())
            break;

        grid[si][sj]='.';
        si=shpath[0].first;
        sj=shpath[0].second;
        if(grid[si][sj]=='0')
            break;
        grid[si][sj]='*';
    }
}

main()
{
    int i,j;
    char ch;

    scanf("%d %d",&m,&n);

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            scanf(" %c",&ch);

            if(ch=='*')
            {
                si=i;
                sj=j;
            }

            grid[i][j]=ch;
        }

    solve();

    j=ans.size();
    printf("%d\n",j);
    for(i=0; i<j; i++)
        printf("%d %d\n",ans[i].first+1,ans[i].second+1);

    return 0;
}
