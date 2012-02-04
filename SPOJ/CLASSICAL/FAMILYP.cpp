#include<iostream>
#include<cmath>

using namespace std;

main()
{
    int n,r;
    char ch;
    while(EOF!=scanf("%d",&n))
    {
        r=(-1+ceil(sqrt(1+8*n)))/2;
        if(r>26)
            r=r%26;
        printf("TERM %d is %c",n,r+64);
    }
    return 0;
}
