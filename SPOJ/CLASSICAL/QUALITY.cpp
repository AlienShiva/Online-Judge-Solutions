#include<iostream>
using namespace std;

main()
{
    int t1,t2,t3,t;
    int n1,n2,n3,count,p,i;
    i=1;
    while(EOF!=scanf("%d %d %d %d %d %d",&t1,&t2,&t3,&n1,&n2,&n3))
    {
        t=p=count=0;
        if(t1)
        {
            t+=t1;
            count++;
            p+=n1-1;
        }
        if(t2)
        {
            t+=t2;
            count++;
            p+=n2-1;
        }
        if(t3)
        {
            t+=t3;
            count++;
            p+=n3-1;
        }
        printf("team %d: %d, %d\n",i,count,t+p*20*60);
        i++;
    }
    return 0;
}
