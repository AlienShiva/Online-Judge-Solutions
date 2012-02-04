#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 20100

#define getchar getchar_unlocked

void fastRead(char a[])
{
    register char c=0;
    register int i=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        a[i++]=c;
        c=getchar();
    }
    a[i]='\0';
}

struct bigint
{
    int len;
    long long num[MAX/8];
};

void store(bigint &a, char s[])
{
    int i,j,l,k;
    long long num;
    long long exp[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

    memset(a.num,0,sizeof(a.num));

    l=strlen(s);

    j=0;
    i=l-1;
    while (i>=0)
    {
        num=0;
        for (k=0;k<8 && i>=0;k++,i--)
        {
            num=(s[i]-48)*exp[k]+num;
        }
        a.num[j++]=num;
    }
    a.len=j;
}

void print(bigint a)
{
    int i;
    printf("%lld",a.num[a.len-1]);
    for (i=a.len-2; i>=0; i--)
        printf("%08lld",a.num[i]);
}

void multiply(bigint a, bigint b, bigint &c)
{
    int i,j;

    memset(c.num,0,sizeof(c.num));

    c.len=a.len+b.len+1;

    for (i=0;i<a.len;i++)
        for (j=0;j<b.len;j++)
            c.num[i+j]+=a.num[i]*b.num[j];

    for (i=0;i<c.len;i++)
    {
        c.num[i+1]+=c.num[i]/100000000;
        c.num[i]=c.num[i]%100000000;
    }

    for (i=c.len+5; i>0 && c.num[i]==0; i--);
    c.len=i+1;
}

main()
{
    int t;
    char str[10010];
    bigint a,b,c;

    scanf("%d",&t);
    while (t--)
    {
        fastRead(str);
        store(a,str);

        fastRead(str);
        store(b,str);

        multiply(a,b,c);
        print(c);
        printf("\n");
    }
    return 0;
}
