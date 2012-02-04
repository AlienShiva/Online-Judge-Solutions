#include<iostream>
using namespace std;

main()
{
        int i,n,d;
        float c,sum;
        scanf("%f",&c);
        while(c!=0.00)
        {
                sum=0;
                for(i=2;sum<c;i++)
                        sum+=1/float(i);
                printf("%d card(s)\n",i-2);
                scanf("%f",&c);
        }
        return 0;
}
