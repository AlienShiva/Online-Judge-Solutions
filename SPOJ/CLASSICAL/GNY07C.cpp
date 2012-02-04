#include<iostream>
using namespace std;

main()
{
    int r,c,t,i,j,k,test,in;
    int dir,r1,c1,r2,c2;
    int num,count;
    char ch,s[1500];
    scanf("%d",&t);
    for(test=1;test<=t;test++)
    {
        s[0]='\0';
        scanf("%d %d %[^0123456789\n]s",&r,&c,s);
        int en[r*c];
        for(i=0;i<r*c;i++)
            en[i]=0;

        for(i=0;s[i];i++)
        {
            num=s[i]-64;
            if(s[i]==' ')
                num=0;
            in=(i+1)*5-1;
            while(num!=0)
            {
                en[in]=num%2;
                num=num/2;
                in--;
            }
        }
        int e[r][c];
        r2=r-1;
        c2=c;
        dir=1;
        count=0;
        i=0;j=-1;k=0;
        while(count!=r*c)
        {
            c1=c2--;
            while(c1)
            {
                j=j+dir;
                e[i][j]=en[k];
                k++;
                c1--;
                count++;
            }
            if(count==r*c)
                break;

            r1=r2--;
            while(r1)
            {
                i=i+dir;
                e[i][j]=en[k];
                r1--;
                k++;
                count++;
            }
            dir=dir*-1;
        }
        printf("%d ",test);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                printf("%d",e[i][j]);
        printf("\n");
    }
    return 0;
}
