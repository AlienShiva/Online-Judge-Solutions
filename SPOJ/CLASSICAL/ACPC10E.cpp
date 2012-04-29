#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

main()
{
    long long i,g,t,a,d,x,y,k,powers[63];

    powers[0]=1;
    for(i=1; i<60; i++)
        powers[i]=powers[i-1]*2;

    cin>>g>>t>>a>>d;
    while(!(g==-1 && t==-1 && a==-1 && d==-1))
    {
        x=(g*t*(t-1))/2;
        k=g*a+d;

        for(i=0; i<60; i++)
            if(k<=powers[i])
                break;

        y=powers[i]-k;
        x+=powers[i]-1;

        cout<<g<<"*"<<a<<"/"<<t<<"+"<<d<<"="<<x<<"+"<<y<<endl;

        cin>>g>>t>>a>>d;
    }
    return 0;
}
