#include<iostream>
#include<cstring>
using namespace std;

struct bigint
{
    int len,num[1024];
};

void store(bigint &a, char s[])
{
    int i,j;
    memset(a.num,0,1024*sizeof(int));
    a.len=strlen(s);
    for(j=0,i=a.len-1; i>=0; i--,j++)
        a.num[j]=s[i]-'0';
}

void print(bigint a)
{
    int i;
    for(i=a.len-1; i>=0; i--)
        printf("%d",a.num[i]);
}

void add(bigint a, bigint b, bigint &c)
{
    int i;

    memset(c.num,0,1024*sizeof(int));
    for(i=0; i<a.len || i<b.len ; i++)
    {
        c.num[i]+=a.num[i]+b.num[i];
        c.num[i+1]=c.num[i]/10;
        c.num[i]%=10;
    }

    if(c.num[i])    c.len=i+1;
    else c.len=i;
}

void subtract(bigint a, bigint b, bigint &c)
{
    int i,j;
    memset(c.num,0,1024*sizeof(int));
    for(i=0,j=0;i<a.len;i++)
    {
        c.num[i]=a.num[i]-b.num[i]-j;
        if(c.num[i]<0)
        {
            j=1;
            c.num[i]+=10;
        }
        else
            j=0;
    }
    c.len=a.len;
    for(i=c.len-1;c.num[i]==0 && i>0;i--);
    c.len=i+1;
}

void multiply(bigint a, bigint b, bigint &c)
{
    int i,j;

    memset(c.num,0,1024*sizeof(int));

    c.len=a.len+b.len+1;

    for(i=0;i<a.len;i++)
        for(j=0;j<b.len;j++)
            c.num[i+j]+=a.num[i]*b.num[j];

    for(i=0;i<c.len;i++)
    {
        c.num[i+1]+=c.num[i]/10;
        c.num[i]=c.num[i]%10;
    }
    for(i=c.len; i>0 && c.num[i]==0; i--);
    c.len=i+1;
}

main()
{
    int i,j,t,mlen,md,md1,md2;
    bigint a,b,c,temp,p;
    char op,s[1200];

    scanf("%d",&t);

    while(t--)
    {
        scanf(" %s",&s);
        for(i=0; s[i]>='0' && s[i]<='9'; i++);
        op=s[i];
        s[i]='\0';
        store(a,s);
        store(b,s+i+1);
        if(op=='+' || op=='-')
        {
            if(op=='+')
                add(a,b,c);
            else if(op='-')
                subtract(a,b,c);
            mlen=(a.len>b.len+1)?a.len:b.len+1;
            mlen=(mlen>c.len)?mlen:c.len;
            md=(c.len>b.len+1)?c.len:b.len+1;
            for(i=0;i<mlen-a.len;i++)
                printf(" ");
            print(a);
            printf("\n");
            for(i=0;i<mlen-b.len-1;i++)
                printf(" ");
            printf("%c",op);
            print(b);
            printf("\n");
            for(i=0;i<mlen-md;i++)
                printf(" ");
            for(i=0;i<md;i++)
                printf("-");
            printf("\n");
            for(i=0;i<mlen-c.len;i++)
                printf(" ");
            print(c);
            printf("\n");
        }
        else
        {
            multiply(a,b,c);
            mlen=(a.len>b.len+1)?a.len:b.len+1;
            mlen=(mlen>c.len)?mlen:c.len;
            temp.len=1;
            temp.num[0]=b.num[0];
            multiply(a,temp,p);
            md1=(p.len>b.len+1)?p.len:b.len+1;

            for(i=0;i<mlen-a.len;i++)
                printf(" ");
            print(a);
            printf("\n");
            for(i=0;i<mlen-b.len-1;i++)
                printf(" ");
            printf("*");
            print(b);
            printf("\n");
            for(i=0;i<mlen-md1;i++)
                printf(" ");
            for(i=0;i<md1;i++)
                printf("-");
            printf("\n");
            for(j=0;j<mlen-p.len;j++)
                    printf(" ");
            print(p);
            printf("\n");
            if(b.len>1)
            {
            for(i=1;i<b.len;i++)
            {
                temp.num[0]=b.num[i];
                multiply(a,temp,p);
                for(j=0;j<mlen-p.len-i;j++)
                    printf(" ");
                print(p);
                printf("\n");
            }

            md2=c.len;
            for(i=0;i<mlen-md2;i++)
                printf(" ");
            for(i=0;i<md2;i++)
                printf("-");
            printf("\n");

            for(i=0;i<mlen-c.len;i++)
                printf(" ");
            print(c);
            printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
