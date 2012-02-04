#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

char grid[1010][1010];
int maxl;
bool visited[1010][1010];
int r,c;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int endx,endy;

void bfs(int i, int j)
{
	int k,d,ti,tj;
	queue<int> q;

	d=0;
	memset(visited,false,sizeof(visited));

	q.push(i);
	q.push(j);
	q.push(d);

	while(!q.empty())
	{
		i=q.front();
		q.pop();
		j=q.front();
		q.pop();
		d=q.front();
		q.pop();

		visited[i][j]=true;

		if(d>maxl)
		{
			maxl=d;
			endx=i;
			endy=j;
		}

		for(k=0;k<4;k++)
		{
			ti=i+dy[k];
			tj=j+dx[k];
			if(ti>=0 && ti<r && tj>=0 && tj<c)
			{
				if(grid[ti][tj]=='.' && !visited[ti][tj])
				{
					q.push(ti);
					q.push(tj);
					q.push(d+1);
				}
			}
		}

	}
}

void findmax()
{
	int i,j;

	maxl=0;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			if(grid[i][j]=='.')
				break;
		if(j!=c)
			break;
	}

	bfs(i,j);
	bfs(endx,endy);
}

main()
{
	int t,i,j;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&c,&r);

		for(i=0;i<r;i++)
		{
			scanf(" %s",grid[i]);
		}
		findmax();
		printf("Maximum rope length is %d.\n",maxl);
	}
	return 0;
}
