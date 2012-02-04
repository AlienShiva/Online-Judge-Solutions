#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

main()
{
    int t,n,i;
    char s[35],c;
    map <string,int> :: iterator in;

    scanf("%d",&t);
    while (t--)
    {
        map <string, int> acc;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            c=0;
            while(c<33) c=getchar();
            ungetc(c,stdin);
            gets(s);
            acc[s]++;
        }
        for (in=acc.begin(); in!=acc.end();in++)
            printf("%s %d\n",in->first.c_str(),in->second);
        printf("\n");
    }
    return 0;
}
