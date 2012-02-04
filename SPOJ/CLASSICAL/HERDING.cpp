#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n,m,ans;
char grid[1009][1009];
int visited[1009][1009];

bool dfs(int i, int j, int pid)
{
	while(1)
	{
		if(visited[i][j])
		{
			if(visited[i][j]==pid)
				return true;
			else
				return false;
		}

		visited[i][j]=pid;

		switch(grid[i][j])
		{
			case 'W': j--; break;
			case 'E': j++; break;
			case 'N': i--; break;
			case 'S': i++; break;
			default: break;
		}
	}

}

void solve()
{
	int i,j,pid;

	memset(visited,0,sizeof(visited));
	pid=0;
	ans=0;

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(!visited[i][j])
			{
				pid++;
				if(dfs(i,j,pid))
					ans++;
			}
}

main()
{
	int i;

	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++)
		scanf(" %s",grid[i]);

	solve();

	printf("%d\n",ans);

	return 0;
}
