#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int m,n,k;
char grid[110][110];
char cgrid[110][110];
string ans;

int dj[]={-1,0,1,0};
int di[]={0,-1,0,1};
char dir[]="WNES";
bool ispos[101][101][16];
int ex;

void score(string s)
{
    int i,j,d,l,in,cnt;
    bool visited[110][110];

    memset(visited,false,sizeof(visited));
    l=s.length();

    i=0;j=0;
    cnt=1;
    visited[0][0]=true;
    for(d=0;d<l;d++)
    {
        switch(s[d])
        {
            case 'W': in=0; break;
            case 'N': in=1; break;
            case 'E': in=2; break;
            case 'S': in=3; break;
            default : break;
        }
        i=i+di[in];
        j=j+dj[in];

        if(!visited[i][j])
        {
            visited[i][j]=true;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

bool solve(int i, int j, int l, string s)
{
    ex++;
    if(i==m-1 && j==n-1)
    {
        if(l==0 && grid[i][j]!='t')
            return false;

        ans=s;
        return true;
    }
    else
    {
        bool torch=false;
        if(grid[i][j]=='t')
        {
            torch=true;
            l=k;
            grid[i][j]='.';
        }

        if(l==0)
            return false;

        int in,ti,tj;
        for(in=0;in<4;in++)
        {
            ti=i+di[in];
            tj=j+dj[in];
            if(ti<m && ti>=0 && tj<n && tj>=0 && grid[ti][tj]!='#' && ispos[ti][tj][l-1])
            {
                if(solve(ti,tj,l-1,s+dir[in]))
                    return true;
            }
        }

        if(torch)
            grid[i][j]='t';

        ispos[i][j][l]=false;
        return false;
    }
}

main()
{
    int i,j,t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&m,&n,&k);

        for(i=0;i<m;i++)
            scanf(" %s",grid[i]);

        for(i=0;i<m;i++)
            strcpy(cgrid[i],grid[i]);

        memset(ispos,true,sizeof(ispos));
        ex=0;
        solve(0,0,k,"");

        cout<<ans<<endl;
    }
    return 0;
}