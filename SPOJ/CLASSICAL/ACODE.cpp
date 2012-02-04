#include<iostream>
#include<cstring>
using namespace std;

char a[60000];
int64_t dp[60000];
bool visited[60000];
int64_t cases, single;

void acode(int i)
{
	if(!visited[i])
	{
		if(a[i]=='\0')
			cases++;
	
		else  if(a[i]!='0')
		{
			acode(i+1);
			if((a[i+1]!='\0') && (10*a[i]+a[i+1] <=554))
				acode(i+2);
		}
		dp[i]=cases;
		visited[i]=true;
	}
	else
		cases+=dp[i];
}

main()
{
	int i,l;
	scanf("%s",a);
	while(a[0]!='0')
	{
		l=strlen(a);
		for(i=0;i<=l;i++)
		{
			visited[i]=false;
			dp[i]=0;
		}
		cases=single=0;
		acode(0);
		printf("%lld\n",cases);
		scanf("%s",a);
	}
	return 0;
}
