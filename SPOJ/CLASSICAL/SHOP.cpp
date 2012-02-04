#include<iostream>
#include<queue>
using namespace std;

bool vis[30][30];
int sec[30][30];
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
int m,n;

struct node
{
    int x,y,Time;
};

node s,d,temp;

bool operator <(const node &a, const node &b)
{
    return (a.Time>b.Time);
}

int dij()
{
    int i;
    node top;
    priority_queue <node> pq;

    pq.push(s);

    while(!pq.empty())
    {
        top=pq.top();
        pq.pop();
        if(top.x==d.x && top.y==d.y)
            return top.Time;

        if(!vis[top.x][top.y])
        {
            vis[top.x][top.y]=true;

            for(i=0;i<4;i++)
            {
                temp.x=top.x+x[i];
                temp.y=top.y+y[i];
                if(temp.x>=0 && temp.x<n)
                    if(temp.y>=0 && temp.y<m)
                    {
                        temp.Time=top.Time+sec[temp.x][temp.y];
                        pq.push(temp);
                    }
            }
        }
    }
    return -1;
}

main()
{
    int i,j;
    char ch;

    scanf("%d %d",&m,&n);

    while(m!=0 && n!=0)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf(" %c",&ch);
                switch(ch)
                {
                    case 'S': s.x=i; s.y=j; s.Time=0; sec[i][j]=0; vis[i][j]=false; break;
                    case 'D': d.x=i; d.y=j; d.Time=0; sec[i][j]=0; vis[i][j]=false; break;
                    case 'X': vis[i][j]=true; sec[i][j]=10; break;
                    default : vis[i][j]=false; sec[i][j]=ch-48; break;
                }
            }

        printf("%d\n",dij());

        scanf("%d %d",&m,&n);
    }
    return 0;
}
