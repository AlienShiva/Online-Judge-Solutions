#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,min_cnt;
int arr[40];

bool pending()
{
    for(int i=0; i<n; i++)
        if(arr[i]!=1)
            return true;

    return false;
}

void change(int l, int r)
{
    for(int i=l; i<=r; i++)
        arr[i]=1;
}

void find_interval(int cnt)
{
    if(!pending())
    {
        if(cnt<min_cnt)
            min_cnt=cnt;

        return;
    }

    int i,j,sum,p[n+1],len,maxlen;

    p[0]=0;
    for(i=0; i<n; i++)
        p[i+1]=p[i]+arr[i];

    maxlen=-1;
    for(i=1; i<n+1; i++)
        for(j=i+1; j<n+1; j++)
        {
            sum=p[j]-p[i-1];
            if(sum>=0)
            {
                len=j-i;
                if(len>maxlen)
                    maxlen=len;
            }
        }

    for(i=1; i<n+1; i++)
        for(j=i+maxlen; j<n+1; j++)
        {
            sum=p[j]-p[i-1];
            if(sum>=0)
            {
                int temp[40];
                memcpy(temp,arr,sizeof(arr));

                change(i-1,j-1);

                find_interval(cnt+1);

                memcpy(arr,temp,sizeof(temp));
            }
        }
}

void solve()
{
    int i,l,r,maxn;

    maxn=-1;
    for(i=0; i<n; i++)
        if(arr[i]>maxn)
            maxn=arr[i];

    for(i=0; i<n; i++)
        arr[i]=(arr[i]==maxn)?1:-1;

    min_cnt=1e9;
    find_interval(0);
}

main()
{
    int t,i;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);

        solve();

        printf("%d\n",min_cnt);
    }

    return 0;
}
