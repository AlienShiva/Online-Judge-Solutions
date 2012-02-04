#include<iostream>
using namespace std;

main()
{
	int n,d,i,k;
	char a[85];

	scanf("%d",&n);

	k=0;

	scanf("%d",&d);
	scanf("%s",a);	
	printf("%d ",++k);
	d--;
	for(i=0;i<d;i++)
		printf("%c",a[i]);
	for(++i;a[i];i++)
		printf("%c",a[i]);
	n--;
	while(n)
	{
		printf("\n");
		scanf("%d",&d);
		scanf("%s",a);	
		printf("%d ",++k);
		d--;
		for(i=0;i<d;i++)
			printf("%c",a[i]);
		for(++i;a[i];i++)
			printf("%c",a[i]);
		n--;
	}
	return 0;
}
