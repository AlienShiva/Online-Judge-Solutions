#include<iostream>
using namespace std;

main()
{
	int k=0,n;
	double val;
	char s[3];
	scanf("%d",&n);

	scanf("%lf %s",&val,s);
	if(s[0]=='k')
		printf("%d %.4lf lb",++k,val*2.2046);

	else if(s[0]=='g')
		printf("%d %.4lf l",++k,val*3.7854);

	else if(s[0]=='l' && s[1]=='\0')
		printf("%d %.4lf g",++k,val*0.2642);

	else
		printf("%d %.4lf kg",++k,val*0.4536);

	n--;

	while(n)
	{
		printf("\n");
		scanf("%lf %s",&val,s);
		if(s[0]=='k')
			printf("%d %.4lf lb",++k,val*2.2046);

		else if(s[0]=='g')
			printf("%d %.4lf l",++k,val*3.7854);

		else if(s[0]=='l' && s[1]=='\0')
			printf("%d %.4lf g",++k,val*0.2642);

		else
			printf("%d %.4lf kg",++k,val*0.4536);

		n--;
	}
	return 0;
}
