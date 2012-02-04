#include<iostream>
using namespace std;

main()
{
    int n,m,i,j,k,l,qkp,count,t;
    t=1;
    scanf("%d %d",&n,&m);
    while(!(n==0 && m==0))
    {
        char grid[n][m];
        bool safe[n][m];
        count=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                safe[i][j]=true;
                grid[i][j]='0';
            }
        scanf("%d",&qkp);
        for(k=0;k<qkp;k++)
        {
            scanf("%d %d",&i,&j);
            i--;j--;
            grid[i][j]='q';
            safe[i][j]=false;
        }
        scanf("%d",&qkp);
        for(k=0;k<qkp;k++)
        {
            scanf("%d %d",&i,&j);
            i--;j--;
            grid[i][j]='k';
            safe[i][j]=false;
        }
        scanf("%d",&qkp);
        for(k=0;k<qkp;k++)
        {
            scanf("%d %d",&i,&j);
            i--;j--;
            grid[i][j]='p';
            safe[i][j]=false;
        }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='k')
                {
                    if(i-2>=0 && j+1<=m-1)
                        safe[i-2][j+1]=false;
                    if(i-2>=0 && j-1>=0)
                        safe[i-2][j-1]=false;
                    if(i-1>=0 && j-2>=0)
                        safe[i-1][j-2]=false;
                    if(i+1<=n-1 && j-2>=0)
                        safe[i+1][j-2]=false;
                    if(i+2<=n-1 && j-1>=0)
                        safe[i+2][j-1]=false;
                    if(i+2<=n-1 && j+1<=m-1)
                        safe[i+2][j+1]=false;
                    if(i-1>=0 && j+2<=m-1)
                        safe[i-1][j+2]=false;
                    if(i+1<=n-1 && j+2<=m-1)
                        safe[i+1][j+2]=false;
                }
                else if(grid[i][j]=='q')
                {
                    for(k=i-1;k>=0 && grid[k][j]=='0';k--)
                        safe[k][j]=false;
                    for(k=i+1;k<n && grid[k][j]=='0';k++)
                        safe[k][j]=false;
                    for(k=j+1;k<m && grid[i][k]=='0';k++)
                        safe[i][k]=false;
                    for(k=j-1;k>=0 && grid[i][k]=='0';k--)
                        safe[i][k]=false;

                    for(k=i-1,l=j-1;k>=0 && l>=0 && grid[k][l]=='0';k--,l--)
                        safe[k][l]=false;
                    for(k=i+1,l=j-1;k<n && l>=0 && grid[k][l]=='0';k++,l--)
                        safe[k][l]=false;
                    for(k=i+1,l=j+1;k<n && l<m && grid[k][l]=='0';k++,l++)
                        safe[k][l]=false;
                    for(k=i-1,l=j+1;k>=0 && l<m && grid[k][l]=='0';k--,l++)
                        safe[k][l]=false;
                }
            }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(safe[i][j])
                    count++;

        printf("Board %d has %d safe squares.\n",t,count);

        t++;
        scanf("%d %d",&n,&m);
    }
    return 0;
}
