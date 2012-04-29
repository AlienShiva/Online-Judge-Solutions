#include <iostream>
#include <cstdio>
using namespace std;

main()
{
    int t, r, c, i, j, p1, p2;
    char ch, g[101][101], str[]="spoon";
    bool spoon;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                scanf(" %c",&ch);
                g[i][j]=tolower(ch);
            }

        spoon=false;

        for(i=0; i<r && !spoon; i++)
            for(j=0; j<c && !spoon; j++)
            {
                p1=c-j;
                p2=r-i;

                if(p1>4 && g[i][j]=='s' && g[i][j+1]=='p' && g[i][j+2]=='o' && g[i][j+3]=='o' && g[i][j+4]=='n')
                    spoon=true;

                if(p2>4 && g[i][j]=='s' && g[i+1][j]=='p' && g[i+2][j]=='o' && g[i+3][j]=='o' && g[i+4][j]=='n')
                    spoon=true;
            }

        if(spoon)
            printf("There is a spoon!\n");
        else
            printf("There is indeed no spoon!\n");
    }

    return 0;
}
