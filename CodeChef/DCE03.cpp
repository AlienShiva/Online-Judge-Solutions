#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 1005

int ct[MAX][MAX];

main()
{
    int t,n;
    int i,j;
    memset(ct,0,sizeof(ct));
    for(i=0;i<MAX;i++)
        ct[i][0]=1;
    for(i=1;i<MAX;i++)
    {
        for(j=1;j<=i;j++)
        {
            ct[i][j]=(ct[i-1][j]+ct[i][j-1])%10000;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ct[n-1][n-1]<<endl;
    }
    return 0;
}
