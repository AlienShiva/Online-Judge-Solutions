#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <ctype.h>
using namespace std;

void strupr(char a[])
{
	int i;
	for(i=0;a[i];i++)
		a[i]=toupper(a[i]);
}

main()
{
	//freopen("ip.txt","r",stdin);
	char ip[55][55];
	char words[22][55];
	int t,n,m,k,i,j,r,g,h,in,tc,wlen,mlen;
	int row,col;
	cin>>t;
	for(tc=0;tc<t;tc++)
	{
		if(tc) cout<<endl;
		cin>>m>>n;
		for(i=0;i<m;i++)
		{
			cin>>ip[i];
			strupr(ip[i]);
		}

		cin>>k;
		for(i=0;i<k;i++)
		{
			cin>>words[i];
			strupr(words[i]);
		}
		for(r=0;r<k;r++)
		{
			wlen=strlen(words[r]);
			//cout<<words[r]<<endl;
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					if(ip[i][j]==words[r][0])
					{
						//cout<<"Pos : "<<i<<","<<j<<endl;
						for(mlen=1,in=1,g=j+1; g<n && ip[i][g]==words[r][in]; g++,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}
					
						for(mlen=1,in=1,g=j-1; g>=0 && ip[i][g]==words[r][in]; g--,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}

						for(mlen=1,in=1,h=i+1; h<m && ip[h][j]==words[r][in]; h++,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}
						for(mlen=1,in=1,h=i-1; h>=0 && ip[h][j]==words[r][in]; h--,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}
						for(mlen=1,in=1,h=i-1,g=j-1; h>=0 && g>=0 && ip[h][g]==words[r][in]; h--,g--,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}
						for(mlen=1,in=1,h=i-1,g=j+1; h>=0 && g<n && ip[h][g]==words[r][in]; h--,g++,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}
						for(mlen=1,in=1,h=i+1,g=j+1; h<m && g<n && ip[h][g]==words[r][in]; h++,g++,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}
						for(mlen=1,in=1,h=i+1,g=j-1; h<m && g>=0 && ip[h][g]==words[r][in]; h++,g--,mlen++,in++);
						if(mlen==wlen)
						{
							row=i;
							col=j;
							i=m;
							break;
						}
					}
			cout<<row+1<<' '<<col+1<<endl;
		}
	}	
	return 0;
}
