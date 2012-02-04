#include<iostream>
#include<list>
using namespace std;

main()
{
	int n,rem;
	scanf("%d",&n);
	if(n==0)
	{
		printf("0\n");
	}
	else
	{
		list<int> l;
		while(n!=0)
		{
			rem=n%-2;
			n=n/-2;
			if(rem<0)
			{
				rem+=2;
				n+=1;
			}
			l.push_front(rem);
		}
		list<int>:: iterator i;
		for(i=l.begin();i!=l.end();i++)
			printf("%d",*i);
		printf("\n");
	}	
	return 0;
}
