#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t,n,i,m[1005],w[1005],sum;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&m[i]);
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		sort(m,m+n);
		sort(w,w+n);
		sum=0;
		for(i=0;i<n;i++)
			sum+=m[i]*w[i];
		printf("%d\n",sum);
		t--;
	}
	return 0;
}
