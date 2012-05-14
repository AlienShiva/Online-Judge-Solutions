#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int i,j,k,n,x,cnt,e,lo1,lo2;
    char car[11][56];
    int fact[]= {1,1,2,6,24,120,720};

    scanf("%d %d",&x,&n);

    for(i=0; i<n; i++)
        scanf(" %s",car[i]);

    cnt=0;
    for(i=0; i<n; i++)
    {
        lo1=0;
        lo2=52;
        while(lo1!=36)
        {
            e=0;

            for(j=lo1; j<lo1+4; j++)
                if(car[i][j]=='0')
                    e++;

            if(car[i][lo2]=='0')
                e++;

            if(car[i][lo2+1]=='0')
                e++;

            if(e>=x)
                cnt+= (fact[e]/(fact[x]*fact[e-x]));

            lo1+=4;
            lo2-=2;
        }
    }

    printf("%d\n",cnt);

    return 0;
}
