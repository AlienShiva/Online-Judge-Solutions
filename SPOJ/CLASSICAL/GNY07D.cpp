#include<iostream>
using namespace std;

main()
{
    int r,c,t,i,j,k,l,test,in;
    int dir,r1,c1,r2,c2;
    int num,count;
    char ch,s[1500];
    scanf("%d",&t);
    for(test=1;test<=t;test++)
    {
        scanf("%d %d %s",&r,&c,s);
        int d[r][c];
        k=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++,k++)
                d[i][j]=s[k]-48;
        int de[r*c];
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
                de[k]=d[i][j];
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
                de[k]=d[i][j];
                r1--;
                k++;
                count++;
            }
            dir=dir*-1;
        }
        l=k;
        printf("%d ",test);
        count=0;
        num=16;
        r1=0;

        for(i=0;i<5;i++)
        {
            for(in=r1;in<l;in=in+5)
                de[in]*=num;
            num/=2;
            r1++;
        }

        for(i=0;i<l;i++)
        {
            num=num+de[i];
            count++;
            if(count==5)
            {
                if(num==0)
                    printf(" ");
                else
                    printf("%c",num+64);
                count=num=0;
            }
        }
        printf("\n");
    }
    return 0;
}
