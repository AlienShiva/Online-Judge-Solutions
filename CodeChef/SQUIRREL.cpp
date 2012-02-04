#include <iostream>
#include <algorithm>
using namespace std;

main()
{
    //freopen("in.txt","r",stdin);
    int i,j,t,m,n,k,temp;
    int ti[11000],pi[11000];
    int f[11000],cur,hb,lb,wt;
    bool found=false;
    long long sum;
    scanf("%d",&t);
    while(t)
    {
        scanf("%d %d %d",&m,&n,&k);
        n=min(n,m);
        for(i=0;i<m;i++)
            scanf("%d",&ti[i]);
        for(i=0;i<m;i++)
            scanf("%d",&pi[i]);
        hb=1000000000;
        lb=1;
        while(lb+1!=hb)
        {
                cur=(lb+hb)>>1;
                for(i=0;i<m;i++)
                {
                    if(cur>=ti[i])
                        f[i]=(cur-ti[i])/pi[i]+1;

                    else
                        f[i]=0;
                }
                sort(f,f+m);
                sum=0;
                for(i=0;i<n;i++)
                    sum+=f[m-i-1];

                if(sum>=k)
                {
                    hb=cur;
                }
                else
                {
                    lb=cur;
                }
        }
        printf("%d\n",hb);
        t--;
    }
    return 0;
}
