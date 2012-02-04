#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    bool prime[1000010];
    int t,n,i,j,cnt,num,m,f;

    memset(prime,true,sizeof(prime));
    for (i=2;i<1002;i++)
        if (prime[i])
            for (j=i<<1;j<1000010;j+=i)
                prime[j]=false;

    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);

        if (prime[n])
        {
            printf("1\n");
            continue;
        }

        m=0;
        num=n;

        for (i=2;i<n && num!=1;i++)
            if (prime[i])
            {
                cnt=0;
                while (num%i==0)
                {
                    cnt++;
                    num=num/i;
                }
                if(m<cnt)
                    m=cnt;
            }
        printf("%d\n",m);
    }
    return 0;
}
