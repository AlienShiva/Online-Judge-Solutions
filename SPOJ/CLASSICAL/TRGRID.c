#include<string.h>

main()
{
    int t,n,m,i,j,count;
    char ch;
    char LR[3]="LR";
    char UD[3]="UD";
    scanf("%d",&t);
    while(t)
    {
        scanf("%d %d",&n,&m);

        if(n<=m)
            ch=LR[n%2];
        else
            ch=UD[m%2];

        printf("%c\n",ch);
        t--;
    }
    return 0;
}
