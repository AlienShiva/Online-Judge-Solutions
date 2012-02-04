#include<iostream>

int t,n,m;
main()
{
	std::cin>>t;
	while(t--)
	{
		std::cin>>n;
		n>0?m+=n:1;
	}
	std::cout<<m;
}
