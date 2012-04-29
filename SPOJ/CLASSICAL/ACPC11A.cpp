#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int t,n,i,flag;
    char words[1200];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf(" %[^\n]s",words);

        n=strlen(words);
        flag=-1;
        for(i=0; i<n; i++)
            if(isalpha(words[i]))
            {
                flag=i;
                break;
            }

        if(flag==-1)
            printf("%s\n",words);

        else
        {
            for(i=flag; i<n && words[i]!='#'; i++)
                ;

            printf("%s",words+i);

            if(i<n)
                printf(" ");

            for(i=flag; i<n && words[i]!=' '; i++)
                printf("%c",words[i]);

            if(flag>0)
                printf(" ");

            for(i=0; i<flag; i++)
                printf("%c",words[i]);

            printf("\n");
        }
    }

    return 0;
}
