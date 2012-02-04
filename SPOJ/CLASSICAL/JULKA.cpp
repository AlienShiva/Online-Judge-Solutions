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

void div2(bigint &a)
{
    int i,j,f,s;
    f=0;
    for(j=i=a.len-1;i>=0;i--,j--)
    {
        s=a.num[i];
        if(f%2==0)
            a.num[j]=s/2;
        else
            a.num[j]=s/2+5;
        f=s;
    }
    if(a.num[a.len-1]==0)
        a.len--;
    if(a.len==0)
        a.len=1;
}

main()
{
    int i,j,t;
    char s[600];
    bigint a,b,c;
    t=10;
    while(t--)
    {
        scanf(" %s",s);
        store(a,s);
        scanf(" %s",s);
        store(b,s);
        add(a,b,c);
        div2(c);
        print(c);
        cout<<endl;
        subtract(c,b,a);
        print(a);
        cout<<endl;
    }
    return 0;
}
