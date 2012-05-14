#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int n,si,pi,i,l,eight,five,three,cnt;
    char str[2000];
    bool isciel;

    cnt=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf(" %[^\n\r]s",str);

        isciel=true;
        eight=five=three=0;

        l=strlen(str);

        for(i=l; i>=0 && !isdigit(str[i]); i--);

        for( ; i>=0 && isdigit(str[i]); i--)
            if(str[i]=='8') eight++;
            else if(str[i]=='5') five++;
            else if(str[i]=='3') three++;
            else
            {
                isciel=false;
                break;
            }

        if(isciel && eight>=five && five>=three)
            cnt++;
    }

    printf("%d\n",cnt);

    return 0;
}
