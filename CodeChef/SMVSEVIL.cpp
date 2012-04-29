#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct pos
{
    int x;
    int y;
};

struct node
{
    int x;
    int y;
    int d;
    string path;
};

bool operator <(const node& a, const node& b)
{
    return (a.d>b.d);
}

int T,K,M[26],N[26];
pos S[26],E[26];
char grid[26][80][80];
string ans;
int dy[4]= {0,-1,0,1};
int dx[4]= {-1,0,1,0};
char dir[5]="WNES";

pos rev_dir(char d)
{
    pos diff;

    switch(d)
    {
    case 'W':
        diff.x=0;
        diff.y=-1;
        break;
    case 'N':
        diff.x=-1;
        diff.y=0;
        break;
    case 'E':
        diff.x=0;
        diff.y=1;
        break;
    case 'S':
        diff.x=1;
        diff.y=0;
        break;
    default:
        break;
    }
    return diff;
}

void input_case()
{
    int i,j,l;
    char c;

    scanf("%d",&K);

    for(l=0; l<K; l++)
    {
        scanf("%d %d",&M[l],&N[l]);

        for(i=0; i<M[l]; i++)
        {
            c=0;
            while (c<33) c=getchar();
            for(j=0; j<N[l]; j++)
            {
                grid[l][i][j]=c;

                if(c=='S')
                {
                    S[l].x=i;
                    S[l].y=j;
                }
                else if(c=='E')
                {
                    E[l].x=i;
                    E[l].y=j;
                }

                c=getchar();
            }
            grid[l][i][N[l]]='\0';
        }
    }
}

string shortest_path(int maze_no)
{
    priority_queue <node> q;
    node temp,t;

    int k,m,n;
    pos s,e;

    s=S[maze_no];
    e=E[maze_no];
    m=M[maze_no];
    n=N[maze_no];

    bool visited[m][n];

    memset(visited,false,sizeof(visited));

    t.x=s.x;
    t.y=s.y;
    t.d=0;
    t.path="";

    q.push(t);
    while(!q.empty())
    {
        t=q.top();
        q.pop();

        if(t.x==e.x && t.y==e.y)
            break;

        visited[t.x][t.y]=true;

        for(k=0; k<4; k++)
        {
            temp.x=t.x+dy[k];
            temp.y=t.y+dx[k];
            temp.d=t.d+1;
            temp.path=t.path+dir[k];

            if(grid[maze_no][temp.x][temp.y]!='#' && temp.x>=0 && temp.x<m
                    && temp.y>=0 && temp.y<n && !visited[temp.x][temp.y])
                q.push(temp);
        }
    }

    return t.path;
}

void solve()
{
    int i,j,k,l,m;
    bool solved[K];
    pos mpos[K],diff;
    string path;
    int solve_count;
    node spath[K];

    memset(solved,false,sizeof(solved));

    ans="";

    for(i=0; i<K; i++)
        mpos[i]=S[i];

    for(i=0; i<K; i++)
    {
        spath[i].path=shortest_path(i);
        spath[i].d=spath[i].path.length();
        spath[i].x=i;
    }
    sort(spath,spath+K);

    solve_count=0;
    m=K-1;
    for(i=spath[m].x; solve_count!=K; i=spath[--m].x)
        if(!solved[i])
        {
            path=shortest_path(i);
            l=path.length();

            for(k=0; k<l; k++) // For every letter
            {
                ans+=path[k];
                diff=rev_dir(path[k]);

                for(j=0; j<K; j++) // For every maze
                {
                    if(!solved[j])
                    {
                        mpos[j].x+=diff.x;
                        mpos[j].y+=diff.y;

                        if(mpos[j].x==E[j].x && mpos[j].y==E[j].y)
                        {
                            solved[j]=true;
                            solve_count++;
                            if(solve_count==K)
                            {
                                return;
                            }
                        }

                        if(grid[j][mpos[j].x][mpos[j].y]!='#' && mpos[j].x>=0 && mpos[j].x<M[j] && mpos[j].y>=0 && mpos[j].y<N[j])
                            ;
                        else
                        {
                            mpos[j].x-=diff.x;
                            mpos[j].y-=diff.y;
                        }

                        grid[j][S[j].x][S[j].y]='.';
                        S[j].x=mpos[j].x;
                        S[j].y=mpos[j].y;
                    }
                }
            }

        }
}

main()
{
    scanf("%d",&T);

    while(T--)
    {
        input_case();
        solve();
        cout<<ans<<endl;
    }
    return 0;
}
