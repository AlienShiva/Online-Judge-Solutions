#include<iostream>
#include<list>
using namespace std;

main()
{
	int n,i,j,l[1001];
	list <int> s;
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&l[i]);
		s.clear();	
		for(j=0,i=1;i<=n && j<n;)
		{
			if(l[j]==i)
			{
				i++;
				j++;
			}
			else
			{
				if(s.size()!=0)
				{
					if(s.front()==i)
					{
						s.pop_front();
						i++;
					}
					else
					{
						s.push_front(l[j]);
						j++;
					}
				}
				else
				{
					s.push_front(l[j]);
					j++;
				}
			}
		}
		while(i!=n+1)
		{
			if(s.front()==i)
			{
				s.pop_front();
				i++;
			}
			else
				break;
		}

		if(i==n+1)
			printf("yes\n");
		else
			printf("no\n");
		scanf("%d",&n);
	}
	return 0;
}
