#include <iostream>
#include <cstdio>
using namespace std;

int totient[1000001];
int small_prime[1000001];

void pre_calc()
{
    int i,j;

    for(i=1; i<1000001; i++)
        small_prime[i] = i;

    for(i=2; i<=1000; i++)
        if(small_prime[i] == i)
            for(j=i<<1; j<1000001; j+=i)
                if(small_prime[j]==j)
                    small_prime[j] = i;

    totient[1]=1;
    for(i=1; i<1000001; i++)
    {
        j = i/small_prime[i];

        if(small_prime[i] == small_prime[j])
            totient[i] = small_prime[i] * totient[j];
        else
            totient[i] = (small_prime[i] - 1) * totient[j];
    }
}

main()
{
    int t,n;

    pre_calc();

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",totient[n]);
    }

    return 0;
}
