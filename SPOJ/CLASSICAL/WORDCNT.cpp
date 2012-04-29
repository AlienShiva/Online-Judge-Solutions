#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int t,cur,prev,cnt,mcnt;
    char str[40000];
    char *word;

    scanf("%d\n",&t);
    while(t--)
    {
        fgets(str,40000,stdin);

        cur=cnt=mcnt=0;
        prev=-1;

        for(word=strtok(str," \t\r\n"); word!=NULL; word=strtok(NULL," \t\r\n"))
        {
            cur=strlen(word);
            if(cur==prev)
                cnt++;
            else
            {
                mcnt=max(mcnt,cnt);
                cnt=1;
            }
            prev=cur;
        }
        mcnt=max(mcnt,cnt);
        printf("%d\n",mcnt);
    }
    return 0;
}

