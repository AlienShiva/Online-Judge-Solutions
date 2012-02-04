#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
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
    for (j=0,i=a.len-1; i>=0; i--,j++)
        a.num[j]=s[i]-'0';
}

void print(bigint a)
{
    int i;
    for (i=a.len-1; i>=0; i--)
        printf("%d",a.num[i]);
}

void add(bigint a, bigint b, bigint &c)
{
    int i;

    memset(c.num,0,1024*sizeof(int));
    for (i=0; i<a.len || i<b.len ; i++)
    {
        c.num[i]+=a.num[i]+b.num[i];
        c.num[i+1]=c.num[i]/10;
        c.num[i]%=10;
    }

    if (c.num[i])    c.len=i+1;
    else c.len=i;
}

void subtract(bigint a, bigint b, bigint &c)
{
    int i,j;
    memset(c.num,0,1024*sizeof(int));
    for (i=0,j=0;i<a.len;i++)
    {
        c.num[i]=a.num[i]-b.num[i]-j;
        if (c.num[i]<0)
        {
            j=1;
            c.num[i]+=10;
        }
        else
            j=0;
    }
    c.len=a.len;
    for (i=c.len-1;c.num[i]==0 && i>0;i--);
    c.len=i+1;
}

main()
{
    int i,j;
    char str[110];
    bigint a,b,c;

    while (EOF!=scanf(" %s",str))
    {
        if (strcmp(str,"1")==0)
            printf("1\n");
        else
        {
            store(a,str);
            store(b,"2");
            add(a,a,c);
            subtract(c,b,a);
            print(a);
            printf("\n");
        }
    }
    return 0;
}
