#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int m,n;
char grid[25][25];
bool visited[25][25];
int imp[15][2];
int dist[15][15];
int impcd[25][25];
int finalstate;
int ntotal;
int sti,stj;
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
int dp[4096][13];

int find(int state, int prev)
{
	if(state==finalstate)
	{
		return 0;		
	}

	if(dp[state][prev])
		return dp[state][prev];

	int i,ans;
	ans=1<<30;
	for(i=0;i<ntotal;i++)
	{
		if(!(state & (1<<i)))
		{
			int temp=find(state|(1<<i),i);
			ans = min(ans,dist[prev][i] + temp);
		}
	}
	dp[state][prev]=ans;
	return ans;
}

void bfs(int nodenum)
{
	int d;
	int k,ti,tj,td,ni,nj,nd;
	queue<int> q;
	int i,j;

	i=imp[nodenum][0];
	j=imp[nodenum][1];
	d=0;
	q.push(i);
	q.push(j);
	q.push(d);

	while(!q.empty())
	{
		ti=q.front();
		q.pop();
		tj=q.front();
		q.pop();
		td=q.front();
		q.pop();

		if(visited[ti][tj])
			continue;

		visited[ti][tj]=true;

		if(grid[ti][tj]=='*' || grid[ti][tj]=='o')
		{
			dist[nodenum][impcd[ti][tj]]=td;
		}

		for(k=0;k<4;k++)
		{
			ni=ti+diry[k];
			nj=tj+dirx[k];
			nd=td+1;
			if( (ni>=0 && ni<m) && (nj>=0 && nj<n) && grid[ni][nj]!='x')
			{
				q.push(ni);
				q.push(nj);
				q.push(nd);
			}
		}
	}
}

int solve()
{
	int i,j;
	finalstate=ntotal=0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(grid[i][j]== '*' || grid[i][j] == 'o')
			{
				finalstate=(finalstate << 1)+1;			
				imp[ntotal][0]=i;
				imp[ntotal][1]=j;
				impcd[i][j]=ntotal;
				ntotal++;
				if(grid[i][j]=='o')
				{
					sti=i;
					stj=j;
				}
			}
		}
	memset(dist,-1,sizeof(dist));
	memset(visited,false,sizeof(visited));
	i=impcd[sti][stj];
	bfs(i);

	dist[i][i]=0;
	for(j=0;j<ntotal;j++)
		if(dist[i][j]==-1)
			return -1;

	for(i=0;i<ntotal;i++)
	{
		memset(visited,false,sizeof(visited));
		bfs(i);
		dist[i][i]=0;
	}
	i=impcd[sti][stj];
	memset(dp,0,sizeof(dp));
	return find(0+(1<<i),impcd[sti][stj]);
}

main()
{
	int i,j;

	scanf("%d %d",&n,&m);
	while(n&&m)
	{
		for(i=0;i<m;i++)
			scanf("%s",grid[i]);

		printf("%d\n",solve());

		scanf("%d %d",&n,&m);
	}
	return 0;
}
