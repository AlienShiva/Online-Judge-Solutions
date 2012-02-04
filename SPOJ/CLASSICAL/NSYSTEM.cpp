#include<iostream>
using namespace std;

int todecimal(char a[])
{
    int c,num,k,i,j;
    int pre[4]={0,0,0,0};
    num=c=0;
    for(i=0;a[i];i++)
    {
        if(a[i]>97)
        {
            c=i;
            if(a[i]=='m')
                k=3;
            else if(a[i]=='c')
                k=2;
            else if(a[i]=='x')
                k=1;
            else
                k=0;
            if(a[i-1]>97 || i==0)
                pre[k]=1;
            else
            {
                j=1;
                for(i--;a[i]<97 && i>=0;i--,j=j*10)
                    pre[k]+=(a[i]-48)*j;
                i=c;
            }
        }
    }
    num=pre[0]+10*pre[1]+100*pre[2]+1000*pre[3];
    return num;
}

main()
{
    char a[20],b[20];
    int t,sum,k,temp,m,c,x,i;

    scanf("%d",&t);
    while(t)
    {
        scanf(" %s %s",a,b);
        sum=todecimal(a)+todecimal(b);

        i=sum%10; sum=sum/10;
        x=sum%10; sum=sum/10;
        c=sum%10; sum=sum/10;
        m=sum%10; sum=sum/10;

        if(m>0)
        {
                if(m==1)    printf("m");
                else    printf("%dm",m);
        }
        if(c>0)
        {
                if(c==1)    printf("c");
                else    printf("%dc",c);
        }
        if(x>0)
        {
                if(x==1)    printf("x");
                else    printf("%dx",x);
        }
        if(i>0)
        {
                if(i==1)    printf("i");
                else    printf("%di",i);
        }
        printf("\n");

        t--;
    }
    return 0;
}
