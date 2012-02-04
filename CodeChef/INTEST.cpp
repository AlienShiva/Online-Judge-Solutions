#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

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

main()
{
	//freopen("ip.txt","r",stdin);
	//freopen("op.txt","w",stdout);

    int i,cnt=0,n,k,num;

    fastRead(&n);
    fastRead(&k);

    for(i=0;i<n;i++)
    {
        fastRead(&num);
        if(num%k==0)
            cnt++;
    }
    printf("%d\n",cnt);
	return 0;
}
