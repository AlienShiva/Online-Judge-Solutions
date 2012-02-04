#include <stdio.h>
#include <string.h>
#include <math.h>

int inc;

int fn(int n)
{
    if(n==1)
        return 1;

    int inc;

    return (fn(n>>1)<<1) + ((n&1)?1:-1);
}

main()
{
    int n,i;
    char str[5];

    scanf(" %s",str);
    while(str[0]-48 || str[1]-48 || str[3]-48)
    {
        n=(str[0]-48)*10 + (str[1]-48);

        for(i='0'; i<str[3]; i++)
            n*=10;

        printf("%d\n",fn(n));

        scanf(" %s",str);
    }
    return 0;
}
