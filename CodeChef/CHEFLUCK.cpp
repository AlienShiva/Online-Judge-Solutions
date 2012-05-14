#include <iostream>
#include <cstdio>
using namespace std;

main()
{
    int t, n, temp, rem, cnt, i;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        cnt=-1;
        if(n%7==0)
        {
            cnt=n;
        }
        else
        {
            rem=n%7;
            temp=n-rem;
            if(rem%4==0)
            {
                cnt=temp;
            }
            else
            {
                for(i=0; i<3; i++)
                {
                    temp=temp-7;
                    rem=rem+7;
                    if(temp>=0 && rem%4==0)
                    {
                        cnt=temp;
                        break;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
