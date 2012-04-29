#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int i,n,k,arr[100000],hi,lo,diff,cnt;

    scanf("%d %d",&n,&k);
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+n);

    lo=0; hi=1;
    cnt=0;
    while(hi<n)
    {
        diff=arr[hi]-arr[lo];
        if(diff==k)
        {
            cnt++;
            hi++; lo++;
        }
        else if(diff<k)
            hi++;
        else
            lo++;
    }

    printf("%d\n",cnt);

	return 0;
}
