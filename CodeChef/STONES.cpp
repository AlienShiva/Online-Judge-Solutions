#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

main()
{
    int t,i,cnt;
    char j[101],s[101];
    bool present[128];

    scanf("%d",&t);
    while(t--)
    {
        scanf(" %[^\n]s",j);
        scanf(" %[^\n]s",s);

        memset(present,false,sizeof(present));
        for(i=0; j[i]; i++)
            present[j[i]]=true;

        cnt=0;
        for(i=0; s[i]; i++)
            if(present[s[i]])
                cnt++;

        printf("%d\n",cnt);
    }

    return 0;
}
