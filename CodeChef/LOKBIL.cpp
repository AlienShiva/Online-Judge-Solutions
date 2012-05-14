#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n,root;
double avg;

void solve(vector <int> adj[])
{
	int i,j,k,l,d,cnt,tcnt,temp;
	bool visited[110];

	cnt=1000000000;

	for(k=0;k<n;k++)
	{
		queue < int  > q;

		memset(visited,false,sizeof(visited));

		q.push(k);
		q.push(0);
		visited[k]=true;

		tcnt=0;

		while(!q.empty())
		{
			i=q.front();
			q.pop();
			d=q.front();
			q.pop();

			tcnt=tcnt+d;

			l=adj[i].size();

			for(j=0;j<l;j++)
			{
				temp=adj[i][j];
				if(!visited[temp])
				{
					visited[temp]=true;
					q.push(temp);
					q.push(d+1);
				}
			}
		}

		if(tcnt<cnt)
		{
			cnt=tcnt;
			root=k;
		}
	}
	avg=double(cnt)/n;
}

main()
{
	int t,i,j,temp;
	char ch;

	scanf("%d",&t);
	while(t--)
	{
		vector <int> adj[110];

		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
			ch=0;
			while(ch!='\n')
			{
				while(ch<33) ch=getchar_unlocked();

				temp=0;
				while (ch>33)
				{
					temp=temp*10+ch-'0';
					ch=getchar_unlocked();
				}
				adj[i].push_back(temp-1);
			}
		}

		solve(adj);

		printf("%d %.6lf\n",root+1,avg);
	}
	return 0;
}
