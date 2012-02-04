#include<iostream>
using namespace std;

main()
{
	int n,m,t;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d",&n);
		m=0;
		while(n)
		{
			n=n/5;
			m+=n;
		}
		printf("%d\n",m);
		t--;
	}
	return 0;
}
