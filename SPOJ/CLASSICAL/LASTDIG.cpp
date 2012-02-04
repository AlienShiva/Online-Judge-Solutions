#include<iostream>
using namespace std;

main()
{
    int t,a,l,temp;
    scanf("%d",&t);
    long long b=0;
    while(t)
    {
        scanf("%d %lld",&a,&b);
        l=a%10;
        if(b==0)
            l=1;
        else if(l==5 || l==0)
            ;
        else
        {
            temp=b%4;
            if(temp==0)
            {
                if(l%2==0)
                    l=6;
                else
                    l=1;
            }
            else if(temp==2)
                l=(l*l)%10;
            else if(temp!=1)
                l=(l*l*l)%10;
        }
        printf("%d\n",l%10);
        t--;
    }
    return 0;
}
