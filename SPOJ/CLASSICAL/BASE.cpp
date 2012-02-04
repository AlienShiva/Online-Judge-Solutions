#include<iostream>
#include<cstring>
using namespace std;

main()
{
    int from,to;
    int i,dec,len,pow,temp,space;
    char num[10],ans[50];
    while(EOF!=scanf(" %s %d %d",num,&from,&to))
    {
        len=strlen(num);
        pow=1;
        dec=0;
        for(i=len-1;i>=0;i--)
        {
            if(num[i]>='0' && num[i]<='9')
                temp=num[i]-48;
            else    temp=num[i]-55;
            dec+=temp*pow;
            pow=pow*from;
        }
        i=0;
        while(dec!=0)
        {
            temp=dec%to;
            ans[i]=(temp>9)?55+temp:48+temp;
            dec=dec/to;
            i++;
        }
        if(i<=7)
        {
            space=7-i;
            for(;space;space--)
                printf(" ");
            for(i--;i>=0;i--)
                printf("%c",ans[i]);
        }
        else
            printf("  ERROR");
        printf("\n");
    }
    return 0;
}
