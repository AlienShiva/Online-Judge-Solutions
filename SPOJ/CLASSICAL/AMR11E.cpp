#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 200000
int pcount[MAX];
bool prime[MAX];
int ans[1001];

main()
{
    int i,j,t,n;

    memset(prime,true,sizeof(prime));

    for(i=2; i*i<MAX; i++)
        if(prime[i])
            for(j=i; j<MAX; j+=i)
            {
                prime[j]=false;
                pcount[j]++;
            }

    for(i=1,j=1; i<MAX && j!=1001; i++)
        if(pcount[i]>2)
            ans[j++]=i;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
