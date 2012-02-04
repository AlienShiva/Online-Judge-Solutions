#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int t,s,c,i,j,k,zi,eqv;
    int num[110][110];
    bool all_zero;

    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&s,&c);

        for (i=0;i<s;i++)
            scanf("%d",&num[0][i]);

        all_zero=false;
        i=-1;
        while (!all_zero)
        {
            i++;
            k=0;
            for (j=0;j<s-i-1;j++)
            {
                num[i+1][j]=num[i][j+1]-num[i][j];
                if(num[i+1][j]==0)
                    k++;
            }
            if (k==j)
            {
                zi=i;
                eqv=num[i][0];
                all_zero=true;
            }
        }

        for(j=s-zi,k=0;k<c;k++,j++)
            num[zi][j]=eqv;

        i=zi-1;
        k=s-zi+1;
        while(i>=0)
        {
            for(j=k;j<k+c;j++)
                num[i][j]=num[i+1][j-1]+num[i][j-1];
            i--;
            k++;
        }

        printf("%d",num[0][s]);
        for (i=s+1;i<s+c;i++)
            printf(" %d",num[0][i]);
        printf("\n");
    }
    return 0;
}
