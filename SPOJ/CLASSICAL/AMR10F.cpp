#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    int t,n,a,d;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&a,&d);
        printf("%d\n",n*(2*a+(n-1)*d)/2);
    }
	return 0;
}
