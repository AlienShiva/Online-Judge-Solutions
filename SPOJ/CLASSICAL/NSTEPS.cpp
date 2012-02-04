#include<iostream>
using namespace std;

main()
{
    int x,y,n;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d %d",&x,&y);
        if(x==y)
        {
            if(y%2==0)
                printf("%d\n",y<<1);
            else
                printf("%d\n",(y<<1)-1);
        }
        else if(x==y+2)
        {
            if(x%2==0)
                printf("%d\n",x+y);
            else
                printf("%d\n",x+y-1);
        }
        else
            printf("No Number\n");

        n--;
    }
    return 0;
}
