#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,cnt;
string ans;
int di[]= {-1,1,-2,2,-2,2,-1,1};
int dj[]= {-2,-2,-1,-1,1,1,2,2};
bool visited[27][27];

bool solve(int i, int j, string s)
{
	if(cnt==(n*m))
	{
		ans=s;
		return true;
	}

	int ti,tj,k;

	for(k=0; k<8; k++)
	{
		ti=i+di[k];
		tj=j+dj[k];

		if(ti>=0 && ti<n && tj>=0 && tj<m && !visited[ti][tj])
		{
			visited[ti][tj]=true;
			cnt++;

			if(solve(ti,tj,(s + char(tj+65) + char(ti+49))))
				return true;
			
			cnt--;
			visited[ti][tj]=false;
		}
	}
	return false;
}

main()
{
	//freopen("fip.txt","r",stdin);
	//freopen("op.txt","w",stdout);

	int t,i,j;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);

		ans="";
		memset(visited,false,sizeof(visited));
		visited[0][0]=true;
		cnt=1;

		if(solve(0,0,"A1"))
		{
			j=ans.length();
			for(i=0; i<j; i++)
				putchar(ans[i]);
		}
		else
		{
			putchar('-');
			putchar('1');
		}
		putchar('\n');
	}
	return 0;
}
