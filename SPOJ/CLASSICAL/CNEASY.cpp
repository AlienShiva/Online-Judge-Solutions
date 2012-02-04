#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

main()
{
    int t,n,i,time;
    scanf("%d",&t);
    while(t)
    {
        cin>>n;
        double l[n+1],least,temp,sec;
        char s[200];
        for(i=0;i<n;i++)
            scanf("%s %lf",s,&l[i]);
        
        sort(l,l+n);

        least=l[n-1]-l[0];
        for(i=1;i<n;i++)
        {
            temp=360-l[i]+l[i-1];
            least=min(least,temp);
        }
        printf("%d\n",(int)ceil(least*12.00));
        t--;
    }
    return 0;
}
