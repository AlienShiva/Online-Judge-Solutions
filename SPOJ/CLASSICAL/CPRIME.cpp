#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100000010

#define check_bit(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define set_bit(x,n) (x[n>>6]&=~(1<<((n>>1)&31)))

unsigned isprime[(MAX+100)/64];

main()
{
    int i,j,k,t,s,dx,n,cnt;
    int interval[102];
    double ans;

    memset(isprime,255,sizeof(isprime));

    s=sqrt(MAX)+1;

    for (j=9; j<MAX; j+=6)
        set_bit(isprime,j);

    dx=4;
    for (i=5; i<s; i+=dx)
    {
        if (check_bit(isprime,i))
        {
            for (j=i*i,k=i<<1; j<MAX; j+=k)
                set_bit(isprime,j);
        }
        dx=6-dx;
    }

    cnt=2;
    dx=4;
    k=0;
    i=5;
    j=1000000;
    while (j<MAX)
    {
        for (; i<=j; i+=dx)
        {
            if (check_bit(isprime,i))
                cnt++;
            dx=6-dx;
        }
        interval[k]=cnt;
        j+=1000000;
        k++;
    }

    scanf("%d",&n);
    while (n)
    {
        if (n<=2)
            cnt=1;
        else if(n<1000000)
        {
            cnt=2;
            dx=4;
            for (i=5; i<=n; i+=dx)
            {
                if (check_bit(isprime,i))
                    cnt++;
                dx=6-dx;
            }
        }
        else
        {
            cnt=interval[n/1000000-1];
            i=(n/1000000)*1000000+1;
            for (; i<=n; i+=2)
            {
                if (check_bit(isprime,i))
                    cnt++;
            }
        }
        ans=fabs(cnt-(n/log(n)))*100.0/cnt;
        printf("%.1lf\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
