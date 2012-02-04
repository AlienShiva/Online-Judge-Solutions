#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int t,r,c;
    long long k,m;
    int pt[]={942,192,442,692};

    scanf("%d",&t);

    while (t--)
    {
        scanf("%lld",&k);

        r=k%4;
        c=0;

        if(r==0)
            c=1;

        m=pt[r] + ((k/4)-c)*1000;

        printf("%lld\n",m);
    }
    return 0;
}
