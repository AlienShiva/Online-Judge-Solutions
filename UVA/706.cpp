//UVa ID : 706
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

void printNum(int s, char n[])
{
	register int i,j;
	int k,l,x,y,z,e=0;
	int r,c;
	r=2*s+3;
	c=s+2;

	int len=strlen(n);

	char num[r][c];
	if(len==1)
		l=c;
	else
		l=len*c+len-1;

	char val[r][l];

	for(x=0;x<r;x++)
		for(y=0;y<l;y++)
			val[x][y]=' ';


	k=x=y=z=0;

	while(n[k])
	{
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				num[i][j]=' ';

		if(n[k]=='0')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';

			//4
			for(j=1;j<1+s;j++)
				num[r-1][j]='-';

			//5
			for(i=s+2;i<r-1;i++)
				num[i][0]='|';

			//6
			for(i=1;i<1+s;i++)
				num[i][0]='|';
		}

		else
		if(n[k]=='1')
		{
			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';
		}

		else
		if(n[k]=='2')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//4
			for(j=1;j<1+s;j++)
				num[r-1][j]='-';

			//5
			for(i=s+2;i<r-1;i++)
				num[i][0]='|';

			//7
			for(j=1;j<1+s;j++)
				num[1+s][j]='-';
		}

		else
		if(n[k]=='3')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';

			//4
			for(j=1;j<1+s;j++)
				num[r-1][j]='-';

			//7
			for(j=1;j<1+s;j++)
				num[1+s][j]='-';
		}

		else
		if(n[k]=='4')
		{
			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';

			//6
			for(i=1;i<1+s;i++)
				num[i][0]='|';

			//7
			for(j=1;j<1+s;j++)
				num[1+s][j]='-';
		}

		else
		if(n[k]=='5')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';

			//4
			for(j=1;j<1+s;j++)
				num[r-1][j]='-';

			//6
			for(i=1;i<1+s;i++)
				num[i][0]='|';

			//7
			for(j=1;j<1+s;j++)
				num[1+s][j]='-';
		}

		else
		if(n[k]=='6')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';

			//4
			for(j=1;j<1+s;j++)
				num[r-1][j]='-';

			//5
			for(i=s+2;i<r-1;i++)
				num[i][0]='|';

			//6
			for(i=1;i<1+s;i++)
				num[i][0]='|';

			//7
			for(j=1;j<1+s;j++)
				num[1+s][j]='-';
		}

		else
		if(n[k]=='7')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';
		}

		else
		if(n[k]=='8')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';

			//4
			for(j=1;j<1+s;j++)
				num[r-1][j]='-';

			//5
			for(i=s+2;i<r-1;i++)
				num[i][0]='|';

			//6
			for(i=1;i<1+s;i++)
				num[i][0]='|';

			//7
			for(j=1;j<1+s;j++)
				num[1+s][j]='-';
		}

		else
		if(n[k]=='9')
		{
			//1
			for(j=1;j<1+s;j++)
				num[0][j]='-';

			//2
			for(i=1;i<1+s;i++)
				num[i][c-1]='|';

			//3
			for(i=s+2;i<r-1;i++)
				num[i][c-1]='|';

			//4
			for(j=1;j<1+s;j++)
				num[r-1][j]='-';

			//6
			for(i=1;i<1+s;i++)
				num[i][0]='|';

			//7
			for(j=1;j<1+s;j++)
				num[1+s][j]='-';

		}
		
		k++;
		e=z*(c+1);

		for(x=0;x<r;x++)
			for(y=e,j=0;y<e+c;y++,j++)
				val[x][y]=num[x][j];

		z++;
	}

	for(x=0;x<r;x++)
	{
		for(y=0;y<l;y++)
			cout<<val[x][y];
		cout<<endl;
	}
}

main()
{
//	freopen("ip","r",stdin);
//	freopen("op","w",stdout);
	int s;
	char n[10];
	cin>>s>>n;
	while(s || (n[0]-48))	
	{	
		printNum(s,n);

		cin>>s>>n;

		cout<<endl;
		if(!(s || (n[0]-48)))
			break;
	}
	return 0;
}
