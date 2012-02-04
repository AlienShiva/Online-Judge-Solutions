#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int i,t,n;
    char s[51];

    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",&s);

        n=1;
        for(i=0; s[i]; i++)
            if(s[i]=='D')
                n=0;

        if(n)
            printf("Possible\n");
        else
            printf("You shall not pass!\n");
    }
    return 0;
}
