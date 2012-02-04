#include<iostream>
using namespace std;

int main()
{
	int n,m;
	register int i,j;
	int i1,i6,j1,j3;
	int counter=0;
	char ch;

	cin>>n>>m;

	while(n || m)
	{
		if(counter)
			cout<<endl;
		char mine[n][m];
		bool mi[n][m];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				cin>>ch;
				if(ch=='*')
					mi[i][j]=false;
				else 
				{
					ch='0';
					mi[i][j]=true;
				}
				mine[i][j]=ch;
			}

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(!mi[i][j])
				{
					i1=i-1; 
					j1=j-1;
					j3=j+1;
					i6=i+1; 

					if(i1>=0)
					{
						if(j1>=0 && mi[i1][j1])
							mine[i1][j1]++;
						if(mi[i1][j])
							mine[i1][j]++;
						if(j3<m && mi[i1][j3])
							mine[i1][j3]++;
					}
					if(j1>=0 && mi[i][j1])
						mine[i][j1]++;
					if(j3<m && mi[i][j3])
						mine[i][j3]++;
					if(i6<n)
					{
						if(j1>=0 && mi[i6][j1])
							mine[i6][j1]++;
						if(mi[i6][j])
							mine[i6][j]++;
						if(j3<m && mi[i6][j3])
							mine[i6][j3]++;
					}
				}

		cout<<"Field #"<<++counter<<":\n";

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				cout<<mine[i][j];
			cout<<endl;
		}
		cin>>n>>m;
	}
	return 0;
}
