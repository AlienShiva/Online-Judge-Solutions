//How much can a stupid solution score? I wonder...

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, adj1[76][76], adj2[76][76];

main()
{
    int t, i, j;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&adj1[i][j]);

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&adj2[i][j]);

        for(i=1; i<=n; i++)
            printf("%d ",i);
        printf("\n");

        for(i=1; i<=n; i++)
            printf("%d ",i);
        printf("\n");
    }
    return 0;
}
