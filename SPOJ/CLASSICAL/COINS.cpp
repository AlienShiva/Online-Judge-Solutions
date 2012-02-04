#include<iostream>
#include<map>
using namespace std;

map <int, long long> dp;

long long find(int n)
{
        if(n==0)
                return 0;

        long long val=dp[n];

        if(val==0)
        {
                val=find(n/2)+find(n/3)+find(n/4);
                dp[n]=(n>val)?n:val;
        }
        return dp[n];
}

main()
{
        int n;
        while(EOF!=scanf("%d",&n))
        {
                dp.clear();
                printf("%lld\n",find(n));
        }
        return 0;
}
