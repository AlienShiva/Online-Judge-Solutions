#include<iostream>
#include<cstring>
using namespace std;

main()
{
	char a[5000];
	int n,i,j,k,l,f,beg,end;
	scanf("%s",a);
	while(a[0]!='.')
	{
		scanf("%d",&n);
		l=strlen(a);
		f=n*l;
		for(i=0,j=1000;i<l;i++,j++)
		{
			for(k=0;k<f;k+=l)
				a[j+k]=a[i];
		}
		end=1000+f;
		beg=1000;
		for(i=0;i<l;i++)
		{
			for(j=beg;j<end;j++)
				printf("%c",a[j]);
			printf("\n");
			a[end++]=a[beg++];
		}		
		scanf("%s %d",a,&n);
	}
	return 0;
}
