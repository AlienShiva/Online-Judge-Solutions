#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    char seq[201];
    int x,y,i,dir;
    int inc[4][2]={{0,-10},{-10,0},{0,10},{10,0}};

    while(EOF!=scanf(" %s",seq))
    {
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");

        x=310; y=420;
        dir=0;
        for(i=0; seq[i]; i++)
        {
            if(seq[i]=='A')
            {
                x+=inc[dir][0];
                y+=inc[dir][1];

                dir=(dir+1)%4;
            }
            else
            {
                x-=inc[dir][0];
                y-=inc[dir][1];

                dir=dir-1;
                if(dir<0)
                    dir+=4;
            }
            printf("%d %d lineto\n",x,y);
        }
        printf("stroke\n");
        printf("showpage\n");
    }
	return 0;
}
