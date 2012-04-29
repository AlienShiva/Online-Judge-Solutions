#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int primes[501];
int pfactor[501];

void precalc()
{
    int i,j;

    for(i=0; i<501; i++)
        primes[i]=i;

    for(i=2; i*i<501; i++)
        if(primes[i]==i)
        {
            for(j=i*i; j<501; j+=i)
                primes[j]=min(primes[j],i);
        }
}

void factorize(int n)
{
    for(; n>1; n=n/primes[n])
        pfactor[primes[n]]++;
}

main()
{
    precalc();
    int t,i,j,len,cnt[53];
    unsigned long long num;
    char s[510];
    int fact[11][4]= {{0,0,0,0},{0,0,0,0},{1,0,0,0},
        {1,1,0,0},{3,1,0,0},{3,1,1,0},{4,2,1,0},
        {4,2,1,1},{7,2,1,1},{7,4,1,1},{8,4,2,1}
    };
    int two,three,five,seven;

    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        memset(pfactor,0,sizeof(pfactor));

        scanf(" %s",s);

        len=strlen(s);

        for(i=0; i<len; i++)
        {
            if(s[i]<91)
                cnt[s[i]-65]++;
            else
                cnt[s[i]-71]++;
        }

        two=three=five=seven=0;
        for(i=0; i<52; i++)
            if(cnt[i]>1)
            {
                two+=fact[cnt[i]][0];
                three+=fact[cnt[i]][1];
                five+=fact[cnt[i]][2];
                seven+=fact[cnt[i]][3];
            }

        for(i=2; i<=len; i++)
            factorize(i);

        pfactor[2]-=two;
        pfactor[3]-=three;
        pfactor[5]-=five;
        pfactor[7]-=seven;

        num=1;
        for(i=2; i<=len; i++)
        {
            for(j=0; j<pfactor[i]; j++)
                num=(num*i)%1000000007;
        }

        printf("%lld\n",num);
    }
    return 0;
}
