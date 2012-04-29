#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    char n;
    int t,cnt,cl;

    scanf("%d",&t);
    while(t--)
    {
        cnt=cl=n=0;

        while (n<33) n=getchar();
        while (n>33)
        {
            if(n=='4' || n=='7')
                cl++;
            cnt++;
            n=getchar();
        }

        printf("%d\n",cnt-cl);
    }
    return 0;
}
