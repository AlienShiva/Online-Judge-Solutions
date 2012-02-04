#include<iostream>
#include<cstring>
using namespace std;

main()
{
    int i,j,k,t,n,count;
    bool found;
    char a[700][100];
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);
        count=n=(n-1)<<1;
        printf("Scenario #%d:\n",k);
        for(i=0;i<n;i++)
            scanf(" %s",a[i]);

        for(i=0;i<n;i++)
        {
            found=false;
            for(j=0;j<n;j++)
                if(i!=j && (strcmp(a[i],a[j])==0))
                    found=true;
            if(i%2==0 && j==n && !found)
                break;
        }
        printf("%s\n",a[i]);
        count-=2;
        while(count)
        {
            for(j=0;j<n;j++)
                if(i+1!=j && strcmp(a[i+1],a[j])==0)
                    break;
            i=j;
            printf("%s\n",a[i]);
            count-=2;
        }
        printf("%s\n\n",a[i+1]);
    }
    return 0;
}
