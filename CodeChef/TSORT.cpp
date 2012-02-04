#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int ip[1000010];

void fastRead(int *a)
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

main()
{
    int i,t;

    scanf("%d",&t);

    for(i=0;i<t;i++)
        fastRead(&ip[i]);

    sort(ip,ip+t);

    for(i=0;i<t;i++)
        printf("%d\n",ip[i]);

    return 0;
}
