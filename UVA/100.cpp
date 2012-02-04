#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int len[1000000];

int findlen(long long n)
{
	//cout<<"N="<<n<<endl;
	if(n<1000000 && len[n])
		return len[n];
	else
	{
		int temp;

		if(n & 1)
			temp=1+findlen(3*n+1);
		else
			temp=1+findlen(n>>1);

		if(n<1000000)
			len[n]=temp;

		return temp;
	}
}

main()
{
	//freopen("ip.txt","r",stdin);
	//freopen("op2.txt","w",stdout);

	int ip1,ip2,i,t,a,b,max;
	memset(len,0,1000000);
	len[1]=1;
	while(cin>>ip1>>ip2)
	{
		if(ip1<ip2) { a=ip1; b=ip2; }
		else { a=ip2; b=ip1; }

		max=0;
		for(i=a;i<=b;i++)
		{
			//cout<<"***********"<<'\t'<<i<<'\t'<<"*************\n";
			t=findlen(i);
			if(t>max)
				max=t;
		}

		cout<<ip1<<' '<<ip2<<' '<<max<<endl;
	}
	return 0;
}
