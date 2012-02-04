#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
	char digits[20][15]={"S",".","..","...","....","-",". -",".. -","... -",".... -",
		"- -",". - -",".. - -","... - -",".... - -","- - -",". - - -",".. - - -","... - - -",".... - - -"};

	int val[8]={0,1,20,360,7200,144000,2880000,57600000};

	int n,i,k,num;
	char ip[8][100];

	scanf("%d",&n);
	while(n)
	{
		for(i=n;i>0;i--)
		{
			scanf(" %[^\n]s",ip[i]);
		}

		num=0;
		for(i=1;i<=n;i++)
		{
			for(k=0;k<20;k++)
				if(strcmp(ip[i],digits[k])==0)
					break;
			num = num + k * val[i];
		}
		
		printf("%d\n",num);

		scanf("%d",&n);
	}
	return 0;
}
