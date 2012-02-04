#include<iostream>
using namespace std;

main()
{
    int i,j,ch;
    bool _flag,capFlag,cons_flag,caps;
    char prev,s[1000];

    while(scanf(" %s",s)!=EOF)
    {
        prev=0;
        ch=0;
        _flag=capFlag=cons_flag=false;
        for(i=0;s[i];i++)
        {
            if(s[i]=='_')
            {
                _flag=true;
                if(prev=='_')
                    cons_flag=true;
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                capFlag=true;
                ch++;
            }
            else
                ch++;
            prev=s[i];
        }

        if((capFlag && _flag)||cons_flag||ch==0||(s[0]>='A'&&s[0]<='Z')||s[0]=='_'||s[i-1]=='_')
            printf("Error!\n");

        else if(capFlag)
        {
            for(i=0;s[i];i++)
                if(s[i]>='A' && s[i]<='Z')
                    printf("_%c",s[i]+32);
                else
                    printf("%c",s[i]);
            printf("\n");
        }

        else
        {
            caps=false;
            for(i=0;s[i];i++)
            {
                if(s[i]=='_')
                {
                    caps=true;
                }
                else
                {
                    if(caps==true)
                    {
                        printf("%c",s[i]-32);
                        caps=false;
                    }
                    else
                        printf("%c",s[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
