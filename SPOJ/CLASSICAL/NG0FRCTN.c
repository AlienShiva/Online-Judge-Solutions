#include<stdio.h>

main()
{
    int i,n,num,den,child[64],a,b,t;
    scanf("%d",&n);
    while(n)
    {
        i=-1;
        while(n!=1)
        {
            i++;
            if(n%2==0)
                child[i]=0;
            else
                child[i]=1;
            n=n>>1;
        }
        num=den=1;
        for(;i>=0;i--)
        {
            if(child[i])
                num=num+den;
            else
                den=num+den;
        }
        a=num;
        b=den;
        while(1)
        {
            if(a)
            {
                t=a;
                a=b%a;
                b=t;
            }
            else
                break;
        }
        num=num/b;
        den=den/b;

        printf("%d/%d\n",num,den);
        scanf("%d",&n);
    }
    return 0;
}
