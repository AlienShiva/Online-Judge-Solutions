#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100000000

#define check_bit(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define set_bit(x,n) (x[n>>6]&=~(1<<((n>>1)&31)))

#ifdef ONLINE_JUDGE
#define putchar putchar_unlocked
#endif

unsigned isprime[(MAX+100)/64];

inline void fastWrite(int a)
{
    char snum[10];
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
            for (j=i*i,k=i<<1; j<MAX; j+=k)
                set_bit(isprime,j);
        dx=6-dx;
    }

    fastWrite(2);
    cnt=2;
    for (i=5;i<MAX;i+=dx)
    {
        if (check_bit(isprime,i))
            if ((cnt++)==100)
            {
                cnt=1;
                fastWrite(i);
            }
        dx=6-dx;
    }
    return 0;
}
