#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 86028125

#define check_bit(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define set_bit(x,n) (x[n>>6]&=~(1<<((n>>1)&31)))

#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

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

inline void fastWrite(int a)
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

unsigned isprime[(MAX+100)/64];
int primes[5000001];

main()
{
    int i,j,k,s,cnt,dx;

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

    primes[1]=2;
    primes[2]=3;
    cnt=3;
    dx=4;
    for (i=5;i<MAX;i+=dx)
    {
        if (check_bit(isprime,i))
            primes[cnt++]=i;
        dx=6-dx;
    }

    fastRead(&k);
    for(i=0;i<k;i++)
    {
        fastRead(&j);
        fastWrite(primes[j]);
    }
    return 0;
}
