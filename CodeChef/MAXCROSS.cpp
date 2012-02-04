#include<iostream>
using namespace std;

int B[1005][1005];

main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k,l,n,max,x1,x2,t;
    char ch;
    bool grid[1005][1005];

    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf(" %c",&ch);
            B[i][j]=0;
            if(ch=='X')
                grid[i][j]=true;
            else
                grid[i][j]=false;
        }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                //Horizontal
                max=0;
                for(x1=j; x1<n && grid[i][x1]; x1++);
                for(x2=j; x2>=0 && grid[i][x2]; x2--);
                max=x1-x2-1;

                //vertical
                for(x1=i; x1<n && grid[x1][j]; x1++);
                for(x2=i; x2>=0 && grid[x2][j]; x2--);
                t=x1-x2-1;
                if(max<t)
                    max=t;

                //Diagonal 1
                for(k=i,l=j,x1=0; k<n && l<n && grid[k][l]; k++,l++,x1++);
                for(k=i,l=j,x2=0; k>=0 && l>=0 && grid[k][l]; k--,l--,x2++);
                t=x1+x2-1;
                if(max<t)
                    max=t;

                //Diagonal 2
                for(k=i,l=j,x1=0; k<n && l>=0 && grid[k][l]; k++,l--,x1++);
                for(k=i,l=j,x2=0; k>=0 && l<n && grid[k][l]; k--,l++,x2++);
                t=x1+x2-1;
                if(max<t)
                    max=t;
                printf("%d",max);
            }
            else
                printf("0");

            if(j<n-1)
                printf(" ");
            else
                printf("\n");
        }

    return 0;
}
