#include<iostream>
using namespace std;

main()
{
        int n,k,s,i,j,a[1005],temp,sum,reqd;
        scanf("%d %d %d",&n,&k,&s);
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
                for(j=i+1;j<n;j++)
                        if(a[i]<a[j])
                        {
                                temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
        sum=0;
        reqd=k*s;
        for(i=0;i<n && sum<reqd;i++)
                sum=sum+a[i];
        printf("%d\n",i);
        return 0;
}
