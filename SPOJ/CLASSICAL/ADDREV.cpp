#include<iostream>
#include<cstdlib>
using namespace std;

int rev(int n)
{
	int m,i=0;
	char s[10];
	while(n!=0)
	{
		s[i]=(n%10)+48;
		n=n/10;
		i++;
	}
	s[i]='\0';
	m=atoi(s);
	return m;
}

main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",rev(rev(n)+rev(m)));
		t--;
	}
	return 0;
}
