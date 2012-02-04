#include<iostream>
#include<list>
using namespace std;

main()
{
//	freopen("ip","r",stdin);
	list <char> s;
	char exp[408];
	int t,i;
	char ch;
	scanf("%d",&t);
	while(t)
	{
		scanf("%s",exp);
		i=0;
		while(exp[i])
		{	
			if(exp[i]==')')
			{
				ch=s.front();
				s.pop_front();
				while(ch!='(')
				{
					printf("%c",ch);
					ch=s.front();
					s.pop_front();
				}
			}

			else if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' & exp[i]<='Z'))			
				printf("%c",exp[i]);

			else
				s.push_front(exp[i]);

			i++;
		}
		printf("\n");
		t--;
	}
	return 0;
}
