#include<stdio.h>

main()
{
        int n,i,p=1;
        char text[10000];
        char ch,cur,next;

        n=0;

        while(EOF!=scanf("%c",&text[n]))
                n++;

        for(i=0;i<n;i++)
        {
                cur=text[i];
                if(i+1<n)
                        next=text[i+1];
                if(cur=='\\')
                {
                        if(p)
                        {
                                if(next=='*')
                                {
                                        p=0;
                                        i++;
                                        continue;
                                }
                                if(next=='b'||next=='i')
                                {
                                        i++;
                                        continue;
                                }
                                else if(next=='s')
                                {
                                        i+=2;
                                        while(i<n && ((text[i]>='0' && text[i]<='9') || text[i]=='.'))
                                        i++;
                                        i--;
                                }
                                else
                                {
                                        printf("%c",next);
                                        i++;
                                }
                        }
                        else
                        {
                                if(next=='*')
                                {
                                        p=1;
                                        i++;
                                        continue;
                                }
                                else
                                        printf("%c",cur);
                        }
                }
                else
printf("%c",cur);
        }
        return 0;
}
