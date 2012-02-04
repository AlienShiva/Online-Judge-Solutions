#include <stdio.h>
#define ull unsigned long long

void r(ull *a)
{
    register char c=0;
    while (c<33)c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

main()
{
    int i;
    ull n,ans,t;
    r(&t);
    for (i=0;i<t;i++)
    {
        r(&n);
        ans=(n*(n+2)*((n<<1)+1));
        printf("%llu\n",ans>>3);
    }
    return 0;
}
