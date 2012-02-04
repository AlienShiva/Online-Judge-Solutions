#include<iostream>
#include<cstring>
using namespace std;

char s[30];

bool machula()
{
        int i;
        for(i=0;s[i];i++)
                if(isalpha(s[i]))
                        return true;
        return false;
}

main()
{
        int t,f1,f2,a;
        scanf("%d",&t);

        while(t)
        {
                scanf("%s",s);
                if(machula())
                {
                        scanf("%s",s);
                        scanf("%s",s);
                        f2=atoi(s);
                        scanf("%s",s);
                        scanf("%s",s);
                        a=atoi(s);
                        if(a>f2)
                                f1=a-f2;
                        else
                                f1=f2-a;
                }
                else
                {
                        f1=atoi(s);
                        scanf("%s",s);
                        scanf("%s",s);
                        if(machula())
                        {
                                scanf("%s",s);
                                scanf("%s",s);
                                a=atoi(s);
                                if(a>f1)
                                        f2=a-f1;
                                else
                                        f2=f1-a;
                        }
                        else
                        {
                                f2=atoi(s);
                                scanf("%s",s);
                                scanf("%s",s);
                                a=f1+f2;
                        }
                }

                printf("%d + %d = %d\n",f1,f2,a);
                t--;
        }
        return 0;
}
