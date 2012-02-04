#include<stdio.h>

main()
{
	int t;
	long long a,b;
	char s[25],s1[2];
	scanf("%d",&t);
	while(t)
	{	
		a=b=0;
		scanf("%s",s);
		a=atoi(s);
		while(1)
		{
			scanf("%s",s1);
			if(s1[0]=='=')
				break;
			scanf("%s",s);
			b=atoi(s);
			if(s1[0]=='+')
				a+=b;

			else if(s1[0]=='-')
				a-=b;

			else if(s1[0]=='/')
				a/=b;

			else if(s1[0]=='*')
				a*=b;
		}
		printf("%lld\n",a);
		t--;
	}
	return 0;
}
