#include<iostream>
using namespace std;

main()
{
	int n;
	scanf("%d",&n);
	
	if(n!=0)
		printf("%d",(n*(n+1)*((n<<1)+1))/6);
	
	scanf("%d",&n);
	
	while(n!=0)
	{
		printf("\n");
		printf("%d",(n*(n+1)*((n<<1)+1))/6);
		scanf("%d",&n);
	}
	return 0;
}
