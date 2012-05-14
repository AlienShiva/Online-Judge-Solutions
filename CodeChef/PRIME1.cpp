#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

main()
{
    int i,j,t,s,m,n,r;
    bool isprime[32000];
    bool range[100000];
    memset(isprime,true,32000);
    isprime[0]=isprime[1]=false;

    for(i=2;i<31630;i++)
        if(isprime[i])
        {
            for(j=i*2;j<31630;j+=i)
                isprime[j]=false;
        }

    scanf("%d",&t);
    while(t)
    {
        scanf("%d %d",&m,&n);
        s=n-m+1;
        r=sqrt(n)+1;
        memset(range,true,s);
        if(m==1) range[0]=false;
        for(i=2;i<r;i++)
            if(isprime[i])
            {
                j=m/i*i;
                if(j<m)
                    j+=i;
                if(j==i)
                    j+=i;
                j-=m;
                for(;j<s;j+=i)
                    range[j]=false;
            }
        for(i=0;i<s;i++)
            if(range[i])
                printf("%d\n",m+i);
        printf("\n");
        t--;
    }
    return 0;
}
