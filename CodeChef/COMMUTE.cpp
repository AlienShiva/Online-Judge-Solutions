#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

main()
{
    int t,cur,n,ts,trt,freq,i;

    cin>>t;
    while(t--)
    {
        cur=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>ts>>trt>>freq;
            if(cur>ts)
            {
                cur=(ceil(double(cur-ts)/freq))*freq+trt+ts;
            }
            else
            {
                cur=ts+trt;
            }
        }
        cout<<cur<<endl;
    }
    return 0;
}