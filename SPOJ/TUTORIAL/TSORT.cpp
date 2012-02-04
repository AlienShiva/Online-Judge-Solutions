#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int ip[1000010];

inline void fastRead(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

inline void fastWrite(int a)
{
    register char c;
    char snum[20];
    int i=0;
    do
    {
        snum[i++]=a%10+48;
        a=a/10;
    }while(a!=0);
    i=i-1;
    while(i>=0)
        putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
}

main()
{
    int i,t;

    fastRead(&t);

    for(i=0;i<t;i++)
        fastRead(&ip[i]);

    sort(ip,ip+t);

    for(i=0;i<t;i++)
        fastWrite(ip[i]);

    return 0;
}