#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char grid[11];
char goal[11];
bool xplace[9],oplace[9];
int count;

bool isfinal(char g[])
{
	if(g[0]!='.' && g[0]==g[1] && g[1]==g[2]) 
		return true;
	if(g[3]!='.' && g[3]==g[4] && g[4]==g[5]) 
		return true;
	if(g[6]!='.' && g[6]==g[7] && g[7]==g[8]) 
		return true;
	if(g[0]!='.' && g[0]==g[3] && g[3]==g[6])
		return true;
	if(g[1]!='.' && g[1]==g[4] && g[4]==g[7])
		return true;
	if(g[2]!='.' && g[2]==g[5] && g[5]==g[8])
		return true;
	if(g[0]!='.' && g[0]==g[4] && g[4]==g[8])
		return true;
	if(g[2]!='.' && g[2]==g[4] && g[4]==g[6])
		return true;

	int i;
	for(i=0;i<9;i++)
		if(g[i]=='.')
			break;
	if(i==9)
		return true;
	else
		return false;
}

bool solve(int p, int sc)
{
	int i;

	i=strcmp(grid,goal);

	if(!i)
		return true;

	if(isfinal(grid) && sc!=count)
	{
		return false;
	}

	if(p==0)
	{
		for(i=0;i<9;i++)
			if(xplace[i])
			{
				xplace[i]=false;
				grid[i]='X';
				if(solve(1,sc+1))
					return true;

				xplace[i]=true;;
				grid[i]='.';
			}
	}
	else
	{
		for(i=0;i<9;i++)
			if(oplace[i])
			{
				oplace[i]=false;
				grid[i]='O';

				if(solve(0,sc+1))
					return true;

				oplace[i]=true;;
				grid[i]='.';
			}
	}
	return false;
}

bool find()
{
	int i;

	memset(xplace,false,sizeof(xplace));
	memset(oplace,false,sizeof(oplace));
	count=0;

	for(i=0;i<9;i++)
		if(goal[i]=='X')
		{ 
			xplace[i]=true;
			count++;
		}
		else if(goal[i]=='O'){
			oplace[i]=true;
			count++;
		}

	memset(grid,'.',sizeof(grid));
	grid[9]='\0';
	return(isfinal(goal) && solve(0,0));
}

main()
{
	scanf("%s",goal);
	while(strcmp(goal,"end"))
	{
		if(find())	printf("valid\n");
		else printf("invalid\n");

		scanf("%s",goal);
	}
	return 0;
}
