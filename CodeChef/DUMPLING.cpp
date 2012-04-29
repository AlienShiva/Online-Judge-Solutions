#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define ull unsigned long long

ull gcd(ull a, ull b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

main()
{
    int t;
    ull a,b,c,d,k,gcd1,gcd2,lcm,ans;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&k);

        gcd1 = gcd(a,b);
        gcd2 = gcd(c,d);

        lcm = gcd1 / gcd(gcd1,gcd2);

        if((lcm*gcd2)/gcd2 != lcm)
        {
            k=0;
            lcm=1;
        }
        else
            lcm *= gcd2;

        ans = (k/lcm)*2 + 1;

        printf("%lld\n",ans);
    }
    return 0;
}
