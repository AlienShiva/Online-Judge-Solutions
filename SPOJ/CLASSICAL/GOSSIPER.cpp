#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#define check_bit(x,i,j) (x[i][j>>5] & (1<<(j&31)))
#define set_bit(x,i,j) (x[i][j>>5] |= (1<<(j&31)))

unsigned int gp[2100][66];

main()
{
	//freopen("gip.txt","r",stdin);
	//freopen("op.txt","w",stdout);

	int n,m,i,j,k,l,ncells;
	char s[100],f[100];
	bool ans;

	scanf("%d %d",&n,&m);
	while(m || n)
	{
		memset(gp,0,sizeof(gp));
		map <string, int> names;
		ncells=n/32 + 1;
		
		for(i=0; i<n; i++)
		{
			scanf(" %s",s);
			names[s]=i;
			set_bit(gp,i,i);
		}

		for(i=0; i<m; i++)
		{
			scanf(" %s",f);
			scanf(" %s",s);

			j=names[f];
			k=names[s];

			for(l=0; l<ncells; l++)
				gp[j][l]=gp[k][l]= gp[j][l] | gp[k][l];	
		}

		ans=true;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(!(check_bit(gp,i,j)))
					ans=false;

		if(ans)
			printf("YES\n");
		else
			printf("NO\n");

		scanf("%d %d",&n,&m);
	}
	return 0;
}
