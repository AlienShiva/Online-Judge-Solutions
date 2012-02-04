#include<iostream>
using namespace std;

main()
{
    int t,ng,nm,i,j,max,g,m;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&ng,&nm);
        g=m=max=-1;
        for(i=0;i<ng;i++)
        {
            scanf("%d",&max);
            if(max>g)
                g=max;
        }
        for(i=0;i<nm;i++)
        {
            scanf("%d",&max);
            if(max>m)
                m=max;
        }
        if(g>=m)
            printf("Godzilla\n");
        else
            printf("MechaGodzilla\n");
    }
    return 0;
}
