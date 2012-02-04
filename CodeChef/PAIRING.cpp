#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int pairs[10010][2];
bool isused[10010];
int ans[10000];

main()
{
    int i,t,n,m,p1,p2,k;

    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        memset(isused,false,sizeof(isused));
        for (i=0;i<m;i++)
            cin>>pairs[i][0]>>pairs[i][1];
        k=0;
        for (i=m-1;i>=0;i--)
        {
            p1=pairs[i][0];
            p2=pairs[i][1];
            if (!isused[p1] && !isused[p2])
            {
                isused[p1]=isused[p2]=true;
                ans[k]=i;
                k++;
            }
        }
        sort(ans,ans+k);
        for (i=0;i<k-1;i++)
            cout<<ans[i]<<' ';
        cout<<ans[k-1]<<endl;
    }
    return 0;
}