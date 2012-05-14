#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define ULL unsigned long long

int n,m;

inline void fastRead(int *a)
{
    register char c=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}

inline void fastWrite(ULL a)
{
    char snum[20];
    int i=0;
    do
    {
        snum[i++]=a%10+48;
        a=a/10;
    }
    while (a);
    i=i-1;
    while (i>=0)
        putchar(snum[i--]);
    putchar('\n');
}

ULL sum_prev_sets()
{
    ULL type2=m-(m/2)-1;
    ULL type1=m-type2;
    ULL k=n/m;

    ULL ans=(type1* k *(k-1))/2 + (type2 * k * (k+1))/2;
    return ans;
}

ULL sum_cur_set()
{
    ULL start=n/m;
    ULL npos=n%m;
    ULL ans=0;
    ULL half=ceil(m/2);

    if(npos<=half)
        ans=npos*start;
    else
    {
        ans=half*start+(npos-half)*(start+1);
    }

    return ans;
}

main()
{
    int t;

    scanf("%d",&t);
    while(t--)
    {
        fastRead(&n);
        fastRead(&m);

        ULL ans=sum_prev_sets()+sum_cur_set();

        fastWrite(ans);
    }

    return 0;
}
