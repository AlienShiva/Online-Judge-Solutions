#include<iostream>
using namespace std;

void rev(char a[],int i,int n)
{
	int j,k;
	k=i+n;
	char temp;
	for(j=0;j<n/2;j++,i++)
	{	
		temp=a[i];
		a[i]=a[k-j-1];
		a[k-j-1]=temp;
	}
}

main()
{
//	freopen("ip","r",stdin);
//	freopen("op","w",stdout);
	int i,j,row,n,k;
	char s[205];
	scanf("%d",&n);
	while(n)
	{
		scanf("%s",s);
		i=n;
		row=1;
		while(s[i]!='\0')
		{
			rev(s,i,n);
			i+=n; row++;
			if(s[i]=='\0')
				break;
			else
			{
				i+=n;
				row++;
			}
		}
		for(i=0;i<n;i++)
			for(j=i,k=0;k<row;k++,j+=n)
				printf("%c",s[j]);
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
