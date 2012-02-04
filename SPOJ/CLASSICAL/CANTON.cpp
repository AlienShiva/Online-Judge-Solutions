#include<iostream>
#include<cmath>

using namespace std;

main()
{
    int t,n,row,start,sign,diff;
    scanf("%d",&t);
    while(t)
    {
        scanf("%d",&n);
        row=ceil((-1+sqrt(1+8*n))/2.0);
        start=row*(row-1)/2+1;
        diff=n-start;

        if(row%2==0)
            printf("TERM %d IS %d/%d\n",n,1+diff,row-diff);
        else
            printf("TERM %d IS %d/%d\n",n,row-diff,1+diff);
        t--;
    }
    return 0;
}
